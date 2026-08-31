PORTNAME=	tailwindcss4
DISTVERSION=	4.3.3
CATEGORIES=	www devel
MASTER_SITES=	LOCAL/dch/${PORTNAME}/:npm
MASTER_SITES+=	https://codeload.github.com/tailwindlabs/tailwindcss/tar.gz/v${DISTVERSION}?dummy=/:twsrc \
		LOCAL/dch/${PORTNAME}/:twsrc \
		https://codeload.github.com/parcel-bundler/lightningcss/tar.gz/v${_LCSS_VER}?dummy=/:lcsssrc \
		LOCAL/dch/${PORTNAME}/:lcsssrc \
		LOCAL/dch/${PORTNAME}/:cargo
DISTFILES=	${_NPM_ARCHIVE}:npm
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Utility-first CSS framework with npm dependencies
WWW=		https://tailwindcss.com/

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 # internal .node libraries not supported elsewhere
BUILD_DEPENDS=	corepack:www/corepack \
		npm:www/npm-node${_NODE_VERSION}
USES=		nodejs:${_NODE_VERSION},build,run python:build tar:txz

CONFLICTS_INSTALL=	tailwindcss*

_LCSS_VER=	1.32.0
_NODE_VERSION=	26
_TAILWIND_VER=	${DISTVERSION}
_WATCHER_VER=	2.5.1

_CACHE_TAG=	202608292202
_NPM_CACHE=	${WRKDIR}/cache
_NPM_ARCHIVE=	${PORTNAME}-npm-cache-${DISTVERSION}-${_CACHE_TAG}${EXTRACT_SUFX}
_CARGO_ARCHIVE=	${PORTNAME}-cargo-vendor-${DISTVERSION}-${_CACHE_TAG}${EXTRACT_SUFX}
_TW_MODULES=	${STAGEDIR}${PREFIX}/lib/node_modules/@tailwindcss/cli/node_modules
_TW_NODE_DIST=	${_TW_MODULES}/@tailwindcss/node/dist
_WATCHER_PKG=	${STAGEDIR}${PREFIX}/lib/node_modules/@parcel/watcher
_TAILWIND_SRC=	${WRKDIR}/tailwindcss-${DISTVERSION}
_LCSS_SRC=	${WRKDIR}/lightningcss-${_LCSS_VER}
_CARGO_VENDOR=	${WRKDIR}/cargo-vendor

.include <bsd.port.pre.mk>

PLIST=		${.CURDIR}/pkg-plist.${ARCH}

# oxide & lightningcss need to be built from source crates on aarch64
DISTFILES+=	tailwindcss-v${DISTVERSION}.tar.gz:twsrc \
		lightningcss-v${_LCSS_VER}.tar.gz:lcsssrc \
		${_CARGO_ARCHIVE}:cargo
BUILD_DEPENDS+=	rust>0:lang/rust

do-extract:
	@${MKDIR} ${_NPM_CACHE}
	${TAR} -xf ${_DISTDIR}/${_NPM_ARCHIVE} -C ${_NPM_CACHE}
.if ${ARCH} == aarch64
	${TAR} -xf ${_DISTDIR}/tailwindcss-v${DISTVERSION}.tar.gz -C ${WRKDIR}
	${TAR} -xf ${_DISTDIR}/lightningcss-v${_LCSS_VER}.tar.gz -C ${WRKDIR}
	${MKDIR} ${_CARGO_VENDOR}
	${TAR} -xf ${_DISTDIR}/${_CARGO_ARCHIVE} \
		-C ${_CARGO_VENDOR}
.endif

do-build:
# because nodejs is fiddly we can't build & then install
	${ECHO_CMD} build_from_source=true > ${WRKDIR}/.npmrc
	${ECHO_CMD} offline=true >> ${WRKDIR}/.npmrc
# npm's self-update check ignores offline=true; keep the build off the network
	${ECHO_CMD} update-notifier=false >> ${WRKDIR}/.npmrc
	${ECHO_CMD} python=${PYTHON_CMD} >> ${WRKDIR}/.npmrc
.if ${ARCH} == aarch64
# configure cargo for offline vendored build
	${MKDIR} ${WRKDIR}/.cargo
	${PRINTF} '[source.crates-io]\nreplace-with = "vendor"\n[source.vendor]\ndirectory = "%s"\n' \
		${_CARGO_VENDOR} > ${WRKDIR}/.cargo/config.toml
