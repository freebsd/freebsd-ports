PORTNAME=	openclaw
DISTVERSION=	2026.4.29
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-ai-gateway
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-channel AI gateway with extensible messaging integrations
WWW=		https://github.com/openclaw/openclaw

LICENSE=	MIT

FETCH_DEPENDS=	curl:ftp/curl \
		jq:textproc/jq \
		npm:www/npm \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=	cmake:devel/cmake \
		npm:www/npm \
		vips>=8.17.2:graphics/vips
RUN_DEPENDS=	vips>=8.17.2:graphics/vips

USES=		nodejs:run pkgconfig python:build
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		EXTEND_AI_TIMEOUT EXTEND_TYPING_TTL_TIMEOUT SKILL_DEPENDENCIES
OPTIONS_DEFAULT=	EXTEND_AI_TIMEOUT EXTEND_TYPING_TTL_TIMEOUT SKILL_DEPENDENCIES

EXTEND_AI_TIMEOUT_DESC=		Set AI endpoint request timeout to 24 hours for slow models
EXTEND_TYPING_TTL_TIMEOUT_DESC=	Set typing indicator TTL to 5 hours for slow LLM responses
SKILL_DEPENDENCIES_DESC=	Install dependencies for all supported skills

# SKILL_DEPENDENCIES installs a lot of dependencies, but they are referenced in the SKILL.md files and can be used any time given the right request,
# therefore we keep it ON by default. Users can disable it if they want to save space and don't mind manually installing dependencies for skills they want to use.
SKILL_DEPENDENCIES_RUN_DEPENDS=	blogwatcher:misc/blogwatcher \
				blu:audio/blucli \
				camsnap:misc/camsnap \
				clawhub:misc/clawhub \
				curl:ftp/curl \
				eightctl:misc/eightctl \
				ffmpeg:multimedia/ffmpeg \
				gh:devel/gh \
				git:devel/git \
				goplaces:misc/goplaces \
				grizzly:misc/grizzly \
				jq:textproc/jq \
				memo:misc/memo \
				nano-pdf:textproc/nano-pdf \
				op:security/op \
				rg:textproc/ripgrep \
				sag:audio/sag \
				songsee:audio/songsee \
				sonos:misc/sonoscli \
				spotify_player:audio/spotify-player \
				tmux:sysutils/tmux \
				wacli:misc/wacli \
				whisper:misc/py-openai-whisper

PACKAGE_NAME=	openclaw

NODE_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/:S/i386/ia32/:S/powerpc64le/ppc64le/:S/powerpc64/ppc64/:C/armv[67]/arm/} # modeled after electron.mk
PLIST_SUB=	NODE_ARCH=${NODE_ARCH}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

# Binary NodeJS modules that require building for the target platform:
# - sharp: Fast image processing library for reading, manipulating, and encoding images
# - koffi: C foreign function interface (FFI) for calling native libraries
# - node-addon-api: Helper library for building native Node.js modules

dep_sharp_npm_name=		sharp
dep_sharp_version=		0.34.5
dep_koffi_npm_name=		koffi
dep_koffi_version=		2.16.1
dep_node_addon_api_npm_name=	node-addon-api
dep_node_addon_api_version=	8.5.0

DISTFILES+=	sharp-${dep_sharp_version}${EXTRACT_SUFX} \
		koffi-${dep_koffi_version}${EXTRACT_SUFX} \
		node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX}

DD=	${DISTDIR}/${DIST_SUBDIR}

