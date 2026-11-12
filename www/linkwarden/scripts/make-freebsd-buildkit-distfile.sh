#!/bin/sh

set -eu

# Run this from the port dir with the target version as the arg like:
# sh scripts/make-freebsd-buildkit-distfile.sh 2.17.0

# Tip: when prepping for an upgrade, the patches may not apply
# cleanly. Comment out the buildkit distfile in the Makefile
# and ensure "make patch" passes without issues before
# trying to generate this distfile.

# Requirements: python3, node, npm, jq
# Maybe others

RELEASE=$(make -V PORTVERSION)
MASTERDIR=$(make -V MASTERDIR)
WRKDIR=$(make -V WRKDIR)
WRKSRC=$(make -V WRKSRC)

make clean
make patch

# Make the dir for holding the distfiles
KITDIR="${WRKDIR}/linkwarden-freebsd-buildkit-${RELEASE}"
mkdir -p ${KITDIR}

# jump in the source
cd ${WRKSRC}

# get the yarnpkg version from the package.json
YARNPKG_VER=$(jq .packageManager < package.json | awk -F\@ '{print $2}' | awk -F\+ '{print $1}' | sed 's/^"//')

npm pack @yarnpkg/cli-dist@${YARNPKG_VER}

YARNPKG_TGZ="yarnpkg-cli-dist-${YARNPKG_VER}.tgz"

# Extract only yarn.js to stdout so we don't get the dirs
tar --to-stdout -xzvpf ${YARNPKG_TGZ} package/bin/yarn.js > ${KITDIR}/yarn.js

# get the nextjs version
NEXT_VER=$(jq -r '.dependencies["@next/swc-wasm-nodejs"]' apps/web/package.json)

npm pack @next/swc-wasm-nodejs@${NEXT_VER}

NEXT_TGZ="next-swc-wasm-nodejs-${NEXT_VER}.tgz"

# extracts to "package/*"
tar -xzvpf ${NEXT_TGZ}

# Move it, rename it
mv package ${KITDIR}/swc-wasm-nodejs

# Prep for generating the yarn-cache
mkdir -p ${KITDIR}/yarn-cache
echo "cacheFolder: ${KITDIR}/yarn-cache" >> .yarnrc.yml
echo "enableGlobalCache: false" >> .yarnrc.yml

export YARN_ENABLE_IMMUTABLE_INSTALLS=false
node ${KITDIR}/yarn.js install --mode=update-lockfile
node ${KITDIR}/yarn.js workspaces focus linkwarden @linkwarden/web @linkwarden/worker

# Preserve our updated yarn.lock
cp yarn.lock ${KITDIR}/

# Grab the Google Fonts that would need to be fetched at build time
# See: files/patch-apps_web_components_Preservation_ReadableView.tsx
mkdir -p ${KITDIR}/fonts
fetch -o ${KITDIR}/fonts/Bentham-Regular.ttf "https://github.com/google/fonts/raw/refs/heads/main/ofl/bentham/Bentham-Regular.ttf"
fetch -o ${KITDIR}/fonts/OFL-Bentham.txt "https://github.com/google/fonts/raw/refs/heads/main/ofl/bentham/OFL.txt"
fetch -o ${KITDIR}/fonts/Caveat-Variable.ttf "https://github.com/google/fonts/raw/refs/heads/main/ofl/caveat/Caveat%5Bwght%5D.ttf"
fetch -o ${KITDIR}/fonts/OFL-Caveat.txt "https://github.com/google/fonts/raw/refs/heads/main/ofl/caveat/OFL.txt"

# Step out of the git clone
cd ${WRKDIR}

# Remove the git clone
rm -rf linkwarden

# Build the tarball
tar -czvpf ${WRKDIR}/linkwarden-freebsd-buildkit-${RELEASE}.tar.gz linkwarden-freebsd-buildkit-${RELEASE}

echo
echo "Complete! Your distfile is located at ${WRKDIR}/linkwarden-freebsd-buildkit-${RELEASE}.tar.gz"
echo "You can uncomment out the buildkit distfile in the Makefile, move it to distfiles, and run make makesum"
