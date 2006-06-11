#! /bin/sh --
# (X)Emacs: -*- mode: Shell-Script; coding: iso8859-1; -*-
# @(#)portless.sh,v 1.3 2006/06/08 10:10:56 martin Exp
# Show "pkg-descr" file of matching port(s).
#
# Copyright (c) 2006 Martin Kammerhofer <mkamm@gmx.net>
# All rights reserved.
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

Script=`basename $0` # name of this script

# set defaults
opt_f=""
PORTSDIR=${PORTSDIR:-/usr/ports}
PAGER=${PAGER=$:-less -e}
PKGDESCR="pkg-descr"

# print usage message to stderr and exit
usage()
{
    while [ $# != 0 ]; do
	echo >&2 "$Script: $1"
	shift
    done
    echo >&2 "usage: $Script [-dfiMmp] [-P pager] 'portglob'..."
    exit 64	# EX_USAGE
}

# process options
while getopts "D:dfiMmpP:" option
  do
  case "$option" in
      (D) PORTSDIR="$OPTARG";;
      (d) PKGDESCR="pkg-descr";;
      (f) opt_f="f";;
      (i) PKGDESCR="distinfo";;
      (M) PKGDESCR="Makefile";;
      (m) PKGDESCR="pkg-message";;
      (p) PKGDESCR="pkg-plist";;
      (P) PAGER="$OPTARG";;
      (*) usage;;
  esac
done
shift $(($OPTIND - 1))

# there must be at least one argument
if [ $# = 0 ]; then
    usage
fi

# main
for p in "$@"; do
    case "$p" in
	(*/*/*)
	usage "portglob '$p' contains more than one slash!";;

	(*/*)
	if [ -n "$opt_f" ]; then
	    $PAGER "$PORTSDIR/$p/$PKGDESCR"
	else
	    $PAGER "$PORTSDIR"/$p/"$PKGDESCR"
	fi;;

	(*)
	if [ -n "$opt_f" ]; then
	    $PAGER "$PORTSDIR"/[a-z]*/"$p/$PKGDESCR"
	else
	    $PAGER "$PORTSDIR"/[a-z]*/$p/"$PKGDESCR"
	fi;;
    esac
done

#EOF#
