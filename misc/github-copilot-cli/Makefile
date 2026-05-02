PORTNAME=	github-copilot-cli
DISTVERSION=	1.0.35-6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-x # -x is to see if it would fix checksum errors

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot CLI brings the power of the coding agent to terminal
WWW=		https://github.com/github/copilot-cli

FLAVORS=	script binary
FLAVOR?=	${FLAVORS:[1]}
script_PKGNAMESUFFIX=
binary_PKGNAMESUFFIX=	-bin
binary_COMMENT=	GitHub Copilot CLI - standalone binary (no npm dependencies)
binary_PLIST=	${.CURDIR}/pkg-plist.binary

FETCH_DEPENDS=	flock:sysutils/flock \
		npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

WRKSRC=		${WRKDIR}/copilot-${DISTVERSION}

PACKAGE_NAME=	@github/copilot

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

FETCH_LOCKFILE=	${DD}/fetch.lock

.if ${FLAVOR} == script
DISTFILES+=	${NODE_HEADERS}${EXTRACT_SUFX}

BUILD_DEPENDS=	npm:www/npm \
		libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips
RUN_DEPENDS=	libsecret>0:security/libsecret \
		rg:textproc/ripgrep \
		vips>=8.17.2:graphics/vips

USES=		nodejs:run pkgconfig python:build

.elif ${FLAVOR} == binary
BROKEN=		See if the binary flavor somehow causes fetch failures
DISTFILES+=	${NODE_HEADERS}${EXTRACT_SUFX}

BUILD_DEPENDS=	npm:www/npm \
		libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips

# The node binary is bundled inside the port binary; its shared libraries
# must still be present at runtime so they are listed here.
LIB_DEPENDS=	libada.so:devel/libada \
		libbrotlidec.so:archivers/brotli \
		libcares.so:dns/c-ares \
		libgtest.so:devel/googletest \
		libhdr_histogram.so:graphics/hdr_histogram \
		libicui18n.so:devel/icu \
		libllhttp.so:www/llhttp \
		libmerve.so:devel/merve \
		libnbytes.so:www/nbytes \
		libnghttp2.so:www/libnghttp2 \
		libnghttp3.so:www/libnghttp3 \
		libngtcp2.so:net/libngtcp2 \
		libsimdjson.so:devel/simdjson \
		libsimdutf.so:converters/simdutf \
		libsqlite3.so:databases/sqlite3 \
		libuv.so:devel/libuv \
		libuvwasi.so:devel/uvwasi \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips

USES=		nodejs:build pkgconfig python:build

.endif	# FLAVOR

NODE_HEADERS=	node-v22.19.0-headers

NODE_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/:S/i386/ia32/:S/powerpc64le/ppc64le/:S/powerpc64/ppc64/:C/armv[67]/arm/} # modeled after electron.mk
PLIST_SUB=	NODE_ARCH=${NODE_ARCH}

DEP_MODULES=			pty sharp keytar node_addon_api
dep_pty_npm_name=		@devm33/node-pty
dep_pty_version=		1.0.9
dep_sharp_npm_name=		sharp
dep_sharp_version=		0.34.4
dep_keytar_npm_name=		keytar
dep_keytar_version=		7.9.0
dep_node_addon_api_npm_name=	node-addon-api
dep_node_addon_api_version=	8.5.0

.for dep in ${DEP_MODULES}
DISTFILES+=	${dep:S/_/-/g}-${dep_${dep}_version}${EXTRACT_SUFX}
.endfor

