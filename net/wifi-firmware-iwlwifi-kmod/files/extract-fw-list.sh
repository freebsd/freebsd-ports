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

if test ! -d ${FWDIR} -o ! -r ${FWDIR}/WHENCE; then
	printf "Cannot find '%s' or '%s/WHENCE'\n" ${FWDIR} ${FWDIR} >&2
	printf "USAGE: %s /path/to/linux-firmware.git\n" $0 >&2
	exit
fi

sed -e "s@%%XXX%%@iwlwifi -.*@g" ../wifi-firmware-kmod/files/WHENCE.awk.in > WHENCE.awk
awk -f WHENCE.awk ${FWDIR}/WHENCE > WHENCE
awk -v FWDIR=${FWDIR} '
function file_exists(fname)
{
	xname=FWDIR "/intel/iwlwifi/" fname;

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

function is_dvm(name)
{
	if (name ~ /^iwlwifi-(3945|4965|5000|5150|1000|6000|6050|6000g2a|6000g2b|135|100|105|2030|2000)-/) {
		return 1;
	}
	return 0;
}

function get_flavor(name)
{
	# All the WiFi7+ stuff we will have a really hard time to tear apart (MAC, RF).
	if (name ~ /^dr-/ && name ~ /-(fm|wh|pe)-/) {
		return "dr";
	}
	if (name ~ /^sc-/ && name ~ /-(fm|wh|pe)-/) {
		return "sc";
	}
	if (name ~ /^(gl|bz)-/ && name ~ /-(fm|wh|pe)-/) {
		return "bz";
	}
	# mvm/(gl|bz)? (WiFi-7?)
	if (name ~ /^(gl|bz)-/ && name ~ /-(gf|jf|hr)-/) {
		return "bz";
	}
	if (name ~ /^(ma|so|ty)-/) {
		return "ax210";
	}
	if (name ~ /^(QuZ|Qu|cc)-/) {
		return "22000";
	}
	if (name ~ /^(9000|9260)/) {
		return "9000";
	}
	if (name ~ /^(8000C|8265)/) {
		return "8000";
	}
	if (name ~ /^(3160|3168|7260|7265|7265D)/) {
		return "7000";
	}

	return "";
}

BEGIN {
	if (!FWDIR) {
		printf "USAGE: -v FWDIR=/path/to/linux-firmware.git\n"
		exit
	}

	flavors[1] = "7000";
	flavors[2] = "8000";
	flavors[3] = "9000";
	flavors[4] = "22000";
	flavors[5] = "ax210";
	flavors[6] = "bz";	# mld starts here
	flavors[7] = "sc";
	flavors[8] = "dr";
}
{
	if (! /^File:/) {
		next;
	}

	gsub("^File: intel/iwlwifi/", "");

	if (!/\.ucode$/ && !/\.pnvm$/) {
		print "ERROR :: " $0
		exit
	}

	name=$0
	if (is_dvm(name)) {
		#print "DEBUG :: skipping DVM firmware file :: " $0;
		next;
	}
	if (!file_exists(name)) {
		print "DEBUG :: file does not exist :: " $0;
		next;
	}

	ispnvm=0
	if (/\.pnvm$/) {
		ispnvm=1
	}

	gsub("^iwlwifi-", "", name);
	gsub("\.ucode$", "", name);
	gsub("\.pnvm$", "", name);

	flav=get_flavor(name);
	ver=name;
	gsub("-[[:digit:]]*$", "", name);
	gsub("^.*-", "", ver);

	# Assoc.Arrays are great but we lose the order which we want for the FLAVORs.
	x1=known_in_2arr(fwver, flav, name);
	x2=known_in_2arr(fwpnvm, flav, name);
	if (x1 || x2) {
		#printf("DEBUG: %s SKIPPING %s/%s, already known in %d,%d\n", $0, flav, name, x1, x2);
	} else {
		fwn[flav]++;
		fwname[flav,fwn[flav]] = name;
		#printf("DEBUG: %s ADDING %s/%s, already known in %d,%d\n", $0, flav, name, x1, x2);
	}
	if (ispnvm) {
		fwpnvm[flav,name] = 1;
	} else {
		if ((fwver[flav,name] + 0) < (ver + 0)) {
			fwver[flav,name] = ver;
		} else {
			printf("DEBUG: skipping %s: %s < %s\n", $0, fwver[flav,name], ver);
		}
	}
}
END {
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
			if (fwpnvm[flav,fwname[flav,i]]) {
				printf(" \\\n\t\${FWSUBDIR}/iwlwifi-%s.pnvm\${DISTURL_SUFFIX}", fwname[flav,i]);
			}
			printf(" \\\n\t\${FWSUBDIR}/iwlwifi-%s-%s.ucode\${DISTURL_SUFFIX}", fwname[flav,i], fwver[flav,fwname[flav,i]]);
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
}' WHENCE

rm -f WHENCE.awk WHENCE

# end
