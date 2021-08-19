#!/bin/sh

# Convenience script to update the free beta key for makemkv in your user's
# configuration.
#
# originally found on https://pastebin.com/vafpYkfa, 2013-08-11
# adapted to FreeBSD by Manfred Heins <manfred.heins@selma.de>, 2021-08-18
# minor improvements by Felix Palmen <felix@palmen-it.de>, 2021-08-19

MAKEMKV_DIR="${HOME}/.MakeMKV"
MAKEMKV_CFG="${MAKEMKV_DIR}/settings.conf"
KEY_URL="http://www.makemkv.com/forum2/viewtopic.php?f=5&t=1053"

BETA_KEY=$(fetch -o- "${KEY_URL}" 2>/dev/null \
	| grep -oe '<code>.*</code>' \
	| sed -E 's:</?code>::g')

if [ "x$BETA_KEY" != x ]; then
	echo "found key: ${BETA_KEY}"
	mkdir -p "${MAKEMKV_DIR}"
	sed -i.bak -e '/app_Key/d' -e '/^$/d' "${MAKEMKV_CFG}" 2>/dev/null
	echo "app_Key = \"${BETA_KEY}\"" >> ${MAKEMKV_CFG}
else
	echo "key could not be found." >&2
	exit 1
fi

