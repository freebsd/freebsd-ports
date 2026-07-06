#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

# This script fetches the audio-capture Rust source from GitHub, vendors all
# Cargo dependencies using 'cargo vendor', and packages everything into a
# reproducible tarball suitable for offline builds.
#
# Usage: $0 <commit> <output-tarball>
# Example: $0 bb370f75235254da2c3d34f6168fc4a9902d9090 /distfiles/audio-capture-bb370f75.tar.gz

set -euo pipefail

export LC_ALL=C
umask 002

AUDIO_CAPTURE_COMMIT="$1"
PACKAGE_TARBALL_OUTPUT="$2"

LOCALBASE="${LOCALBASE:-/usr/local}"

if [ -z "$AUDIO_CAPTURE_COMMIT" ] || [ -z "$PACKAGE_TARBALL_OUTPUT" ]; then
	echo "Usage: $0 <commit> <output-tarball>"
	exit 1
fi

if [ -z "$TMPDIR" ]; then
	TMPDIR="/tmp"
fi

# to full paths
if ! echo "${PACKAGE_TARBALL_OUTPUT}" | grep -q "^/"; then
	PACKAGE_TARBALL_OUTPUT="`pwd`/${PACKAGE_TARBALL_OUTPUT}"
fi
if ! echo "${TMPDIR}" | grep -q "^/"; then
	TMPDIR="`pwd`/${TMPDIR}"
fi

BUILD_DIR="${TMPDIR}/audio-capture-fetch-${AUDIO_CAPTURE_COMMIT}"
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

# Download source from GitHub
echo "===> Downloading audio-capture source (commit ${AUDIO_CAPTURE_COMMIT})"
${LOCALBASE}/bin/curl -sL \
	"https://github.com/kstonekuan/audio-capture/archive/${AUDIO_CAPTURE_COMMIT}.tar.gz" \
	-o source.tar.gz
tar xzf source.tar.gz
rm source.tar.gz
SRC="audio-capture-${AUDIO_CAPTURE_COMMIT}"

# Vendor all Cargo dependencies into the source tree
echo "===> Vendoring Rust dependencies"
cd "${BUILD_DIR}/${SRC}"
CARGO_HOME="${BUILD_DIR}/cargo-home" cargo vendor cargo-crates 2>&1 | tail -5

# Write .cargo/config.toml to use vendored crates
cat > "${BUILD_DIR}/${SRC}/.cargo/config.toml" << 'EOF'
[source.crates-io]
replace-with = "vendored-sources"

[source.vendored-sources]
directory = "cargo-crates"

[target.aarch64-apple-darwin]
rustflags = ["-C", "link-args=-undefined dynamic_lookup"]

[target.x86_64-apple-darwin]
rustflags = ["-C", "link-args=-undefined dynamic_lookup"]
EOF

# Create a deterministic tarball (normalise timestamps, permissions, sort entries)
echo "===> Creating tarball"
cd "${BUILD_DIR}"
find "${SRC}" -type d -exec chmod 755 {} \;
find "${SRC}" -type f ! -perm -0100 -exec chmod 644 {} \;
find "${SRC}" -type f -perm -0100 -exec chmod 755 {} \;
find "${SRC}" -and -exec touch -h -d 1970-01-01T00:00:00Z {} \;
find "${SRC}" -print0 | sort -z | \
	tar czf "${PACKAGE_TARBALL_OUTPUT}" \
		--format=bsdtar --no-read-sparse --gid 0 --uid 0 \
		--options gzip:!timestamp --no-recursion --null -T -

rm -rf "${BUILD_DIR}"
echo "===> Created: ${PACKAGE_TARBALL_OUTPUT}"