# build tailwind-oxide Rust NAPI module for freebsd-arm64
	(cd ${_TAILWIND_SRC} && \
		${SETENV} CARGO_HOME=${WRKDIR}/.cargo CARGO_NET_OFFLINE=true \
		cargo build --release -p tailwind-oxide && \
		${CP} target/release/libtailwind_oxide.so crates/node/tailwindcss-oxide.freebsd-arm64.node)
# build lightningcss Rust NAPI module for freebsd-arm64
	(cd ${_LCSS_SRC} && \
		${SETENV} CARGO_HOME=${WRKDIR}/.cargo CARGO_NET_OFFLINE=true \
		cargo build --release -p lightningcss_node)
.endif

do-install:
# scrub MAKEFLAGS/MFLAGS as it breaks node-gyp & gmake
	(cd ${WRKDIR} && \
		${SETENV} -u MAKEFLAGS -u MFLAGS \
		HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm_config_devdir=${_NPM_CACHE} npm_config_nodedir=${PREFIX} \
		npm_config_node_gyp_include_dir=${PREFIX}/include/node \
		npm install --global --no-audit --no-fund --no-prune --cache \
		${_NPM_CACHE} --prefer-offline --verbose --no-progress \
		--build-from-source --prefix=${STAGEDIR}${PREFIX} @parcel/watcher@${_WATCHER_VER} \
		@tailwindcss/cli@${_TAILWIND_VER})
# create symlinks for the CLI tools
	${LN} -sf ../lib/node_modules/@tailwindcss/cli/dist/index.mjs \
		${STAGEDIR}${PREFIX}/bin/tailwind
	${LN} -sf ../lib/node_modules/@tailwindcss/cli/dist/index.mjs \
		${STAGEDIR}${PREFIX}/bin/tailwindcss
# remove files already present in node, npm, or yarn packages
.for m in corepack npm
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/node_modules/${m}
.endfor
# remove build detritus
.for file in Release/.deps Release/obj.target Makefile binding.Makefile \
	config.gypi watcher.target.mk
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/node_modules/@parcel/watcher/build/${file}
.endfor
.if ${ARCH} == aarch64
# drop x86 binaries in favour of our source-built ones
	${RM} -rf ${_TW_MODULES}/@tailwindcss/oxide-freebsd-x64 \
		${_TW_MODULES}/lightningcss-freebsd-x64 \
		${_WATCHER_PKG}/node_modules/@parcel/watcher-freebsd-x64
	${MKDIR} ${_TW_MODULES}/@tailwindcss/oxide-freebsd-arm64
	${INSTALL_DATA} ${_TAILWIND_SRC}/crates/node/tailwindcss-oxide.freebsd-arm64.node \
		${_TW_MODULES}/@tailwindcss/oxide-freebsd-arm64/
	${PRINTF} '{"name":"@tailwindcss/oxide-freebsd-arm64","version":"%s","main":"tailwindcss-oxide.freebsd-arm64.node"}\n' \
		${_TAILWIND_VER} > ${_TW_MODULES}/@tailwindcss/oxide-freebsd-arm64/package.json
	${MKDIR} ${_TW_MODULES}/lightningcss-freebsd-arm64
	${INSTALL_DATA} ${_LCSS_SRC}/target/release/liblightningcss_node.so \
		${_TW_MODULES}/lightningcss-freebsd-arm64/lightningcss.freebsd-arm64.node
	${PRINTF} '{"name":"lightningcss-freebsd-arm64","version":"%s","main":"lightningcss.freebsd-arm64.node"}\n' \
		${_LCSS_VER} > ${_TW_MODULES}/lightningcss-freebsd-arm64/package.json
	${MKDIR} ${_WATCHER_PKG}/node_modules/@parcel/watcher-freebsd-arm64
	${INSTALL_DATA} ${_WATCHER_PKG}/build/Release/watcher.node \
		${_WATCHER_PKG}/node_modules/@parcel/watcher-freebsd-arm64/
	${PRINTF} '{"name":"@parcel/watcher-freebsd-arm64","version":"%s","main":"watcher.node"}\n' \
		${_WATCHER_VER} > ${_WATCHER_PKG}/node_modules/@parcel/watcher-freebsd-arm64/package.json
# the x86 shims we replaced shipped a LICENSE; keep one alongside ours. oxide &
# lightningcss come from the source trees we built, watcher from its own package
	${INSTALL_DATA} ${_TAILWIND_SRC}/LICENSE \
		${_TW_MODULES}/@tailwindcss/oxide-freebsd-arm64/
	${INSTALL_DATA} ${_LCSS_SRC}/LICENSE \
		${_TW_MODULES}/lightningcss-freebsd-arm64/
	${INSTALL_DATA} ${_WATCHER_PKG}/LICENSE \
		${_WATCHER_PKG}/node_modules/@parcel/watcher-freebsd-arm64/
