#!/bin/sh

#
# $FreeBSD$
#

# defaults
daily_status_portaudit_enable="YES"
portaudit_dir="%%DATABASEDIR%%"

# If there is a global system configuration file, suck it in.
#
if [ -r /etc/defaults/periodic.conf ]
then
    . /etc/defaults/periodic.conf
    source_periodic_confs
fi

. %%DATADIR%%/portaudit.functions

portaudit_file="${portaudit_dir}/auditfile.tbz"

rc=0
case "$daily_status_portaudit_enable" in
	""|[Yy][Ee][Ss])
		echo ""
		echo "Checking for packages with security vulnerabilities:"
		echo ""

		if [ -z "${PKG_INFO}" ]; then
			if [ -x /usr/local/sbin/pkg_info ]; then
				PKG_INFO=/usr/local/sbin/pkg_info
			else
				PKG_INFO=/usr/sbin/pkg_info
			fi
		fi

		if [ ! -x "${PKG_INFO}" ]; then
			echo "${PKG_INFO} missing, please install port sysutils/pkg_install-devel"
			exit 2
		fi

		PKG_INSTALL_VER=`${PKG_INFO} -qP 2>/dev/null`
		if [ -z "${PKG_INSTALL_VER}" -o "${PKG_INSTALL_VER}" -lt 20040125 ]; then
			echo "${PKG_INFO} is too old, please update port sysutils/pkg_install-devel"
			exit 2
		fi

		if [ ! -f "${portaudit_file}" ]; then
			echo "portaudit: database missing."
			echo "           run fetchaudit to update."
			exit 2
		fi
		if checksum_auditfile; then
			echo "portaudit: corrupt database."
			exit 2
		fi
		if checkexpiry_auditfile 14; then
			echo "portaudit: database too old."
			echo ""
			rc=2
		fi

		extract_auditfile | awk -F\| "
			BEGIN { vul=0 }
			/^(#|\$)/ { next }
			{
				cmd=\"${PKG_INFO} -E \\\"\" \$1 \"\\\"\"
				while((cmd | getline pkg) > 0) {
					vul++
					print \"Affected package: \" pkg \"\\n\" \
						\"Type of problem: \" \$3 \".\\n\" \
						\"Reference: <\" \$2 \">\\n\"
				}
				close(cmd)
			}
			END {
				print vul \" problem(s) in your installed packages found.\"
				if (vul > 0) exit(1)
			}
		" || rc=1
		;;
	*)
		;;
esac

exit "$rc"
