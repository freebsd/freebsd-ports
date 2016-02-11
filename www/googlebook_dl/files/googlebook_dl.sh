#!/bin/sh

#
# SUBS
#

parse_options()
{
	local _proxylist

	while getopts ap:P:vw: OPT; do
		# escape meta
		OPTARG=${OPTARG%%[;\\\$]*}

		case ${OPT} in
		a)	all=yes ;;
		p)	_proxylist="${OPTARG}"
			if [ -r "${_proxylist}" ]; then	# file
				proxylist=$(cat "${_proxylist}")
			else	# list
				proxylist=$(echo "${_proxylist}" | sed -e 's/,/ /g')
			fi
			;;
		P)	pageprefix="${OPTARG}" ;;
		v)	verbose=yes ;;
		w)	pagewidth="${OPTARG}" ;;
		*)	usage ;;
		esac
	done

	OPTC=$((${OPTIND} - 1))
}

err()
{
	local exitval=$1

	shift
	echo 1>&2 "${0##*/}: $*"
	exit ${exitval}
}

#
# returns true if argument is a positive/negative whole integer.
# stolen from bsdinstall
#
isinteger()
{
	local arg="${1#-}"

	[ -z ${arg} ] && err 3 'isinteger(): bad syntax'

	[ "${arg}" = "${arg%[!0-9]*}" ]
}

usage()
{
	echo "usage: ${0##*/} [-ahPpvw] [numpages] bookid"
	echo '	-h display this help'
	echo '	-a all mode (try to get links from all pages, including already downloaded)'
	echo '	-P pageprefix when numpages specified (*PA, PP, PR, PT)'
	echo '	-p https://proxy.tld:port,proxy.tld,ip:port | https-proxylist.txt'
	echo '	-v verbose'
	echo '	-w pagewidth (800, *1024, 1280, 1440, 1680, ...)'
	echo
	exit 1
}

#
# shows progress in dots/got_page numbers
# stolen from portsnap
#
progress()
{
	local page=$1

	[ -z ${page} ] && err 3 'progress(): bad syntax'

	if [ $((${page} % 10)) -eq 0 -a "${lastchar}" = '.' ]; then
		echo -n ${page}
	elif [ $((${page} % 2)) -eq 0 ]; then
		echo -n .
	fi
}

#
# out $msg $verbose_msg
#
out()
{
	local msg="$1" verbose_msg="$2"

	[ -z "${msg}" -a -z "${verbose_msg}" ] && err 3 'out(): bad syntax'

	if [ -n "${verbose}" -a -n "${verbose_msg}" ]; then
		echo ${verbose_msg}
	elif [ -z "${verbose}" -a ! -z "${msg}" ]; then
		[ "${msg}" = '.' ] && lastchar=.
		case ${lastchar} in
		[.ce]) printf "${msg}" ;;
			*) printf " ${msg}" ;;
		esac
		lastchar=${msg#${msg%?}}
	fi
}

get_cookie()
{
	local cookie_str _return

	# remove old cookie
	rm "${cookie}" 2>/dev/null

	# get cookie
	wget ${optcommon} -U"${ua}" --keep-session-cookies \
		--save-cookies "${cookie}" -O/dev/null \
		"${baseurl}${bookid}&pg=PA1&jscmd=click3"

	# fail if non-zero exitcode returned or cookie has wrong format
	_return=$?
	cookie_str="$(sed -ne \
		'/^.google.com[[:space:]]/s/^.*\(NID[^=]*=.*\)$/\1/p' "${cookie}")"
	if [ ${_return} -ne 0 -o -z "${cookie_str}" ]; then
		rm "${cookie}" 2>/dev/null
		out 'E\n' "cannot get cookie: ${cookie_str}"
		return 1
	fi

	# show cookie
	out 'c' "cookie: ${cookie_str}"
}