.endif
# upstream jS plugin resolvers probe only .js/.json/.node/.ts
# Phoenix & DaisyUI reference plugins that way, so append .mjs/.cjs to the resolver
	@${REINPLACE_CMD} -e 's|extensions:\["\.js","\.json","\.node","\.ts"\]|extensions:[".js",".json",".node",".ts",".mjs",".cjs"]|g' \
		${_TW_NODE_DIST}/index.js ${_TW_NODE_DIST}/index.mjs
	@${RM} -f ${_TW_NODE_DIST}/index.js.bak ${_TW_NODE_DIST}/index.mjs.bak
# fail loudly rather than silently shipping a CLI that cannot load .mjs plugins
# the files are minified onto one line, so count occurrences, not lines
	@patched=$$(${AWK} '{ n += gsub(/"\.mjs","\.cjs"\]/, "&") } END { print n + 0 }' \
		${_TW_NODE_DIST}/index.js ${_TW_NODE_DIST}/index.mjs); \
	if [ "$$patched" != "4" ]; then \
		${ECHO_CMD} "===> resolver extensions patched at $$patched of 4 sites; upstream layout changed"; \
		exit 1; \
	fi
# strip .node files; they are shared libraries, path varies between architectures
	${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules -name "*.node" -exec \
		${STRIP_CMD} {} +

# Basic functional tests:
# oxide scanner, variant engine, lightningcss minification, TypeScript
# plugin loading (jiti + babel + the shipped tailwindcss JS API), & Phoenix

_TEST_DIR=	${WRKDIR}/twtest
# User plugins are resolved from where they live, not from the CLI, so the
# installed tailwindcss package has to be reachable for "tailwindcss/plugin"
_TEST_NODE_MODULES=	${STAGEDIR}${PREFIX}/lib/node_modules/@tailwindcss/cli/node_modules

do-test:
	${RM} -r ${_TEST_DIR}
	${MKDIR} ${_TEST_DIR} ${_TEST_DIR}/deps/daisyui/packages/bundle \
		${_TEST_DIR}/vendor
	${PRINTF} '@import "tailwindcss";\n@plugin "./plug.ts";\n@plugin "daisyui/packages/bundle/daisyui";\n@plugin "daisyui/packages/bundle/daisyui-theme";\n@plugin "./vendor/fake";\n' \
		> ${_TEST_DIR}/input.css
	${PRINTF} 'import plugin from "tailwindcss/plugin";\nexport default plugin(({ addUtilities }: any) => addUtilities({ ".zz": { zoom: "2" } }));\n' \
		> ${_TEST_DIR}/plug.ts
	${PRINTF} 'module.exports = { handler: ({ addUtilities }) => addUtilities({ ".phx-cjs": { zoom: "3" } }) };\n' \
		> ${_TEST_DIR}/deps/daisyui/packages/bundle/daisyui.js
	${PRINTF} 'export default { handler: ({ addUtilities }) => addUtilities({ ".phx-esm": { zoom: "4" } }) };\n' \
		> ${_TEST_DIR}/deps/daisyui/packages/bundle/daisyui-theme.mjs
	${PRINTF} 'export default { handler: ({ addUtilities }) => addUtilities({ ".phx-vnd": { zoom: "5" } }) };\n' \
		> ${_TEST_DIR}/vendor/fake.mjs
	${PRINTF} '<div class="flex zz underline md:grid-cols-2 hover:bg-red-500/50 phx-cjs phx-esm phx-vnd">x</div>\n' \
		> ${_TEST_DIR}/index.html
# minified output
	(cd ${_TEST_DIR} && ${SETENV} \
		NODE_PATH=${_TEST_NODE_MODULES}:${_TEST_DIR}/deps \
		${STAGEDIR}${PREFIX}/bin/tailwindcss -i input.css -o out.css --minify)
	${GREP} -q 'zoom:2' ${_TEST_DIR}/out.css
	${GREP} -q 'zoom:3' ${_TEST_DIR}/out.css
	${GREP} -q 'zoom:4' ${_TEST_DIR}/out.css
	${GREP} -q 'zoom:5' ${_TEST_DIR}/out.css
	${GREP} -q 'grid-cols-2' ${_TEST_DIR}/out.css
	${GREP} -q 'bg-red-500' ${_TEST_DIR}/out.css
# same again, unminified
	(cd ${_TEST_DIR} && ${SETENV} \
		NODE_PATH=${_TEST_NODE_MODULES}:${_TEST_DIR}/deps \
		${STAGEDIR}${PREFIX}/bin/tailwindcss -i input.css -o plain.css)
	${GREP} -q 'zoom: 2' ${_TEST_DIR}/plain.css
# canonicalize round-trips without touching the filesystem
	${SETENV} NODE_PATH=${_TEST_NODE_MODULES} \
		${STAGEDIR}${PREFIX}/bin/tailwind canonicalize flex | ${GREP} -qx flex
	@${ECHO_MSG} "===> tailwindcss functional tests passed"

# Maintainer flow, architecture independent.
# Bump _CACHE_TAG first: archives are rebuilt & must not reuse a published name
# make _tarball                     # rebuild both LOCAL distfiles & distinfo
# make _upload                      # push them to freefall

# Merge crates from tailwindcss & lightningcss repos before packaging.
_SRC_DISTFILES=	tailwindcss-v${DISTVERSION}.tar.gz:twsrc \
		lightningcss-v${_LCSS_VER}.tar.gz:lcsssrc

_tarball: build-depends
	@if [ -f ${_DISTDIR}/${_NPM_ARCHIVE} -o -f ${_DISTDIR}/${_CARGO_ARCHIVE} ]; then \
		${ECHO_CMD} "===> distfiles for _CACHE_TAG=${_CACHE_TAG} already exist;"; \
		${ECHO_CMD} "===> bump _CACHE_TAG before rebuilding them"; \
		exit 1; \
	fi
# we tar up whatever is left lying around, so start both staging areas empty
	${RM} -rf ${_NPM_CACHE} ${WRKDIR}/vendor-stage
	@${MKDIR} ${WRKDIR} \
		${_NPM_CACHE} ${_DISTDIR}
	${ECHO_CMD} python=${PYTHON_CMD} > ${WRKDIR}/.npmrc
	(cd ${WRKDIR} && \
		${SETENV} HOME=${WRKDIR} npm_config_cache=${_NPM_CACHE} \
		npm_config_devdir=${_NPM_CACHE} npm_config_nodedir=${PREFIX} \
		npm_config_node_gyp_include_dir=${PREFIX}/include/node \
		npm install --global --no-audit --no-fund --no-prune --cache \
		${_NPM_CACHE} --verbose --no-progress --prefix=${WRKDIR}/stage \
		@parcel/watcher@${_WATCHER_VER} @tailwindcss/cli@${_TAILWIND_VER})

# Normally npm only caches tarballs for the host architecture.
	(cd ${WRKDIR} && \
		${SETENV} HOME=${WRKDIR} npm cache add --cache ${_NPM_CACHE} \
		@tailwindcss/oxide-freebsd-x64@${_TAILWIND_VER} lightningcss-freebsd-x64@${_LCSS_VER} \
		@parcel/watcher-freebsd-x64@${_WATCHER_VER})
	${TAR} -caf ${_DISTDIR}/${_NPM_ARCHIVE} -C ${_NPM_CACHE} _cacache
	${CHMOD} 644 ${_DISTDIR}/${_NPM_ARCHIVE}
# cargo crates, merged from both repos
	cd ${.CURDIR} && \
		${MAKE} fetch DISTFILES="${_SRC_DISTFILES}" NO_CHECKSUM=yes
	${TAR} -xf ${_DISTDIR}/tailwindcss-v${DISTVERSION}.tar.gz -C ${WRKDIR}
	${TAR} -xf ${_DISTDIR}/lightningcss-v${_LCSS_VER}.tar.gz -C ${WRKDIR}
	${MKDIR} ${WRKDIR}/vendor-stage
# --versioned-dirs to avoid clobbering variants, --no-delete to merge the two
	(cd ${_TAILWIND_SRC} && \
		cargo vendor --versioned-dirs --no-delete ${WRKDIR}/vendor-stage)
	(cd ${_LCSS_SRC} && \
		cargo vendor --versioned-dirs --no-delete ${WRKDIR}/vendor-stage)
	${TAR} -caf ${_DISTDIR}/${_CARGO_ARCHIVE} \
		-C ${WRKDIR}/vendor-stage .
	${CHMOD} 644 ${_DISTDIR}/${_CARGO_ARCHIVE}
	cd ${.CURDIR} && ${MAKE} makesum
	@${ECHO_MSG} "===> distinfo updated; run \"make _upload\" to publish"

_upload:
	rsync -Phriv --times --chmod=F644 ${_DISTDIR}/${_NPM_ARCHIVE} ${_DISTDIR}/${_CARGO_ARCHIVE} \
		freefall.freebsd.org:public_distfiles/${PORTNAME}/

.include <bsd.port.post.mk>
