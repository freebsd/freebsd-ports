#!/bin/sh
# Script for assembling the node dependencies required for FreeBSD packaging
#
# This is what I run to get the node_modules dirs needed to build the port
#
# Clone the https://github.com/deltachat/deltachat-desktop repo
# Then start with something like the following:
# git checkout -b v2.22.0 tags/v2.22.0
#
# Finally you can run this script.
#
# Requirements: electron37, node, npm, deltachat-rpc-server

set -eu

VERSION=$(git branch --show-current)

export ELECTRON_OVERRIDE_DIST_PATH=/usr/local/share/electron37
export ELECTRON_SKIP_BINARY_DOWNLOAD=1

# Cleanup
rm -rf node_modules pnpm packages/target-electron/node_modules deltachat-desktop-2.15.0-node-deps.tgz
git reset --hard

# Install pnpm in temp dir to avoid package.json parsing issues
# It would throw an error on the "catalog:"
CWD=$(pwd)
TMP=$(mktemp -d)
cd $TMP
npm i pnpm
mv node_modules $CWD
cd $CWD
rm -r $TMP

# Install all dependencies
echo "Installing dependencies..."
pnpm install

# Build workspace packages that have build steps
echo "Building workspace packages..."
# shared and runtime are just TypeScript source, no build needed
pnpm --filter @deltachat-desktop/frontend build

# Test the main build to ensure everything works
echo "Testing main build..."
cd packages/target-electron
pnpm build
cd ../..

echo "Build test successful! All dependencies are working."

# Remove platform-specific modules/binaries we don't need for FreeBSD
# TODO: there are possibly more that could be excluded
echo "Cleaning platform-specific binaries..."
rm -rf node_modules/.pnpm/*linux*
rm -rf node_modules/.pnpm/*darwin*
rm -rf node_modules/.pnpm/*win32*
rm -rf node_modules/.pnpm/*android*
rm -rf node_modules/.pnpm/@tauri-apps*
rm -rf node_modules/.pnpm/app-builder*

# Remove duplicates which will make it harder to select the right path by
# globbing in Makefile during packaging
find node_modules/.pnpm -name "@deltachat+stdio-rpc-server@*" -type d | tail -n+2 | xargs rm -r

echo "Creating tarball..."
tar -czvpf deltachat-desktop-${VERSION}-node-deps.tgz \
    node_modules \
    packages/target-electron/node_modules \
    packages/frontend/node_modules \
    packages/runtime/node_modules \
    packages/shared/node_modules

echo ""
echo "Tarball created successfully!"
echo "You can now upload this distfile"