do-fetch:
	@${MKDIR} ${DD}
	@exec 9>${FETCH_LOCKFILE} && flock -x 9 && \
	if ! [ -f ${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching ${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi && \
	if ! [ -f ${DD}/${NODE_HEADERS}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching ${NODE_HEADERS}${EXTRACT_SUFX}" && \
		${FETCH_CMD} -q https://nodejs.org/download/release/v22.19.0/${NODE_HEADERS}${EXTRACT_SUFX} \
			-o ${DD}/${NODE_HEADERS}${EXTRACT_SUFX}; \
	fi && \
	if ! [ -f ${DD}/pty-${dep_pty_version}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching dependency pty" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_pty_npm_name} ${dep_pty_version} \
			${FILESDIR}/package-lock-pty.json \
			${DD}/pty-${dep_pty_version}${EXTRACT_SUFX}; \
	fi && \
	if ! [ -f ${DD}/sharp-${dep_sharp_version}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching dependency sharp" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_sharp_npm_name} ${dep_sharp_version} \
			${FILESDIR}/package-lock-sharp.json \
			${DD}/sharp-${dep_sharp_version}${EXTRACT_SUFX}; \
	fi && \
	if ! [ -f ${DD}/keytar-${dep_keytar_version}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching dependency keytar" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_keytar_npm_name} ${dep_keytar_version} \
			${FILESDIR}/package-lock-keytar.json \
			${DD}/keytar-${dep_keytar_version}${EXTRACT_SUFX}; \
	fi && \
	if ! [ -f ${DD}/node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching dependency node-addon-api" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_node_addon_api_npm_name} ${dep_node_addon_api_version} \
			${FILESDIR}/package-lock-node-addon-api.json \
			${DD}/node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX}; \
	fi

post-extract:
	# Extract node-addon-api and install into sharp/node_modules
	# the tarball has a nested structure, so we need to move the inner directory
	@${MV} \
		${WRKDIR}/${dep_node_addon_api_npm_name}-${dep_node_addon_api_version}/node_modules/${dep_node_addon_api_npm_name} \
		${WRKDIR}/${dep_sharp_npm_name}-${dep_sharp_version}/node_modules/${dep_sharp_npm_name}/node_modules/node-addon-api

post-patch:
	# set version
	${REINPLACE_CMD} -i '' \
		-e 's|qg.default.createElement(U,{color:e.MUTED},"v",t)|qg.default.createElement(U,{color:e.MUTED},"v","${PORTVERSION}")|g' \
		${WRKSRC}/node_modules/@github/copilot/index.js

do-build:
	# Create directory for FreeBSD prebuilds
	@${MKDIR} ${WRKSRC}/node_modules/${PACKAGE_NAME}/prebuilds/freebsd-x64
	@${ECHO_MSG} "====> Building pty..."
	@cd ${WRKDIR}/node-pty-${dep_pty_version}/node_modules/${dep_pty_npm_name} && \
		${SETENV} HOME=${WRKDIR} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${LOCALBASE} && \
		${CP} build/Release/pty.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/prebuilds/freebsd-x64/
	@${ECHO_MSG} "====> Building sharp..."
	@cd ${WRKDIR}/sharp-${dep_sharp_version}/node_modules/${dep_sharp_npm_name}/src && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} CXXFLAGS="-I${LOCALBASE}/include" \
			node-gyp configure build --nodedir=${WRKDIR}/node-v22.19.0 && \
		${MKDIR} ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/@img/sharp-freebsd-${NODE_ARCH} && \
		${CP} build/Release/sharp-freebsd-${NODE_ARCH}.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/@img/sharp-freebsd-${NODE_ARCH}/sharp.node
	@${ECHO_MSG} "====> Building keytar..."
	@cd ${WRKDIR}/keytar-${dep_keytar_version}/node_modules/${dep_keytar_npm_name} && \
		${SETENV} HOME=${WRKDIR} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${LOCALBASE} && \
		${CP} build/Release/keytar.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/prebuilds/freebsd-x64/
.if ${FLAVOR} == binary
	@${ECHO_MSG} "====> Creating copilot bundle (includes node runtime)..."
	# Embed the node runtime so it runs without a system node installation
	@${CP} ${LOCALBASE}/bin/node ${WRKSRC}/node_modules/${PACKAGE_NAME}/node
	@cd ${WRKSRC}/node_modules/${PACKAGE_NAME} && \
		${TAR} --exclude=./ripgrep --exclude=./sharp \
			--exclude=./changelog.json --exclude=./npm-loader.js.orig \
			-cJf ${WRKSRC}/copilot_bundle.txz .
	@${ECHO_MSG} "====> Building copilot launcher..."
	@${PRINTF} '\t.global _binary_copilot_bundle_txz_start\n\t.global _binary_copilot_bundle_txz_end\n_binary_copilot_bundle_txz_start:\n\t.incbin "%s"\n_binary_copilot_bundle_txz_end:\n' \
		"${WRKSRC}/copilot_bundle.txz" > ${WRKSRC}/blob.s
	@${CC} -c ${WRKSRC}/blob.s -o ${WRKSRC}/blob.o
	@${CC} ${CFLAGS} \
		-DPREFIX='"${PREFIX}"' \
		-DPORTVERSION='"${PORTVERSION}"' \
		-c ${FILESDIR}/launcher.c -o ${WRKSRC}/launcher.o
	@${CC} ${LDFLAGS} -o ${WRKSRC}/copilot ${WRKSRC}/launcher.o ${WRKSRC}/blob.o
	@${STRIP_CMD} ${WRKSRC}/copilot
.endif	# FLAVOR == binary

do-install:
.if ${FLAVOR} == script
	# install files
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	# remove *.node files for other OSes
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -name "*\\.node" | \
		${GREP} -v freebsd | \
		${XARGS} ${RM}
	# remove files for other OSes
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -name "*linux*" | ${XARGS} ${RM} -r
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -name "*win32*" | ${XARGS} ${RM} -r
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -name "*darwin*" | ${XARGS} ${RM} -r
	# remove unnecessary files
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "*package*.json" -delete
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "README.md" -delete
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "LICENSE.md" -delete
	# update shebang to use system node
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/index.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/npm-loader.js
	# create symlink in bin
	@${RLN} -s ${STAGEDIR}${PREFIX}/lib/node_modules/.bin/copilot ${STAGEDIR}${PREFIX}/bin/copilot
	# strip binaries
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -path "*/build/*" -name *.node | ${XARGS} ${STRIP_CMD}
.elif ${FLAVOR} == binary
	${INSTALL_PROGRAM} ${WRKSRC}/copilot ${STAGEDIR}${PREFIX}/bin/copilot
.endif	# FLAVOR

.include <bsd.port.mk>
