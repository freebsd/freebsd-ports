#!/bin/sh
SIGNAL_VERS=v8.13.0

fetch -qo /tmp/package.json https://raw.githubusercontent.com/signalapp/Signal-Desktop/${SIGNAL_VERS}/package.json

############ NODE ############
node_version=$(awk /'"node":'/'{print $2}' /tmp/package.json | head -n 1 | sed 's/"//g')
node_major_version=$(echo ${node_version} | cut -d '.' -f 1)
echo "requires: www/node${node_major_version}"

node_installed_version=$(pkg info www/node${node_major_version} | awk /Version/'{print $3}')
printf "version installed: ${node_installed_version}\n\n"

############ ELECTRON ############
electron_version=$(grep '"electron":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
electron_major_version=$(echo ${electron_version} | cut -d '.' -f 1)
echo "requires: devel/electron${electron_major_version}"

electron_installed_version=$(pkg info devel/electron${electron_major_version} | awk /Version/'{print $3}')
printf "version installed: ${electron_installed_version}\n\n"

############ RINGRTC ############
ringrtc_version=$(grep '@signalapp/ringrtc"' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "requires: multimedia/ringrtc v${ringrtc_version}"

ringrtc_ports_version=$(make -C ../../multimedia/ringrtc -V DISTVERSION)
echo "version in ports: ${ringrtc_ports_version}"

ringrtc_installed_version=$(pkg info multimedia/ringrtc | awk /Version/'{print $3}')
echo "version installed: ${ringrtc_installed_version}"
echo

############ LIBSIGNAL-NODE ############
libsignalclient_version=$(grep '@signalapp/libsignal-client' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "requires: net-im/libsignal-node v${libsignalclient_version}"

libsignal_ports_version=$(make -C ../libsignal-node -V DISTVERSION)
echo "version in ports: ${libsignal_ports_version}"

libsignal_installed_version=$(pkg info net-im/libsignal-node | awk /Version/'{print $3}')
echo "version installed: ${libsignal_installed_version}"
echo

############ NODE-SQLCIPHER ############
sqlcipher_version=$(grep '"@signalapp/sqlcipher":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "requires: security/node-sqlcipher v${sqlcipher_version}"

sqlcipher_ports_version=$(make -C ../../security/node-sqlcipher -V DISTVERSION)
echo "version in ports: ${sqlcipher_ports_version}"

sqlcipher_installed_version=$(pkg info security/node-sqlcipher | awk /Version/'{print $3}')
echo "version installed: ${sqlcipher_installed_version}"
echo

############ SIGNAL-SQLCIPHER-EXTENSION ############
fetch -qo /tmp/Cargo.toml https://raw.githubusercontent.com/signalapp/node-sqlcipher/refs/tags/v${sqlcipher_version}/deps/extension/Cargo.toml
sqlcipher_ext_version=$(awk /version/'{print $3}' /tmp/Cargo.toml | head -n1 | sed 's#"##g')
echo "requires: devel/signal-sqlcipher-extension v${sqlcipher_ext_version}"

signal_sqlcipher_ports_version=$(make -C ../../devel/signal-sqlcipher-extension -V DISTVERSION)
echo "version in ports: ${signal_sqlcipher_ports_version}"

signal_sqlcipher_installed_version=$(pkg info devel/signal-sqlcipher-extension | awk /Version/'{print $3}')
echo "version installed: ${signal_sqlcipher_installed_version}"
echo

############ PNPM ############
pnpm_version=$(grep '"packageManager":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g' | sed 's#pnpm@##')
echo "requires: PNPM_VERS ${pnpm_version}"

############ WEBRTC ############
webrtc_version=$(fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.properties | grep 'webrtc.version' | awk -F '=' '{print $2}')
printf "WEBRTC_REV=\t${webrtc_version}\n" | portedit merge -i ../../multimedia/ringrtc/Makefile
sed -i '' "s#WEBRTC_REV=.*#WEBRTC_REV=${webrtc_version}#g" ../../multimedia/ringrtc/webrtc_fetch.sh
