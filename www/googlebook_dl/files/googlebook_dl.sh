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

#
# returns true if argument is a positive/negative whole integer.
# stolen from bsdinstall
#
isinteger()
{
	local arg="$1"

	# prevent division-by-zero
	[ "${arg}" = "0" ] && return

	# attempt to perform arithmetic divison (an operation which will exit
	# with error unless arg is a valid positive/negative whole integer).
	( : $((0/$arg)) ) > /dev/null 2>&1
}

err()
{
	local exitval

	exitval=$1
	shift
	echo 1>&2 "${0##*/}: $*"
	exit ${exitval}
}

usage()
{
	echo "usage: ${0##*/} [-ahPpvw] totpages bookid"
	echo '	-h display this help'
	echo '	-a all mode (try to get links from all pages, including already downloaded)'
	echo '	-P pageprefix (*PA, PP, PR, PT)'
	echo '	-p http://proxy.tld:port,proxy.tld,ip:port | proxylist.txt'
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
	local page

	page=$1
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
	[ -z "$1" -a -z "$2" ] && err 3 'out(): bad syntax'

	if [ -n "${verbose}" -a -n "$2" ]; then
		echo $2
	elif [ -z "${verbose}" -a ! -z "$1" ]; then
		[ "$1" = '.' ] && lastchar=.
		case ${lastchar} in
		[.ce]) printf "$1" ;;
			*) printf " $1" ;;
		esac
		lastchar=${1#${1%?}}
	fi
}

get_cookie()
{
	local cookie_str _return

	# remove old cookie
	rm "${cookie}" 2>/dev/null

	# get cookie
	wget -T5 -t2 -q -U"${ua}" --keep-session-cookies \
		--save-cookies "${cookie}" -O/dev/null \
		"http://books.google.com/books?id=${bookid}&pg=PA1&jscmd=click3"

	# fail if wget returned non-zero exitcode or cookies.txt is empty
	_return=$?
	cookie_str="$(grep '^.google.com[[:space:]]' "${cookie}" 2>/dev/null | \
		sed -ne 's/^.*\(ID=.*\)$/\1/p')"
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
	local page url urls _return

	[ -z $1 ] && err 3 'get_page(): bad syntax'
	page=$1

	# pull signatures only from missing pages unless in all mode
	[ -f "${bookid}/${pageprefix}${page}.png" -a -z "${all}" ] && return

	# change cookie every 100 pages
	if [ $((${got_pages} % 100)) -eq 0 ]; then
		get_cookie || return 1
	fi
	got_pages=$((${got_pages} + 1))

	url="http://books.google.com/books?id=${bookid}&pg=${pageprefix}${page}&jscmd=click3"
	out "$(progress ${got_pages})" "${pageprefix}${page}: ${url}&w=${pagewidth} TRY"

	# NB! signatures tied to cookie and ip
	urls=$(wget -T5 -t2 -q -U"${ua}" --no-cache \
		--load-cookies "${cookie}" -O- \
		"${url}" | tr '}' '\n' | grep "{\"pid\":\"P.*\",\"src\":" | \
		sed 's/^.*"src":"\(http:\/\/[^"]*\)".*$/\1/;s/\\u0026/\&/g' | sort -u)

	for	url in ${urls}; do
		page=$(echo "${url}" | sed 's/^.*&pg=\([^&]*\)&.*$/\1/')

		# check again if page already downloaded, we usually get a few
		# urls from a single request
		if [ ! -f "${bookid}/${page}.png" ]; then
			got_pages=$((${got_pages} + 1))

			wget -T5 -t3 -q -U"${ua}" --no-cache \
				--load-cookies "${cookie}" \
				-O"${bookid}/${page}.png" "${url}&w=${pagewidth}"

			_return=$?
			if [ ${_return} -ne 0 ]; then
				# sometime google books just returns 404
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
	local page got_pages

	# for out(), progress()
	local lastchar=.

	got_pages=1

	# randomize page requests - google books only shows 200 - 300 urls in one
	# session
	#
	# if start on odd second count from 1 to totpages, on even - from totpages to 1
	# [ $((`date -j "+%s"` % 2)) -eq 0 ] && descending_order=yes
	# XXX not portable
	if [ $(jot -r 1 0 1) -ne 0 ]; then
		echo "fetching pages in ascending order"

		get_cookie || return 1
		page=1
		while [ ${page} -le ${totpages} ]; do
			get_page ${page} || return 1
			page=$((${page} + 1))
		done
	else
		echo "fetching pages in descending order"

		get_cookie || return 1
		page=${totpages}
		while [ ${page} -ge 1 ]; do
			get_page ${page} || return 1
			page=$((${page} - 1))
		done
	fi

	echo
}


#
# MAIN
#

# with wrong UserAgent we will get 401 Unauthorized
# ua='Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) Firefox/3.0'
ua='Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1)'

# default page width
pagewidth=1024

# PA - books pages			${totpages}
# PR - preface, contents 	~30
# PP,PT - front, back title	~10
# default page prefix
pageprefix=PA

parse_options ${1+"$@"}
shift ${OPTC}

isinteger "${pagewidth}" || err 4 "pagewidth must be integer: ${pagewidth}"

[ -z $1 ] && usage
totpages=$1
isinteger "${totpages}" || err 4 "totpages must be integer: ${totpages}"

[ -z $2 ] && usage
bookid=$2

# if bookid dir already exist, continue from previous try
if [ ! -d "${bookid}" ]; then
	mkdir -- "${bookid}" || err 2 "cannot create dir ${bookid}"
fi

cookie=`mktemp -t cookie` || err 2 'mktemp error'

trap "rm ${cookie} 2>/dev/null; exit 1" 1 2 3 10 13 15

if [ -z "${proxylist}" ]; then
	get_pages
else
	for http_proxy in ${proxylist}; do
		echo "using proxy ${http_proxy}"
		get_pages
	done
fi

rm "${cookie}" 2>/dev/null
