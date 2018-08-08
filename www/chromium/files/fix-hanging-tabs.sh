#! /bin/sh -
#
# Chromium has a known problem of hanging tabs.  The workaround for this
# problem is to mount ~/.cache/chromium as memory-fs.  In order to do this,
# before you run Chromium, please run this script as root once for each user
# who uses Chromium.
#
# $FreeBSD$

set -e

# Make sure that the user specified both the user and the group.
if [ ${#} -ne 2 ]; then
	printf 'Usage: %s user group\n' "${0}" >&2
	exit 1
fi

user="${1}"
group="${2}"
home="$(awk -F: -v user="${user}" '{if ($1==user) print $6}' /etc/passwd)"
cachedir="${home}/.cache/chromium"
fstabrecord="md ${cachedir} mfs rw,late,-w${user}:${group},-s300m 2 0"

# Make sure that the provided user and group are valid.
if ! id "${user}" >/dev/null 2>&1; then
	printf 'Invalid user "%s"\n' "${user}" >&2
	exit 1
elif [ ! -d "${home}" ]; then
	printf 'Cannot locate home directory of user "%s"\n' "${user}" >&2
	exit 1
elif ! grep "^${group}:" /etc/group >/dev/null; then
	printf 'Invalid group "%s"\n' "${group}" >&2
	exit 1
fi

if grep "${fstabrecord}" /etc/fstab >/dev/null; then
	printf 'Workaround already configured for user "%s"\n' "${user}" >&2
	exit 1
fi

if [ ! -d "${cachedir}" ]; then
	su -l "${user}" -c 'mkdir "${cachedir}"'
fi
printf '%s\n' "${fstabrecord}" >> /etc/fstab
mount "${cachedir}"
