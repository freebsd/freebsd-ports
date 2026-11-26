PORTNAME=	paseo
.include "${.CURDIR}/Makefile.common"
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Agentic development environment (daemon and CLI)
WWW=		https://paseo.sh/ \
		https://github.com/getpaseo/paseo

# node_modules/@anthropic-ai/claude-agent-sdk is proprietary.
LICENSE=	APACHE20 Proprietary
LICENSE_COMB=	multi
LICENSE_NAME_Proprietary=	Anthropic Proprietary License
LICENSE_FILE_APACHE20=	${WRKSRC}/node_modules/@getpaseo/cli/LICENSE
LICENSE_FILE_Proprietary=	${WRKSRC}/node_modules/@anthropic-ai/claude-agent-sdk/LICENSE.md
LICENSE_PERMS_Proprietary=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	esbuild, which compiles plugins, has FreeBSD binaries only for aarch64 and amd64

RUN_DEPENDS=	git:devel/git

USES=		gmake nodejs:build,run npm:npm,build python:build
USE_RC_SUBR=	paseo

NPM_PREFETCH_ARCHS=	${ONLY_FOR_ARCHS}
NPM_FETCH_FLAGS+=	--os=freebsd --cpu=${NPM_NODEJS_ARCH}

APPDIR=		${PREFIX}/lib/${PORTNAME}
SUB_FILES=	paseo-wrapper pkg-message
SUB_LIST=	APPDIR=${APPDIR}
PLIST_FILES=	bin/paseo

OPTIONS_DEFINE=		ZSH
OPTIONS_DEFAULT=	ZSH

ZSH_PLIST_FILES=	share/zsh/site-functions/_paseo

# node-pty doesn't ship FreeBSD prebuilt addons.  Build it.
NODE_GYP=	${LOCALBASE}/lib/node_modules/npm/node_modules/node-gyp/bin/node-gyp.js

# Dictation needs sherpa-onnx, which has no FreeBSD build; turn it off by
# default.
post-patch:
	@${REINPLACE_CMD} -e 's|^\(export const DICTATION_ENABLED_BY_DEFAULT = \)true;|\1false;|' \
		${WRKSRC}/node_modules/@getpaseo/server/dist/server/server/speech/speech-config-resolver.js

do-build:
	@cd ${WRKSRC}/node_modules/node-pty && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		PYTHON=${PYTHON_CMD} JOBS=${MAKE_JOBS_NUMBER} \
		${LOCALBASE}/bin/node ${NODE_GYP} rebuild --nodedir=${LOCALBASE}

do-install:
	# Only node-pty's lib/ and build/Release/pty.node are used at run time.
	# msgpackr-extract is optional and has no FreeBSD build.
	@cd ${WRKSRC}/node_modules && ${RM} -r .bin msgpackr-extract \
		node-pty/binding.gyp node-pty/node-addon-api node-pty/prebuilds \
		node-pty/scripts node-pty/src node-pty/third_party pngjs/coverage
	@${FIND} ${WRKSRC}/node_modules/node-pty/build -mindepth 1 \
		-not -path '*/build/Release' -not -path '*/build/Release/pty.node' \
		-delete
	@${FIND} ${WRKSRC}/node_modules \( -name '*.orig' -o -name '*.bak' \) \
		-delete
	@${MKDIR} ${STAGEDIR}${APPDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} node_modules ${STAGEDIR}${APPDIR}
	${INSTALL_LIB} ${WRKSRC}/node_modules/node-pty/build/Release/pty.node \
		${STAGEDIR}${APPDIR}/node_modules/node-pty/build/Release
	# COPYTREE_SHARE drops the execute bit that esbuild needs.
	${INSTALL_PROGRAM} \
		${WRKSRC}/node_modules/@esbuild/freebsd-${NPM_NODEJS_ARCH}/bin/esbuild \
		${STAGEDIR}${APPDIR}/node_modules/@esbuild/freebsd-${NPM_NODEJS_ARCH}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/paseo-wrapper ${STAGEDIR}${PREFIX}/bin/paseo

# Generate the zsh completion from the CLI's commander definition.
post-build-ZSH-on:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/node ${FILESDIR}/gen-zsh-completion.mjs \
		node_modules/@getpaseo/cli/dist > ${WRKDIR}/_paseo

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/_paseo ${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s ${APPDIR:S,^${PREFIX}/,,} -not -type d >> ${TMPPLIST}

.include <bsd.port.mk>
