#!/bin/sh
SIGNAL_VERS=v7.27.0

fetch -qo /tmp/package.json https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/package.json
node_version=$(awk /'"node":'/'{print $2}' /tmp/package.json | sed 's/"//g')
echo "NODE_VERSION= ${node_version}"

ringrtc_version=$(grep '@signalapp/ringrtc"' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "RINGRTC_VERSION= ${ringrtc_version}"

webrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.properties | grep 'webrtc.version' | awk -F '=' '{print $2}')
echo "WEBRTC_REV= ${webrtc_version}"

libsignalclient_version=$(grep '@signalapp/libsignal-client' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "LIBSIGNAL_VERSION= ${libsignalclient_version}"

electron_version=$(grep '"electron":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "ELECTRON_VERSION= ${electron_version}"

bsqlite3_version=$(grep '@signalapp/better-sqlite3' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')

fetch -qo /tmp/download.js https://raw.githubusercontent.com/signalapp/better-sqlite3/v${bsqlite3_version}/deps/download.js
BASE_URI=https://build-artifacts.signal.org/desktop
HASH=$(awk /"HASH ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
SQLCIPHER_VERSION=$(awk /"SQLCIPHER_VERSION ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
OPENSSL_VERSION=$(awk /"OPENSSL_VERSION ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
TOKENIZER_VERSION=$(awk /"TOKENIZER_VERSION ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
TAG="${SQLCIPHER_VERSION}--${OPENSSL_VERSION}--${TOKENIZER_VERSION}"
echo "Signal-FTS5-Extension= ${TOKENIZER_VERSION}"
echo "SQLCIPHER=sqlcipher-${TAG}-${HASH}" | portedit merge -i Makefile

echo "fetch https://build-artifacts.signal.org/desktop/sqlcipher-${TAG}-${HASH}.tar.gz"
