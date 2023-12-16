#!/bin/sh
SIGNAL_VERS=v6.42.0

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

esbuild_version=$(grep '"esbuild":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "ESBUILD_VERSION= ${esbuild_version}"

fetch -qo /tmp/download.js https://raw.githubusercontent.com/signalapp/better-sqlite3/v${bsqlite3_version}/deps/download.js

BASE_URI=https://build-artifacts.signal.org/desktop
HASH=$(awk /"HASH ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
SQLCIPHER_VERSION=$(awk /"SQLCIPHER_VERSION ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
OPENSSL_VERSION=$(awk /"OPENSSL_VERSION ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
TOKENIZER_VERSION=$(awk /"TOKENIZER_VERSION ="/'{print $4}' /tmp/download.js | sed -e 's#;##g' -e "s#'##g")
TAG="${SQLCIPHER_VERSION}--${OPENSSL_VERSION}--${TOKENIZER_VERSION}"
echo "Signal-FTS5-Extension= ${TOKENIZER_VERSION}"
echo "SQLCIPHER=sqlcipher-${TAG}-${HASH}" | portedit merge -i Makefile

fetch -qo /tmp/yarn.lock https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/yarn.lock
npm_signal_hash=$(egrep "libsignal-client.*${libsignalclient_version}" /tmp/yarn.lock | awk -F '#' /resolved/'{print $2}' | sed 's/"//g')
echo "NPM_SIGNAL_DIR=npm-@signalapp-libsignal-client-${libsignalclient_version}-${npm_signal_hash}-integrity" | portedit merge -i Makefile

npm_ringrtc_hash=$(grep ringrtc /tmp/yarn.lock | awk -F '#' /resolved/'{print $2}' | sed 's/"//g')
echo "NPM_RINGRTC_DIR=npm-@signalapp-ringrtc-${ringrtc_version}-${npm_ringrtc_hash}-integrity" | portedit merge -i Makefile

npm_bsqlite3_hash=$(grep better-sqlite3 /tmp/yarn.lock | awk -F '#' /resolved/'{print $2}' | sed 's/"//g')
echo "NPM_SQLITE3_DIR=npm-@signalapp-better-sqlite3-${bsqlite3_version}-${npm_bsqlite3_hash}-integrity" | portedit merge -i Makefile
