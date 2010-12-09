#!/bin/sh

parse_options()
{
	local OPT OPTARG OPTIND

	while getopts ap:P:vw: OPT; do
		# escape meta
		OPTARG=${OPTARG%%[;\\\$]*}

		case ${OPT} in
		a)	all=yes ;;
		p)	proxylist="${OPTARG}" ;;
		P)	pageprefix="${OPTARG}" ;;
		v)	verbose=yes ;;
		w)	pagewidth="${OPTARG}" ;;
		*)	usage ;;
		esac
	done

	OPTC=$((${OPTIND} - 1))
}

usage()
{
	echo "usage: ${0##*/} [-ahPpw] totpages bookid"
	echo '	-h display this help'
	echo '	-a all mode (try to get sigs from all pages, including already downloaded)'
	echo '	-P pageprefix (*PA, PP, PR, PT)'
	echo '	-p proxylist'
	echo '	-v verbose'
	echo '	-w pagewidth (800, *1024, 1280, 1440, 1680, ...)'
	echo
	exit 1
}

get_pages()
{
	local ua page url _return

	# with wrong ua we will get 401 Unauthorized
	# ua='Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) Firefox/3.0'
	ua='Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1)'

	# get cookie
	wget -T5 -t2 -q -U"${ua}" --keep-session-cookies \
		--save-cookies "${DIR}/cookies.txt" -O/dev/null \
		"http://books.google.com/books?id=${bookid}&pg=PA1&jscmd=click3"

	# bail if wget returned non zero exit code or cookies.txt is empty
	_return=$?
	cookie="$(grep '^.google.com' "${DIR}/cookies.txt" 2>/dev/null | \
		sed 's/^.*\(ID.*\)$/\1/')"
	[ ${_return} -ne 0 -o -z "${cookie}" ] && \
		{ rm "${DIR}/cookies.txt"; return 1; }

	# show cookie
	[ -n "${verbose}" ] && echo "cookie: ${cookie}"

	# if downloaded less that half of total pages, use all mode
	[ $(ls "${bookid}/" | wc -l) -le $((${totpages} / 2)) ] && all=yes

	# pull sigs only from missing pages unless in all mode
	page=1
	while [ ${page} -le ${totpages} ]; do
		[ -f "${bookid}/${pageprefix}${page}" -a -z "${all}" ] || \
			echo "http://books.google.com/books?id=${bookid}&pg=${pageprefix}${page}&jscmd=click3" \
			>> "${DIR}/urls"
		page=$(( ${page} + 1))
	done

	# get all sigs at once
	# NB! sigs tied to cookie and ip
	wget -T5 -t2 -q -U"${ua}" --no-cache --load-cookies "${DIR}/cookies.txt" \
	-O- -i "${DIR}/urls" | tr '}' '\n' | grep "{\"pid\":\"P.*\",\"src\":" | \
	sed 's/^.*"src":"\(http:\/\/[^"]*\)".*$/\1/;s/\\u0026/\&/g' | sort -u | \
	while read -r url; do
		page=$(echo "${url}" | sed 's/^.*&pg=\([^&]*\)&.*$/\1/')

		[ -n "${verbose}" ] && verbose="${page}: ${url}&w=${pagewidth}"

		# skip already downloaded pages
		[ -f "${bookid}/${page}" ] || \
		{
			wget -T5 -t3 -q -U"${ua}" --no-cache \
				--load-cookies "${DIR}/cookies.txt" \
				-O"${bookid}/${page}" "${url}&w=${pagewidth}"

			_return=$?
			if [ ${_return} -ne 0 ]; then
				# sometimes google books returns 404
				rm "${bookid}/${page}"
				[ -n "${verbose}" ] && verbose="${verbose} ERROR"
			else
				if [ -n "${verbose}" ]; then
					verbose="${verbose} DOWNLOADED"
				else
					echo -n "${page} "
				fi
			fi
		}

		[ -n "${verbose}" ] && echo "${verbose}"
	done
	# clean temp files
	rm "${DIR}/cookies.txt" "${DIR}/urls"

	echo
}

#
# MAIN
#

# default page width
pagewidth=1024

# PA - books pages			${totpages}
# PR - preface, contents 	~30
# PP,PT - front, back title	~10
# default page prefix
pageprefix=PA

parse_options ${1+"$@"}
shift ${OPTC}

[ -z $1 ] && usage
totpages=$1

[ -z $2 ] && usage
bookid=$2

# if bookid dir already exists, continue from previous try
[ -d "${bookid}" ] || \
{
	mkdir "${bookid}" || { echo "cannot create dir ${bookid}"; exit 2; }
}

DIR=`mktemp -d googlebook_dl.XXXXXXXXXX` || exit 2
trap "rm -rf ${DIR}; exit 1" 1 2 3 10 13 15

if [ -z "${proxylist}" ]; then
	get_pages
else
	for http_proxy in `cat "${proxylist}"`; do
		echo "using proxy ${http_proxy}"
		get_pages
	done
fi

rmdir "${DIR}"
