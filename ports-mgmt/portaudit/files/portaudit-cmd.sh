#!/bin/sh -efu
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

portaudit_confs()
{
	: ${portaudit_dir="%%DATABASEDIR%%"}
	: ${portaudit_filename="auditfile.tbz"}

	: ${portaudit_fetch_env=""}
	: ${portaudit_fetch_cmd="fetch -1mp"}

	: ${portaudit_sites="http://www.FreeBSD.org/ports/"}

	: ${portaudit_fixed=""}

	if [ -r %%PREFIX%%/etc/portaudit.conf ]; then
		. %%PREFIX%%/etc/portaudit.conf
	fi
}

extract_auditfile()
{
	%%BZIP2_CMD%% -dc -- "$portaudit_dir/$portaudit_filename" | \
		tar -xOf - auditfile
}

checksum_auditfile()
{
	chksum1=`extract_auditfile |
		sed -nE -e '$s/^#CHECKSUM: *MD5 *([0-9a-f]{32})$/\1/p'`
	chksum2=`extract_auditfile | sed -e '$d' | md5`
	[ "$chksum1" = "$chksum2" ];
}

getcreated_auditfile()
{
	extract_auditfile |
		sed -nE -e '1s/^#CREATED: *([0-9]{4})-?([0-9]{2})-?([0-9]{2}) *([0-9]{2}):?([0-9]{2}):?([0-9]{2}).*$/\1-\2-\3 \4:\5:\6/p'
}

gettimestamp_auditfile()
{
	extract_auditfile |
		sed -nE -e '1s/^#CREATED: *([0-9]{4})-?([0-9]{2})-?([0-9]{2}).*$/\1\2\3/p'
}

checkexpiry_auditfile()
{
	created=`gettimestamp_auditfile`
	expiry=`date -u -v-$1d '+%Y%m%d'`
	[ "$created" -gt "$expiry" ];
}

