#!/bin/sh

set -euo pipefail

# args
deps_file="$1"

# initialize Makefile.xx files
echo "MASTER_SITES=	\\" > Makefile.MASTER_SITES
echo "DISTFILES=	\\" > Makefile.DISTFILES

# loop
cat $deps_file | grep -v "^#" | (while read -r line; do
	line=$(echo $line | sed -e 's|;| |g')
	#echo "LINE $line"

	# extract fields
	name=$(echo $line | sed -e 's| .*||')
	url=$(echo $line | sed -e "s|$name ||; s| .*||")
	#echo "... name=$name url=$url"

	# split url
	url_split=$(echo $url | sed -E 's|(.*)/([^/]+)|\1 \2|')
	#echo "... url_split=$url_split"
	url_dir=$(echo $url_split | sed -e 's| .*||')
	url_file=$(echo $url_split | sed -e 's|.* ||')
	#echo "... url_dir=$url_dir url_file=$url_file"

	# write Makefile.xx files
	echo "		$url_dir/:$name \\" >> Makefile.MASTER_SITES
	echo "		$url_file:$name \\" >> Makefile.DISTFILES
done)
