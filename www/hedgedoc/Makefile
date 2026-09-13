PORTNAME=	hedgedoc
DISTVERSION=	1.12.0
CATEGORIES=	www editors
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/ \
		LOCAL/dbaio:yarn
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${_YARN_TARBALL}:yarn

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Web-based online collaborative editor using your preferred SQL DB
WWW=		https://hedgedoc.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: no i386 sqlite3.node file found

BUILD_DEPENDS=	${LOCALBASE}/include/uv.h:devel/libuv \
		${PY_SETUPTOOLS}

USES=		gmake localbase nodejs:24,build,run python:build shebangfix
USE_RC_SUBR=	${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

SHEBANG_FILES=	${WRKSRC}/bin/*

PORTSCOUT=	site:https://github.com/${PORTNAME}/${PORTNAME}/releases

USERS=		hedgedoc
GROUPS=		hedgedoc

PLIST_SUB+=	ARCH=${ARCH:S/aarch64/arm64/:S/amd64/x64/}
OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

# Upstream ships the Yarn release it expects in .yarn/releases; run that one
# rather than www/yarn, which is Yarn 1 and cannot read a v8 lockfile.
_YARN_VERSION=	4.13.0
_YARN=		${WRKSRC}/.yarn/releases/yarn-${_YARN_VERSION}.cjs
_YARN_CACHE=	${WRKDIR}/yarn-cache
_YARN_TARBALL=	${DISTNAME}-yarn-offline-cache.txz
_YARN_ENV=	HOME=${WRKDIR} PATH=${PATH} YARN_CACHE_FOLDER=${_YARN_CACHE} \
		YARN_ENABLE_GLOBAL_CACHE=false YARN_ENABLE_TELEMETRY=0 \
		YARN_ENABLE_COLORS=false npm_config_nodedir=${LOCALBASE} \
		CPPFLAGS="${CPPFLAGS}" PYTHON=${PYTHON_CMD} \
		PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true
_YARN_CMD=	${SETENV} ${_YARN_ENV} YARN_ENABLE_NETWORK=false \
		${LOCALBASE}/bin/node ${_YARN}

yarn-cache: patch
	@${RM} -r ${_YARN_CACHE}
	(cd ${WRKSRC} && \
		${SETENV} ${_YARN_ENV} YARN_ENABLE_NETWORK=true \
		${LOCALBASE}/bin/node ${_YARN} install --mode=skip-build)
	(cd ${WRKDIR} && \
		${TAR} cvaf ${_YARN_TARBALL} yarn-cache)

rsync: yarn-cache
	@rsync -Phivl --inplace ${WRKDIR}/${_YARN_TARBALL} freefall:public_distfiles/

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-build:
	(cd ${WRKSRC} && \
		${_YARN_CMD} install --immutable --immutable-cache --inline-builds)
	(cd ${WRKSRC} && \
		${RM} -r .babelrc .editorconfig .eslint* .mailmap .remarkrc \
		.yarn .yarnrc.yml node_modules/*/deps node_modules/*/man \
		node_modules/.bin node_modules/.yarn* \
		node_modules/@mapbox/node-pre-gyp/node_modules/.bin \
		node_modules/bufferutil/binding.gyp node_modules/bufferutil/build/Makefile \
		node_modules/bufferutil/build/Release/.deps node_modules/bufferutil/build/Release/obj.target \
		node_modules/bufferutil/build/config.gypi node_modules/bufferutil/build/node_gyp_bins \
		node_modules/bufferutil/node_modules node_modules/bufferutil/prebuilds \
		node_modules/bufferutil/src node_modules/node-addon-api \
		node_modules/node-gyp* node_modules/sqlite3/build-tmp-napi-v6 \
		node_modules/sqlite3/build/Makefile node_modules/sqlite3/build/config.gypi \
		node_modules/sqlite3/build/deps node_modules/sqlite3/build/node_gyp_bins \
		node_modules/sqlite3/build/Release/.deps node_modules/sqlite3/build/Release/obj \
		node_modules/sqlite3/build/Release/obj.target \
		node_modules/sqlite3/build/Release/node-addon-api \
		node_modules/sqlite3/build/Release/*.a \
		node_modules/sqlite3/deps node_modules/sqlite3/node-addon-api \
		node_modules/sqlite3/node_modules node_modules/sqlite3/src \
		node_modules/utf-8-validate/binding.gyp node_modules/utf-8-validate/build/Makefile \
		node_modules/utf-8-validate/build/Release/.deps node_modules/utf-8-validate/prebuilds \
		node_modules/utf-8-validate/build/Release/obj.target \
		node_modules/utf-8-validate/build/config.gypi node_modules/utf-8-validate/build/node_gyp_bins \
		node_modules/utf-8-validate/node_modules node_modules/utf-8-validate/src \
		renovate.json test webpack.*)
	${FIND} -E ${WRKSRC}/node_modules -regex '.+\.(Makefile|mk|\.d|targ|info|gyp)$$' \
		-print -delete
	${FIND} ${WRKSRC}/node_modules -name .DS_Store -print -delete
	${RM} -r ${WRKSRC}/node_modules/bare-*/prebuilds
	${FIND} ${WRKSRC}/node_modules -name '*.node' -print -exec ${STRIP_CMD} \
		{} +
	${MV} ${WRKSRC}/docs ${WRKDIR}/docs

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