do-fetch:
	@${MKDIR} ${DD}
	@if ! [ -f ${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} npm_config_force=true ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi
	@if ! [ -f ${DD}/sharp-${dep_sharp_version}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_sharp_npm_name} ${dep_sharp_version} \
			${FILESDIR}/package-lock-sharp.json \
			${DD}/sharp-${dep_sharp_version}${EXTRACT_SUFX}; \
	fi
	@if ! [ -f ${DD}/koffi-${dep_koffi_version}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_koffi_npm_name} ${dep_koffi_version} \
			${FILESDIR}/package-lock-koffi.json \
			${DD}/koffi-${dep_koffi_version}${EXTRACT_SUFX}; \
	fi
	@if ! [ -f ${DD}/node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${dep_node_addon_api_npm_name} ${dep_node_addon_api_version} \
			${FILESDIR}/package-lock-node-addon-api.json \
			${DD}/node-addon-api-${dep_node_addon_api_version}${EXTRACT_SUFX}; \
	fi

post-extract:
	# Move node-addon-api into sharp's node_modules for building
	@${MV} \
		${WRKDIR}/${dep_node_addon_api_npm_name}-${dep_node_addon_api_version}/node_modules/${dep_node_addon_api_npm_name} \
		${WRKDIR}/${dep_sharp_npm_name}-${dep_sharp_version}/node_modules/${dep_sharp_npm_name}/node_modules/node-addon-api

do-build:
	@${ECHO_MSG} "====> Building sharp for FreeBSD..."
	@cd ${WRKDIR}/sharp-${dep_sharp_version}/node_modules/${dep_sharp_npm_name}/src && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} CXXFLAGS="-I${LOCALBASE}/include" \
			node-gyp configure build --nodedir=${LOCALBASE} && \
		${MKDIR} ${WRKSRC}/node_modules/openclaw/node_modules/@img/sharp-freebsd-${NODE_ARCH} && \
		${CP} build/Release/sharp-freebsd-${NODE_ARCH}.node \
			${WRKSRC}/node_modules/openclaw/node_modules/@img/sharp-freebsd-${NODE_ARCH}/sharp.node
	@${ECHO_MSG} "====> Building koffi for FreeBSD..."
	@cd ${WRKDIR}/${dep_koffi_npm_name}-${dep_koffi_version}/node_modules/${dep_koffi_npm_name} && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} \
			node src/cnoke/cnoke.js build -P . -D src/koffi && \
		${MKDIR} ${WRKSRC}/node_modules/openclaw/node_modules/koffi/build/koffi/freebsd_${NODE_ARCH} && \
		${CP} $$(${FIND} ${WRKDIR}/${dep_koffi_npm_name}-${dep_koffi_version}/node_modules/${dep_koffi_npm_name}/build/koffi/freebsd_${NODE_ARCH} -name "koffi.node" -type f | ${HEAD} -1) \
			${WRKSRC}/node_modules/openclaw/node_modules/koffi/build/koffi/freebsd_${NODE_ARCH}/koffi.node

do-install:
	# install node_modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/lib
	# remove *.node binaries for non-FreeBSD platforms
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules \
		-name "*.node" ! -path "*freebsd*" -delete
	# update shebang
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/openclaw.mjs
	# set exec bit
	@${CHMOD} +x \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/openclaw.mjs
	# create wrapper script
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/openclaw
	@${ECHO_CMD} 'exec ${PREFIX}/lib/node_modules/${PACKAGE_NAME}/openclaw.mjs "$$@"' \
		>> ${STAGEDIR}${PREFIX}/bin/openclaw
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/openclaw

post-patch-EXTEND_AI_TIMEOUT-on:
	@${FIND} ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist -name "*.js" \
		-exec ${GREP} -q "DEFAULT_GUARDED_HTTP_TIMEOUT_MS = 6e4" {} \; \
		-exec ${REINPLACE_CMD} \
			-e 's/DEFAULT_GUARDED_HTTP_TIMEOUT_MS = 6e4/DEFAULT_GUARDED_HTTP_TIMEOUT_MS = 86400000/' {} \;
	@${FIND} ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist -name "*.js" \
		-exec ${GREP} -q "DEFAULT_LLM_IDLE_TIMEOUT_MS = 120 \* 1e3" {} \; \
		-exec ${REINPLACE_CMD} \
			-e 's/DEFAULT_LLM_IDLE_TIMEOUT_MS = 120 \* 1e3/DEFAULT_LLM_IDLE_TIMEOUT_MS = 0/' {} \;
	@${FIND} ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist -name "*.js" \
		-exec ${GREP} -q "new Agent(withHttp1OnlyDispatcherOptions(options))" {} \; \
		-exec ${REINPLACE_CMD} \
			-e 's/new Agent(withHttp1OnlyDispatcherOptions(options))/new Agent({ ...withHttp1OnlyDispatcherOptions(options), headersTimeout: 86400000, bodyTimeout: 86400000 })/' {} \;

post-patch-EXTEND_TYPING_TTL_TIMEOUT-on:
	@${FIND} ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist -name "*.js" \
		-exec ${GREP} -q "typingTtlMs = 2 \* 6e4" {} \; \
		-exec ${REINPLACE_CMD} \
			-e 's/typingTtlMs = 2 \* 6e4/typingTtlMs = 18000000/' {} \;

post-install:
	# remove empty directories in STAGEDIR
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules -type d -empty -delete
	# remove lancedb plugin to ensure it is never enabled at runtime
	# not to be removed until https://github.com/lancedb/lancedb/issues/3338 is resolved and the plugin can be safely re-enabled
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/extensions/memory-lancedb
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/docs/plugins/memory-lancedb.md
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules -type d -empty -delete
	# autoplist: 32k+ files with randomizing strings in names warrant autoplist
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
