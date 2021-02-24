#!/usr/bin/awk -f
# $FreeBSD$

BEGIN {
	group = "yarn";
	url = "https://registry.yarnpkg.com/";
	non_first_record = 0

	printf "DISTFILES="
}
! /^  resolved/ {
	next
}
non_first_record {
	printf " \\\n"
}
{
	sub("^.* \"", "", $0)
	sub("#.*$", "", $0)
	distfile = $0;
	sub(url, "", distfile);
	# It is necessary to put distfiles into subdirectories within
	# DISTDIR/DIST_SUBDIR, because some of the distfiles share the same
	# names.
	printf "\t\t%s:%s", distfile, group;

	non_first_record = 1
}
END {
	printf "\n"
}
