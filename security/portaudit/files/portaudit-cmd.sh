#!/bin/sh -ef
#
# Copyright (c) 2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#  1. Redistributions of source code must retain the above copyright notice
#     this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the author nor the names of its contributors may be
#    used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $FreeBSD$
#

. %%DATADIR%%/portaudit.functions
portaudit_confs

opt_audit=false
opt_version=false
opt_dbversion=false
opt_fetch=false
opt_quiet=false

if [ $# -eq 0 ] ; then
	opt_audit=true
fi

while getopts aVdFq opt; do
	case "$opt" in
	a)
		opt_audit=true;;
	d)
		opt_dbversion=true;;
	F)
		opt_fetch=true;;
	q)
		opt_quiet=true;;
	V)
		opt_version=true;;
	?)
		echo "Usage: $0 -adFqV"
		exit 2;;
	esac
done

shift $(($OPTIND - 1))

if $opt_version; then
	echo "portaudit version %%PORTVERSION%%"
fi

if $opt_fetch; then
	fetch_auditfile || echo "failed."
fi

if $opt_dbversion; then
	if [ ! -f "${portaudit_dir}/${portaudit_filename}" ]; then
		echo "portaudit: database missing. run \`portaudit -F' to update."
		exit 2
	fi
	if ! checksum_auditfile; then
		echo "portaudit: database corrupt."
		exit 2
	fi
	echo "database created: `getcreated_auditfile`"
fi

if $opt_audit; then
	portaudit_prerequisites
	audit_installed || true
fi