get_page()
{
	local url urls _return page=$1

	[ -z ${page} ] && err 3 'get_page(): bad syntax'

	# pull signatures only from missing pages unless in all mode
	[ -f "${bookid}/${page}.png" -a -z "${all}" ] && return

	# change cookie every 100 pages tried
	if [ $((${got_pages} % 100)) -eq 0 ]; then
		get_cookie || return 1
	fi
	got_pages=$((${got_pages} + 1))

	url="${baseurl}${bookid}&pg=${page}&jscmd=click3"
	out "$(progress ${got_pages})" "${page}: ${url}&w=${pagewidth} TRY"

	# fetch urls
	# NB! signatures tied to cookie and ip
	urls=$(wget ${optcommon} -U"${ua}" --load-cookies "${cookie}" -O- \
		"${url}" | tr '}' '\n' | \
		sed -ne 's/^.*"src":"\(https:\/\/[^"]*\)".*$/\1/; /pg=/s/\\u0026/\&/gp')

	# fetch pages
	for	url in ${urls}; do
		page=${url##*&pg=}; page=${page%%&*}

		# check again if page already downloaded, we usually get a few
		# urls from a single request
		if [ ! -f "${bookid}/${page}.png" ]; then
			got_pages=$((${got_pages} + 1))

			wget ${optcommon} -U"${ua}" --load-cookies "${cookie}" \
				-O"${bookid}/${page}.png" "${url}&w=${pagewidth}"

			_return=$?
			if [ ${_return} -ne 0 ]; then
				# sometime google books returns 404
				rm "${bookid}/${page}.png"
				out 'e' "${page}: ${url}&w=${pagewidth} ERROR"
			else
				out "${page}" "${page}: ${url}&w=${pagewidth} DOWNLOADED"
			fi
		else
			out '' "${page}: ${url}&w=${pagewidth} ALREADY"
		fi
	done
}

get_pages()
{
	local page got_pages=1
	# for out(), progress()
	local lastchar=.

	# randomize page requests - google books only shows 200 - 300 urls
	# in one session. also remove duplicates.
	PAGELIST=$(echo ${PAGELIST} | tr ' ' '\n' | sort -u -R)

	get_cookie || return 1

	for page in ${PAGELIST}; do
		get_page ${page} || return 1
	done
}

#
# returns number of already retrieved pages in retpages
#
get_retpages()
{
	local RETPAGELIST="$(echo "${bookid}"/P*)"

	retpages=$(set -- ${RETPAGELIST}; echo $#)
	# bookid dir is empty
	[ ${retpages} -eq 1 -a "${RETPAGELIST}" != "${RETPAGELIST%\*}" ] && \
		retpages=0
}

get_pagelist()
{
	local _return url="${baseurl}${bookid}&pg=PA1&jscmd=click3"

	# autodetect available pages
	# XXX there can be a few not listed pages
	PAGELIST=$(wget ${optcommon} -U"${ua}" -O- "${url}" | \
		tr '}' '\n' | sed -ne 's/^.*"[Pp]id":"\(P[^"]*\)".*/\1/p' | sort -u)

	# fail if non-zero exitcode returned or PAGELIST is empty
	_return=$?
	if [ ${_return} -ne 0 -o -z "${PAGELIST}" ]; then
		err 2 'cannot autodetect available pages, try to set numpages manually'
	fi

	# XXX hack: add PP1-3, PT1-2 to PAGELIST manually
	PAGELIST="${PAGELIST} PP1 PP2 PP3 PT1 PT2"
}

#
# create PAGELIST, only for pageprefix
#
make_pagelist()
{
	local page=1 numpages=$1

	[ -z ${numpages} ] && err 3 'make_pagelist(): bad syntax'

	PAGELIST=
	while [ ${page} -le ${numpages} ]; do
		PAGELIST="${PAGELIST} ${pageprefix}${page}"
		page=$((${page} + 1))
	done
}


#
# MAIN
#

# with wrong UserAgent google returns 401 Unauthorized
# ua='Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) Firefox/3.0'
ua='Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1)'

baseurl='https://books.google.com/books?id='

# common wget options
optcommon='-T5 -t3 -q'

# default page width
pagewidth=1024

# PA - books pages
# PR - preface, contents 	~20
# PP,PT - front, back title	~4
# default page prefix for numpages
pageprefix=PA

# remove possible environment pollution
unset http_proxy https_proxy

parse_options "$@"
shift ${OPTC}

isinteger "${pagewidth}" || err 4 "pagewidth must be integer: ${pagewidth}"

[ -z $1 ] && usage

# fallback to old enumeration method if numpages provided
if isinteger $1; then
	numpages=$1

	[ -z $2 ] && usage
	bookid=$2

	make_pagelist ${numpages}
else
	bookid=$1
	get_pagelist
	numpages=$(set -- ${PAGELIST}; echo $#)
fi

# if bookid dir already exist, continue from previous try
if [ ! -d "${bookid}" ]; then
	mkdir -- "${bookid}" || err 2 "cannot create dir ${bookid}"
fi

cookie=`mktemp -t cookie` || err 2 'mktemp error'

trap "rm ${cookie} 2>/dev/null; exit 1" 1 2 3 10 13 15

get_retpages
echo "pages total/retrieved: ~${numpages}/${retpages}"

if [ -z "${proxylist}" ]; then
	get_pages
	echo
else
	for https_proxy in ${proxylist}; do
		echo "using proxy ${https_proxy}"
		export https_proxy
		get_pages
		echo
	done
fi

rm "${cookie}" 2>/dev/null
