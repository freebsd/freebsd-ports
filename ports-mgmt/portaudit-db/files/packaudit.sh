#!/bin/sh -e
#
# Copyright (c) 2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice
#    this list of conditions and the following disclaimer.
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

AWK=/usr/bin/awk
BASENAME=/usr/bin/basename
CAT=/bin/cat
DATE=/bin/date
ENV=/usr/bin/env
MD5=/sbin/md5
MKDIR="/bin/mkdir -p"
MKTEMP=/usr/bin/mktemp
RM=/bin/rm
SED=/usr/bin/sed
TAR=/usr/bin/tar
XSLTPROC=%%LOCALBASE%%/bin/xsltproc

PORTSDIR="${PORTSDIR:-%%PORTSDIR%%}"
VUXMLDIR="${VUXMLDIR:-$PORTSDIR/security/vuxml}"
PORTAUDITDBDIR="${PORTAUDITDBDIR:-$PORTSDIR/security/portaudit-db}"

DATABASEDIR="${DATABASEDIR:-%%DATABASEDIR%%}"

STYLESHEET="%%DATADIR%%/vuxml2portaudit.xslt"

PUBLIC_HTML="${PUBLIC_HTML:-$HOME/public_html/portaudit}"
HTMLSHEET="%%DATADIR%%/vuxml2html.xslt"
BASEURL="${BASEURL:-http://www.freebsd.org/ports/portaudit/}"

PORTAUDIT2VUXML="%%DATADIR%%/portaudit2vuxml.awk"

[ -d "$DATABASEDIR" ] || $MKDIR "$DATABASEDIR"

if [ ! -w "$DATABASEDIR" ]; then
    echo "$DATABASEDIR is not writable by you, exiting."
    exit 1
fi

TMPNAME=`$BASENAME "$0"`

VULVER=`$SED -En -e '/^.*\\$FreeBSD\: [^$ ]+,v ([0-9]+(\.[0-9]+)+) [^$]+\\$.*$/{s//\1/p;q;}' "$VUXMLDIR/vuln.xml"`
VULURL="http://cvsweb.freebsd.org/ports/security/vuxml/vuln.xml?rev=$VULVER"

[ -r "%%PREFIX%%/etc/packaudit.conf" ] && . "%%PREFIX%%/etc/packaudit.conf"

if [ -d "$PUBLIC_HTML" -a -w "$PUBLIC_HTML" ]; then
  VULNMD5=`$CAT "$VUXMLDIR/vuln.xml" "$PORTAUDITDBDIR/database/portaudit.xml" "$PORTAUDITDBDIR/database/portaudit.txt" | $MD5`
  if [ -f "$PUBLIC_HTML/portaudit.md5" ]; then
    VULNMD5_OLD=`$CAT "$PUBLIC_HTML/portaudit.md5"`
  fi
  if [ "$VULNMD5" != "$VULNMD5_OLD" ]; then
    echo -n "$VULNMD5" > "$PUBLIC_HTML/portaudit.md5"
    TMPXML=`$MKTEMP -t "$TMPNAME.$$"` || exit 1
    $PORTAUDIT2VUXML "$PORTAUDITDBDIR/database/portaudit.txt" "$PORTAUDITDBDIR/database/portaudit.xml" > "$TMPXML"
    $XSLTPROC $XSLTPROC_EXTRA_ARGS --stringparam vulurl "$VULURL" --stringparam extradoc "$TMPXML" \
      -o "$PUBLIC_HTML/" "$HTMLSHEET" "$VUXMLDIR/vuln.xml"
    $RM "$TMPXML"
  fi
fi

TMPDIR=`$MKTEMP -d -t "$TMPNAME.$$"` || exit 1

TESTPORT="vulnerability-test-port>=2000<`$DATE -u +%Y.%m.%d`"
TESTURL="http://cvsweb.freebsd.org/ports/security/vulnerability-test-port/"
TESTREASON="Not vulnerable, just a test port (database: `$DATE -u +%Y-%m-%d`)"

XLIST_FILE="$PORTAUDITDBDIR/database/portaudit.xlist"

cd "$TMPDIR" || exit 1
{
  $DATE -u "+#CREATED: %Y-%m-%d %H:%M:%S"
  echo "# Created by packaudit %%PORTVERSION%%"
  echo "$TESTPORT|$TESTURL|$TESTREASON"
  echo "# Please refer to the original document for copyright information:"
  echo "# $VULURL"
  $XSLTPROC $XSLTPROC_EXTRA_ARGS --stringparam baseurl "$BASEURL" "$STYLESHEET" "$VUXMLDIR/vuln.xml" \
  | $AWK -F\| -v XLIST_FILE="$XLIST_FILE" '
    BEGIN {
      while((getline < XLIST_FILE) > 0)
        if(!/^(#|$)/)
          ignore[$1]=1
    }
    /^(#|$)/ || !($4 in ignore) {
      print
    }
  '
  echo "# This part is in the public domain"
  $XSLTPROC $XSLTPROC_EXTRA_ARGS --stringparam baseurl "$BASEURL" "$STYLESHEET" "$PORTAUDITDBDIR/database/portaudit.xml"
  $AWK -F\| '
    /^(#|$)/ {
      print
      next
    }
    {
      if ($4)
        print $1 FS "'"$BASEURL"'" $4 ".html" FS $3 FS $4
      else
        print
    }
  ' "$PORTAUDITDBDIR/database/portaudit.txt"
} | $AWK -F\| -v XLIST_FILE="$XLIST_FILE" '
  /^(#|$)/ {
    print
    next
  }
  {
    print $1 "|" $2 "|" $3
  }
' > auditfile
echo "#CHECKSUM: MD5 `$MD5 < auditfile`" >> auditfile
$TAR -jcf "$DATABASEDIR/auditfile.tbz" auditfile
cd
$RM -Rf "$TMPDIR"
