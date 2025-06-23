#!/bin/sh
SIGNAL_VERS=v7.58.0

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

sqlcipher_version=$(grep '"@signalapp/sqlcipher":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "SQLCIPHER_VERSION= ${sqlcipher_version}"

fetch -qo /tmp/Cargo.toml https://raw.githubusercontent.com/signalapp/node-sqlcipher/refs/tags/v${sqlcipher_version}/deps/extension/Cargo.toml
sqlcipher_ext_version=$(awk /version/'{print $3}' /tmp/Cargo.toml |head -n1 | sed 's#"##g')
echo "devel/signal-sqlcipher-extension: ${sqlcipher_ext_version}"
