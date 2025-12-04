PORTNAME=	github-copilot-cli
DISTVERSION=	0.0.366
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${NODE_HEADERS}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot CLI brings the power of the coding agent to terminal
WWW=		https://github.com/github/copilot-cli

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	binaries are installed in folders with architecture encoded in them, patches are welcome to fix this limitation

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq
BUILD_DEPENDS=	npm:www/npm \
		libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips
RUN_DEPENDS=	libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips

USES=		nodejs:run pkgconfig python:build

WRKSRC=		${WRKDIR}/copilot-${DISTVERSION}

PACKAGE_NAME=	@github/copilot

NODE_HEADERS=	node-v22.19.0-headers

JS_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}
PLIST_SUB=	JS_ARCH=${JS_ARCH}

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

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
	@if ! [ -f ${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/${NODE_HEADERS}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/pty-${dep_pty_version}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/sharp-${dep_sharp_version}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/keytar-${dep_keytar_version}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX} ]; then \
		${MKDIR} ${DD} && \
		${ECHO} "====> Fetching ${NODE_HEADERS}${EXTRACT_SUFX}" && \
		${FETCH_CMD} -q https://nodejs.org/download/release/v22.19.0/${NODE_HEADERS}${EXTRACT_SUFX} -o ${DD}/${NODE_HEADERS}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency pty" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_pty_npm_name} ${dep_pty_version} \
			${FILESDIR}/package-lock-pty.json \
			${DD}/pty-${dep_pty_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency sharp" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_sharp_npm_name} ${dep_sharp_version} \
			${FILESDIR}/package-lock-sharp.json \
			${DD}/sharp-${dep_sharp_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency keytar" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_keytar_npm_name} ${dep_keytar_version} \
			${FILESDIR}/package-lock-keytar.json \
			${DD}/keytar-${dep_keytar_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency node-addon-api" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_node_addon_api_npm_name} ${dep_node_addon_api_version} \
			${FILESDIR}/package-lock-node-addon-api.json \
			${DD}/node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching ${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi

post-extract:
	# Extract node-addon-api and install into sharp/node_modules
	# the tarball has a nested structure, so we need to move the inner directory
	@${MV} \
		${WRKDIR}/${dep_node_addon_api_npm_name}-${dep_node_addon_api_version}/node_modules/${dep_node_addon_api_npm_name} \
		${WRKDIR}/${dep_sharp_npm_name}-${dep_sharp_version}/node_modules/${dep_sharp_npm_name}/node_modules/node-addon-api

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
		${MKDIR} ${WRKSRC}/node_modules/@img/sharp-freebsd-x64 && \
		${CP} build/Release/sharp-freebsd-x64.node ${WRKSRC}/node_modules/@img/sharp-freebsd-x64/sharp.node
	@${ECHO_MSG} "====> Building keytar..."
	@cd ${WRKDIR}/keytar-${dep_keytar_version}/node_modules/${dep_keytar_npm_name} && \
		${SETENV} HOME=${WRKDIR} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${LOCALBASE} && \
		${CP} build/Release/keytar.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/prebuilds/freebsd-x64/

do-install:
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
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/index.js
	# create symlink in bin
	@${RLN} -s ${STAGEDIR}${PREFIX}/lib/node_modules/.bin/copilot ${STAGEDIR}${PREFIX}/bin/copilot
	# strip binaries
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -path "*/build/*" -name *.node | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