portaudit_prerequisites()
{
	if $prerequisites_checked; then
		return 0
	fi

	if [ -z "${pkg_info:-}" ]; then
		if [ -x "%%LOCALBASE%%/sbin/pkg_info" ]; then
			pkg_info="%%LOCALBASE%%/sbin/pkg_info"
		else
			pkg_info="/usr/sbin/pkg_info"
		fi
	fi

	if [ -z "${pkg_version:-}"]; then
		case "$pkg_info" in
		*/*)
			pkg_version="${pkg_info%/*}/pkg_version";;
		*)
			pkg_version="pkg_version";;
		esac
	fi

	PKG_INSTALL_VER=`$pkg_info -qP 2>/dev/null`
	if [ -z "$PKG_INSTALL_VER" -o "$PKG_INSTALL_VER" -lt %%REQPKGVER%% ]; then
		echo "$pkg_info is too old, please update port sysutils/pkg_install-devel"
		return 1
	fi

	if [ ! -r "$portaudit_dir/$portaudit_filename" ]; then
		echo "portaudit: Database missing, run \`portaudit -F' to update." >&2
		return 2
	elif ! checksum_auditfile; then
		echo "portaudit: Corrupt database." >&2
		return 2
	elif ! checkexpiry_auditfile 14; then
		echo "portaudit: Database too old." >&2
		return 2
	fi

	prerequisites_checked=true
	return 0
}

audit_installed()
{
	local rc=0
	local osversion=`sysctl -n kern.osreldate`

	fixedre=`echo -n $portaudit_fixed | tr -c '[:alnum:]- \t\n' 'x' | tr -s ' \t\n' '|'`

	extract_auditfile | awk -F\| "$PRINTAFFECTED_AWK"'
		BEGIN { vul=0; fixedre="'"$fixedre"'" }
		/^(#|\$)/ { next }
		$2 !~ /'"$opt_restrict"'/ { next }
		$1 ~ /^FreeBSD[<=>!]/ {
			if (fixedre && $2 ~ fixedre) next
			if (!system("'"$pkg_version"' -T \"FreeBSD-'"$osversion"'\" \"" $1 "\"")) {
				print_affected("FreeBSD-'"$osversion"'", \
					"To disable this check add the uuid to \`portaudit_fixed'"'"' in %%PREFIX%%/etc/portaudit.conf")
			}
			next
		}
		{
			cmd="'"$pkg_info"' -E \"" $1 "\""
			while((cmd | getline pkg) > 0) {
				vul++
				print_affected(pkg, "")
			}
			close(cmd)
		}
		END {
			if ("'$opt_quiet'" == "false") {
				print vul " problem(s) in your installed packages found."
			}
			if (vul > 0) {
				if ("'$opt_quiet'" == "false") {
					print "\nYou are advised to update or deinstall" \
						" the affected package(s) immediately."
				}
				exit(1)
			}
		}
	' || rc=$?

	return $rc
}

audit_file()
{
	local rc=0
	local TMPFILE=

	case "$1" in
	-)
		TMPFILE=`mktemp -t portaudit`
		cat > "$TMPFILE"
		FILE="$TMPFILE"
		;;
	http://*|ftp://*|https://*|file://*)
		echo "portaudit: Can't audit remote file $1" >&2
		return 2
		;;
	*)
		if [ -r "$1" ]; then
			FILE="$1"
        	else
			echo "portaudit: Can't read $1" >&2
			return 2
		fi
		;;
	esac

	extract_auditfile | awk -F\| "$PRINTAFFECTED_AWK"'
		BEGIN { vul=0 }
		/^(#|\$)/ { next }
		{
			cmd="'"$pkg_version"' -T - \"" $1 "\" <\"'"$FILE"'\""
			while((cmd | getline pkg) > 0) {
				if ($2 !~ /'"$opt_restrict"'/)
					continue
				vul++
				print_affected(pkg, "")
			}
			close(cmd)
		}
		END {
			print vul " problem(s) found."
			if (vul > 0) {
				exit(1)
			}
		}
	' || rc=$?

	if [ -n "$TMPFILE" ]; then
		rm "$TMPFILE"
	fi
	return $rc
}

audit_args()
{
	local VULCNT=0
	while [ $# -gt 0 ]; do
		case "$1" in
		/*|-)
			echo "portaudit: $1 is a file, please use the -f option" >&2
			;;
		http://*|ftp://*|https://*|file://*)
			echo "portaudit: Can't audit remote file $1" >&2
			;;
		*)
			if VLIST=`extract_auditfile | awk -F\| '
					/^(#|\$)/ { next }
					$2 !~ /'"$opt_restrict"'/ { next }
					{ print }
				' | $pkg_version -T "$1" -`; then
				VULCNT=$(($VULCNT+1))
				echo "$VLIST" | awk -F\| "$PRINTAFFECTED_AWK"'
					{ print_affected("'"$1"'", "") }
				'
			fi
			;;
		esac
		shift
	done
	$opt_quiet || echo "$VULCNT problem(s) found."
	if [ $VULCNT -gt 0 ]; then
		return 1
	fi
}

audit_cwd()
{
	if [ ! -r "Makefile" ]; then
		echo "portaudit: No Makefile here" >&2
		return 2
	fi

	PKGNAME=`make -VPKGNAME 2>/dev/null || true"`

	if [ -z "$PKGNAME" ]; then
		echo "portaudit: Can't determine the package name" >&2
		return 2
	fi

	if VLIST=`extract_auditfile | awk -F\| '
			/^(#|\$)/ { next }
			$2 !~ /'"$opt_restrict"'/ { next }
			{ print }
		' | $pkg_version -T "$PKGNAME" -`; then
		echo "$VLIST" | awk -F\| "$PRINTAFFECTED_AWK"'
			{ print_affected("'"$PKGNAME"'", "") }
		'
		return 1
	fi
}

fetch_auditfile()
{
	local rc=2

	if [ ! -d "$portaudit_dir" ]; then
		if ! mkdir -p "$portaudit_dir"; then
			echo "Couldn't create $portaudit_dir, try running \`portaudit -F' as root" >&2
			return 2
		fi
	fi
	if [ ! -w "$portaudit_dir" ]; then
		echo "Couldn't write to $portaudit_dir, try running \`portaudit -F' as root" >&2
		return 2

	fi
	cd "$portaudit_dir"
	if [ -r "$portaudit_filename" ]; then
		cp -f "$portaudit_filename" "$portaudit_filename.old"
	fi

	$opt_verbose && echo "Attempting to fetch from $portaudit_sites."
	urls=`echo "$portaudit_sites" | tr -s ' \t' '\n' | sed -E -e "s/?\$/$portaudit_filename"`

	if ! env $portaudit_fetch_env $portaudit_fetch_cmd $urls; then
		echo "Couldn't fetch database." >&2
	elif [ ! -f "$portaudit_dir/$portaudit_filename" ] ; then
		echo "portaudit: No database." >&2
	elif ! checksum_auditfile; then
		echo "portaudit: Database corrupt." >&2
	elif ! checkexpiry_auditfile 7; then
		echo "portaudit: Database too old." >&2
	else
		$opt_quiet || echo "New database installed."
		rc=0
		break
	fi

        if [ -f "$portaudit_filename.old" ]; then
        	if [ $rc -eq 0 ]; then
			rm -f "$portaudit_filename.old"
		else
			mv -f "$portaudit_filename.old" "$portaudit_filename"
			$opt_quiet || echo "Old database restored."
		fi
	fi
	if [ -f "$portaudit_filename" ]; then
		chmod a=r "$portaudit_filename"
	fi

	return $rc
}

portaudit_confs

opt_audit=false
opt_auditcwd=false
opt_dbversion=false
opt_fetch=false
opt_file=
opt_quiet=false
opt_restrict=
opt_verbose=false
opt_version=false
opt_expiry=

if [ $# -eq 0 ] ; then
	opt_audit=true
fi

while getopts aCdf:Fqr:vVX: opt; do
	case "$opt" in
	a)
		opt_audit=true;;
	C)
		opt_auditcwd=true;;
	d)
		opt_dbversion=true;;
	f)
		opt_file="$OPTARG";;
	F)
		opt_fetch=true;;
	q)
		opt_quiet=true;;
	r)
		opt_restrict="$OPTARG";;
	v)
		opt_verbose=true;;
	V)
		opt_version=true;;
	X)
		opt_expiry="$OPTARG";;
	?)
		echo "Usage: $0 -aCdFVvq [-X days] [-r pattern] [-f file] [pkg-name ...]"
		exit 2;;
	esac
done

shift $(($OPTIND-1))

ret=0

if $opt_version; then
	echo "portaudit version %%PORTVERSION%%"
fi

if $opt_fetch; then
	if ! fetch_auditfile; then
		echo "portaudit: Download failed." >&2
		exit 2
	fi
elif [ -n "$opt_expiry" ]; then
	if [ ! -r "$portaudit_dir/$portaudit_filename" ] || ! checkexpiry_auditfile "$opt_expiry"; then
		$opt_quiet || echo "Downloading fresh database."
		if ! fetch_auditfile; then
			echo "portaudit: Download failed." >&2
			exit 2
		fi
		ret=1
	fi
fi

if $opt_dbversion; then
	if [ ! -f "$portaudit_dir/$portaudit_filename" ]; then
		echo "portaudit: Database missing, run \`portaudit -F' to update." >&2
		exit 2
	fi
	if ! checksum_auditfile; then
		echo "portaudit: Database corrupt." >&2
		exit 2
	fi
	created=`getcreated_auditfile`
	echo "Database created: `date -j -f '%Y-%m-%d %H:%M:%S %Z' \"$created GMT\"`"
fi

prerequisites_checked=false

if $opt_quiet; then
	PRINTAFFECTED_AWK='
		function print_affected(apkg, note) {
			print apkg
		}
		'
elif $opt_verbose; then
	PRINTAFFECTED_AWK='
		function print_affected(apkg, note) {
			split(apkg, thepkg)
			print "Affected package: " thepkg[1] " (matched by " $1 ")"
			print "Type of problem: " $3 "."
			split($2, ref, / /)
			for (r in ref)
				print "Reference: <" ref[r] ">"
			if (note)
				print "Note: " note
			print ""
		}
		'
else
	PRINTAFFECTED_AWK='
		function print_affected(apkg, note) {
			split(apkg, thepkg)
			print "Affected package: " thepkg[1]
			print "Type of problem: " $3 "."
			split($2, ref, / /)
			for (r in ref)
				print "Reference: <" ref[r] ">"
			if (note)
				print "Note: " note
			print ""
		}
		'
fi

if $opt_audit; then
	portaudit_prerequisites
	audit_installed || ret=$?
fi

if $opt_auditcwd; then
	portaudit_prerequisites
	audit_cwd || ret=$?
fi

if [ -n "$opt_file" ]; then
	portaudit_prerequisites
	audit_file "$opt_file" || ret=$?
fi

if [ $# -gt 0 ]; then
	portaudit_prerequisites
	audit_args "$@" || ret=$?
fi

exit $ret
