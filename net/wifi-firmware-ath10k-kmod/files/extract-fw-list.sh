#!/bin/sh
#
# Copyright (c) 2025 The FreeBSD Foundation
#
# This software was developed by Björn Zeeb
# under sponsorship from the FreeBSD Foundation.
#
# SPDX-License-Identifier: BSD-2-Clause
#
# Generate the firmware flavors and files from the WHENCE file in
# linux-firmware.git based on the "MAC" names.
# It is no longer feasible to generate them from the driver as the
# firmware names are fully dynamic and require at least a register
# read on each card.  The combinations likely go into the hundreds
# or thousands.
# We still check for the firmware file with the highest API version
# available based on each file name and sort out all the others.
# We also have to sort out the DVM drier parts which we are not
# interested in.
#

FWDIR=${1:-/nonexistent}
DRVNAME=${2:-NODRVNAMEGIVEN}

if test ! -d ${FWDIR} -o ! -r ${FWDIR}/WHENCE; then
	printf "Cannot find '%s' or '%s/WHENCE'\n" ${FWDIR} ${FWDIR} >&2
	printf "USAGE: %s /path/to/linux-firmware.git ath1xk\n" $0 >&2
	exit
fi
case "${DRVNAME}" in
NODRVNAMEGIVEN)	
	printf "USAGE: %s /path/to/linux-firmware.git ath1xk\n" $0 >&2
	exit
	;;
esac

sed -e "s@%%XXX%%@"${DRVNAME}" -.*@g" ../wifi-firmware-kmod/files/WHENCE.awk.in > WHENCE.awk
awk -f WHENCE.awk ${FWDIR}/WHENCE > WHENCE
awk -v FWDIR="${FWDIR}" -v DRVNAME="${DRVNAME}" '
function file_exists(fname)
{
	xname = FWDIR "/" DRVNAME "/" fname;

	#printf("DEBUG: checking for file %s\n", xname);

	if ((getline _ < xname) >= 0) {
		return 1;
	}
}

function known_in_2arr(arr, idx1, idx2)
{
	for (both in arr) {
		split(both, sep, SUBSEP);
		if (sep[1] == idx1 && sep[2] == idx2) {
			return 1;
		}
	}
	return 0;
}

function get_flavor(name)
{

	name = tolower(name);

	# remove the file name.
	gsub("/[^/]*$", "", name);

	# Reduce to two levels
	n = split(name, a, "/")
	if (n > 1) {
		name = a[1] "/" a[2];
	}

	# replace special characters
	gsub("/", "_", name);
	gsub("\\.", "", name);

	#printf("FLAVNAME >>%s<<\n", name);

	return name;
}

function is_flavor_known(name, n, flavarr)
{

	for (f = 1; f <= n ; f++) {
		if (flavarr[f] == name)
			return 1;
	}

	return 0;
}

BEGIN {
	if (!FWDIR) {
		printf "USAGE: -v FWDIR=/path/to/linux-firmware.git\n"
		exit
	}

	flavors_n = 0;
}
{
	if (! /^File:/) {
		next;
	}

	gsub("^File: " DRVNAME "/", "");

	name=$0
	if (!file_exists(name)) {
		print "DEBUG :: file does not exist :: " $0;
		next;
	}

	flav = get_flavor($name);

	if (!is_flavor_known(flav, flavors_n, flavors)) {
		flavors[++flavors_n] = flav;
	}

	if (name ~ /\.txt$/) {
		fwl[flav]++;
		fwlic[flav,fwl[flav]] = name;
	} else {
		fwn[flav]++;
		fwname[flav,fwn[flav]] = name;
	}
}
END {
	# Sort flavors
	for (i = 1; i < length(flavors); i++) {
		for (j = i + 1; j <= length(flavors); j++) {
			if (flavors[i] > flavors[j]) {
				t=flavors[i]
				flavors[i]=flavors[j]
				flavors[j]=t
			}
		}
	}

	printf("FWSUBS=");
	for (f = 1; f <= length(flavors); f++) {
		if (fwn[flavors[f]] > 0) {
			printf(" \\\n\t%s", flavors[f]);
		}
	}
	printf("\n\n");

	# Deal with all the firmware flavors:
	for (f = 1; f <= length(flavors); f++) {
		flav=flavors[f];

		#
		# Firmware files.
		#
		if (fwn[flav] > 0) {
			if (f > 1) {
				printf("\n");
			}
			printf("DISTFILES_%s+=", flav);
		}
		# Sort
		for (i = 1; i < fwn[flav]; i++) {
			for (j = i + 1; j <= fwn[flav]; j++) {
				if (fwname[flav,i] > fwname[flav,j]) {
					t=fwname[flav,i]
					fwname[flav,i]=fwname[flav,j]
					fwname[flav,j]=t
				}
			}
		}
		# Print
		for (i = 1; i <= fwn[flav]; i++) {
			printf(" \\\n\t\${FWSUBDIR}/%s\${DISTURL_SUFFIX}", fwname[flav,i]);
		}

		#
		# License files.
		#
		if (fwl[flav] > 0) {
			if (fwn[flav] > 0) {
				printf("\n");
			}
			printf("DISTFILES_%s_lic+=", flav);
		}
		# Sort
		for (i = 1; i < fwl[flav]; i++) {
			for (j = i + 1; j <= fwl[flav]; j++) {
				if (fwlic[flav,i] > fwlic[flav,j]) {
					t=fwlic[flav,i]
					fwlic[flav,i]=fwlic[flav,j]
					fwlic[flav,j]=t
				}
			}
		}
		# Print
		for (i = 1; i <= fwl[flav]; i++) {
			printf(" \\\n\t\${FWSUBDIR}/%s\${DISTURL_SUFFIX}", fwlic[flav,i]);
		}
	}
	printf("\n");

	printf("\n");
	printf("DISTFILES_\${FWDRV}=");
	for (f = 1; f <= length(flavors); f++) {
		if (fwn[flavors[f]] > 0) {
			printf(" \\\n\t\${DISTFILES_%s}", flavors[f]);
		}
	}
	printf("\n");
	printf("DISTFILES_\${FWDRV}_lic=");
	for (f = 1; f <= length(flavors); f++) {
		if (fwl[flavors[f]] > 0) {
			printf(" \\\n\t\${DISTFILES_%s_lic}", flavors[f]);
		}
	}
	printf("\n");
}' WHENCE

rm -f WHENCE.awk WHENCE

# end
