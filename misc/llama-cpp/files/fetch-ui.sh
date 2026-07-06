#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org
#
# This script is used during the fetch phase of the llama-cpp port.
# It downloads npm dependencies for the embedded WebUI using the port's
# committed package-lock.json and packages node_modules into a tarball.
# The actual build (npm run build) happens during the build phase.
#
# Args:
#   $1 - DISTVERSION (e.g., 9426)
#   $2 - DISTDIR/DIST_SUBDIR path where distfiles are stored
#   $3 - GH tarball filename (e.g., ggerganov-llama.cpp-b9426_GH0.tar.gz)
#   $4 - FILESDIR path (e.g., /usr/ports/misc/llama-cpp/files)

set -eu -o pipefail

DISTVERSION="$1"
DIST_SUBDIR_PATH="$2"
GH_TARBALL_NAME="$3"
FILESDIR="$4"

LOCALBASE="${LOCALBASE:-/usr/local}"

if [ -z "${TMPDIR:-}" ]; then
	TMPDIR="/tmp"
fi

BUILD_DIR="${TMPDIR}/llama-ui-npm-$$"
GH_TARBALL="${DIST_SUBDIR_PATH}/${GH_TARBALL_NAME}"
OUTPUT="${DIST_SUBDIR_PATH}/llama-ui-npm-${DISTVERSION}.tar.gz"
PORT_PACKAGE_LOCK="${FILESDIR}/package-lock.json"

if [ -f "${OUTPUT}" ]; then
	echo "INFO: ${OUTPUT} already exists, skipping"
	exit 0
fi

if [ ! -f "${GH_TARBALL}" ]; then
	echo "ERROR: GH tarball ${GH_TARBALL} not found"
	exit 1
fi

if [ ! -f "${PORT_PACKAGE_LOCK}" ]; then
	echo "ERROR: package-lock.json not found at ${PORT_PACKAGE_LOCK}"
	echo "       please ensure the file exists in the port's files/ directory"
	exit 1
fi

if [ ! -f "${LOCALBASE}/share/certs/ca-root-nss.crt" ]; then
	echo "ERROR: CA certificate file ${LOCALBASE}/share/certs/ca-root-nss.crt is missing"
	echo "       please install the 'ca_root_nss' package"
	exit 1
fi

echo "INFO: Downloading npm dependencies for llama-ui"

rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"

# Extract the main source tarball
tar xzf "${GH_TARBALL}" -C "${BUILD_DIR}"
SRC_DIR="${BUILD_DIR}/llama.cpp-b${DISTVERSION}"

if [ ! -d "${SRC_DIR}/tools/ui" ]; then
	echo "ERROR: tools/ui directory not found in extracted source"
	exit 1
fi

# Install npm dependencies using the port's committed package-lock.json
cd "${SRC_DIR}/tools/ui"

echo "INFO: using package-lock.json from ${PORT_PACKAGE_LOCK}"
cp "${PORT_PACKAGE_LOCK}" package-lock.json

HOME="${TMPDIR}" \
NODE_EXTRA_CA_CERTS="${LOCALBASE}/share/certs/ca-root-nss.crt" \
npm ci --ignore-scripts

echo "INFO: npm ci succeeded"

# Package node_modules into a reproducible tarball
cd "${SRC_DIR}/tools/ui"
find node_modules -exec touch -h -d 1970-01-01T00:00:00Z {} +
find node_modules -print0 | LC_ALL=C sort -z | \
	tar czf "${OUTPUT}" --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -

# Cleanup
rm -rf "${BUILD_DIR}"

echo "INFO: created ${OUTPUT}"
