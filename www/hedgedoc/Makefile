PORTNAME=	hedgedoc
DISTVERSION=	1.9.6
PORTREVISION=	2
CATEGORIES=	www editors
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://nodejs.org/download/release/v${NODEJS_HEADERS}/:node \
		LOCAL/dch:yarn
DISTFILES+=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${_YARN_TARBALL}:yarn \
		node-v${NODEJS_HEADERS}-headers.tar.gz:node

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Web-based online collaborative editor using your preferred SQL DB
WWW=		https://hedgedoc.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: no i386 sqlite3.node file found

BUILD_DEPENDS=	git:devel/git \
		npm:www/npm-node16 \
		sqlite3:databases/sqlite3 \
		yarn:www/yarn-node16

USES=		nodejs:16,run,build python:build shebangfix
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	${WRKSRC}/bin/*

PORTSCOUT=	site:https://github.com/${PORTNAME}/${PORTNAME}/releases

USERS=		hedgedoc
GROUPS=		hedgedoc

PLIST_SUB+=	ARCH=${ARCH:S/aarch64/arm64/:S/amd64/x64/}
OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

NODEJS_HEADERS=	16.19.0

_YARNRC=	${_YARN_HOME}/yarnrc
_YARN_BIN=	${LOCALBASE}/bin/yarn
_YARN_CACHE=	${_YARN_HOME}/.cache
_YARN_CMD=	${SETENV} ${_YARN_ENV} ${_YARN_BIN} ${_YARN_FLAGS}
_YARN_CWD=	${WRKSRC}
_YARN_ENV=	HOME=${_YARN_HOME} NODE_ENV=production \
		PATH=${PATH}:/usr/local/lib/node_modules/npm/node_modules/.bin/ \
		NPM_CONFIG_TARBALL=${DISTDIR}/node-v${NODEJS_HEADERS}-headers.tar.gz \
		PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true PYTHON=${PYTHON_CMD}
_YARN_FLAGS=	--skip-integrity-check --noninteractive --no-node-version-check \
		--no-default-rc --cwd ${_YARN_CWD} --cache-folder \
		${_YARN_CACHE} --use-yarnrc ${_YARNRC} --no-progress --silent \
		--frozen-lockfile
_YARN_HOME=	${WRKDIR}/yarn
_YARN_MIRROR=	${_YARN_HOME}/mirror
_YARN_TARBALL=	${DISTNAME}-yarn-cache.txz

# helper creates a tarball that pre-populates the yarn cache
# upload to your freefall public_distfiles/ location
tarball: patch
	@${RM} -r ${_YARN_MIRROR}
	(cd ${WRKSRC} && \
		${_YARN_CMD} --ignore-scripts)
	(cd ${WRKDIR} && \
		${TAR} cvaf ${_YARN_TARBALL} yarn/mirror)

rsync: tarball
	@rsync -Phivl --inplace ${WRKDIR}/${_YARN_TARBALL} freefall:public_distfiles/

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} \
		${WRKSRC}

post-patch:
	@${MKDIR} ${_YARN_MIRROR}
	@${ECHO_CMD} 'yarn-offline-mirror "${_YARN_MIRROR}"' > ${_YARNRC}

do-build:
	(cd ${WRKSRC} && \
		${_YARN_CMD} --offline install)
# remove temporary build garbage and unnecessary runtime files
	(cd ${WRKSRC} && \
		${RM} -r .babelrc .editorconfig .eslint* .mailmap .remarkrc \
		.yarn* node_modules/*/deps node_modules/*/man node_modules/.bin \
		node_modules/.yarn* node_modules/@mapbox/node-pre-gyp/node_modules/.bin \
		node_modules/bufferutil/binding.gyp node_modules/bufferutil/build/Makefile \
		node_modules/bufferutil/build/Release/.deps node_modules/bufferutil/build/Release/obj.target \
		node_modules/bufferutil/build/config.gypi node_modules/bufferutil/build/node_gyp_bins \
		node_modules/bufferutil/node_modules node_modules/bufferutil/prebuilds \
		node_modules/bufferutil/src node_modules/node-addon-api \
		node_modules/node-gyp* node_modules/sqlite3/build-tmp-napi-v6 \
		node_modules/sqlite3/deps node_modules/sqlite3/node-addon-api \
		node_modules/sqlite3/node_modules node_modules/sqlite3/src \
		node_modules/utf-8-validate/binding.gyp node_modules/utf-8-validate/build/Makefile \
		node_modules/utf-8-validate/build/Release/.deps node_modules/utf-8-validate/prebuilds/ \
		node_modules/utf-8-validate/build/Release/obj.target \
		node_modules/utf-8-validate/build/config.gypi node_modules/utf-8-validate/build/node_gyp_bins \
		node_modules/utf-8-validate/node_modules node_modules/utf-8-validate/src \
		renovate.json test webpack.*)
	${FIND} -E ${WRKSRC}/node_modules -regex '.+\.(Makefile|mk|\.d|targ|info|gyp)$$' \
		-print -delete
	${FIND} ${WRKSRC}/node_modules -name '*.node' -print -exec ${STRIP_CMD} \
		{} +
	${MV} ${WRKSRC}/docs \
		${WRKDIR}/docs

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/bin \
		${STAGEDIR}/var/db/hedgedoc/uploads
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	(cd ${WRKSRC} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX}/libexec/${PORTNAME})
	(cd ${WRKDIR}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/config.json.example \
		${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
