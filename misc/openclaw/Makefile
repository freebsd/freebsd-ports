PORTNAME=	openclaw
DISTVERSION=	2026.9.4
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-ai-gateway
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-channel AI gateway with extensible messaging integrations
WWW=		https://github.com/openclaw/openclaw

LICENSE=	MIT

# The npm fetch step also needs the release's supported Node runtime.
FETCH_DEPENDS=	curl:ftp/curl \
		jq:textproc/jq \
		node24>=24.16.0:www/node24 \
		npm-node24>=0:www/npm-node24 \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=	node24>=24.16.0:www/node24 \
		npm-node24>=0:www/npm-node24
RUN_DEPENDS=	node24>=24.16.0:www/node24

USES=		cmake:indirect gmake python:build
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		SKILL_DEPENDENCIES
OPTIONS_DEFAULT=	SKILL_DEPENDENCIES

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

DD=	${DISTDIR}/${DIST_SUBDIR}

do-fetch:
	@${MKDIR} ${DD}
	@if ! [ -f ${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} npm_config_force=true ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi

do-build:
	# Remove supplied addons so the normal loader uses our source builds.
	@${FIND} ${WRKSRC}/node_modules/${PACKAGE_NAME} \
		-type f -name "*.node" -delete
	# Keep CMake intermediates outside the package copied to STAGEDIR.
	@cd ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/koffi && \
		${SETENV} HOME=${WRKDIR} CMAKE_BUILD_PARALLEL_LEVEL=${MAKE_JOBS_NUMBER} \
			node cnoke.cjs -P . -D src/koffi -O ${WRKDIR}/koffi-build --release && \
		${MKDIR} build/koffi/freebsd_${NODE_ARCH} && \
		${CP} ${WRKDIR}/koffi-build/koffi.node build/koffi/freebsd_${NODE_ARCH}/koffi.node
	@cd ${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules/tree-sitter-bash && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} \
			node ${LOCALBASE}/lib/node_modules/npm/node_modules/node-gyp/bin/node-gyp.js \
			configure build --nodedir=${LOCALBASE} && \
		${MKDIR} prebuilds/freebsd-${NODE_ARCH} && \
		${MV} build/Release/tree_sitter_bash_binding.node \
			prebuilds/freebsd-${NODE_ARCH}/tree-sitter-bash.node && \
		${RM} -r build

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

post-install:
	# remove empty directories in STAGEDIR
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules -type d -empty -delete
	# autoplist: 32k+ files with randomizing strings in names warrant autoplist
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
