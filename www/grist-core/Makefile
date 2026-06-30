PORTNAME=	grist-core
PORTVERSION=	1.7.16
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	LOCAL/mfechner/${PORTNAME}/:yarncache
DISTFILES=	${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX}:yarncache

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Modern relational spreadsheet running in browser, Community Edition
WWW=		https://github.com/gristlabs/grist-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Yarn cache only for amd64 generated

MY_DEPENDS=	yarn${NODEJS_SUFFIX}>=1.10.0:www/yarn${NODEJS_SUFFIX} \
		bash:shells/bash
BUILD_DEPENDS=	${MY_DEPENDS} \
		libuv>=1.34.0:devel/libuv
RUN_DEPENDS=	${MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.2.2:devel/py-pip@${PY_FLAVOR}

USES=		compiler:c++17-lang gmake nodejs python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	gristlabs
USE_RC_SUBR=	grist
SHEBANG_FILES=	sandbox/gvisor/run.py

# Required for node-gyp to work
MAKE_ENV+=	npm_config_build_from_source=true
MAKE_ENV+=	npm_config_nodedir=${PREFIX}
MAKE_ENV+=	npm_config_node_gyp=${LOCALBASE}/bin/node-gyp
MAKE_ENV+=	PYTHON=${PYTHON_CMD}
MAKE_ENV+=	COREPACK_ENABLE_DOWNLOAD_PROMPT=0
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

WWWDIR=		${PREFIX}/www/grist-core
SUB_FILES=	pkg-message
SUB_LIST=	GRIST_USER=${USERS} \
		GRIST_GROUP=${GROUPS} \
		PYTHON_CMD="${PYTHON_CMD}"
USERS=		grist
GROUPS=		grist

post-patch:
	# setup yarnrc for offline node_modules installation
	@${ECHO_CMD} 'yarn-offline-mirror "${WRKDIR}/yarn-offline-cache"' >> ${WRKSRC}/.yarnrc

pre-build:
	#(cd ${WORKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} && yarn config set python /usr/local/bin/python3.11)
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} echo community > grist-edition
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} PUPPETEER_SKIP_DOWNLOAD=true npm_config_build_from_source=true yarn install --offline

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn build:prod

do-install:
	# Rebuild production-only node_modules
	${RM} -r ${WRKSRC}/node_modules
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} PUPPETEER_SKIP_DOWNLOAD=true npm_config_build_from_source=true yarn install --offline --prod

	# Cleanup broken sqlite3 build leftovers
	${RM} -r ${WRKSRC}/node_modules/@gristlabs/sqlite3/build-tmp-napi-v6/Release/.deps/Release/obj.target/nothing \
		${WRKSRC}/node_modules/@gristlabs/sqlite3/build-tmp-napi-v6/Release/obj.target/nothing \
		${WRKSRC}/node_modules/@gristlabs/sqlite3/build/Release/.deps/Release/obj.target/nothing \
		${WRKSRC}/node_modules/@gristlabs/sqlite3/build/Release/obj.target/nothing

	# Install main directories
.for d in node_modules _build bower_components plugins static
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${WWWDIR})
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/app/cli.sh ${STAGEDIR}${WWWDIR}/cli
	${INSTALL_DATA} ${WRKSRC}/package.json ${STAGEDIR}${WWWDIR}
	#
	# Skip files having executable bit
	${CHMOD} +x ${WRKSRC}/sandbox/run.sh
	(cd ${WRKSRC} && ${COPYTREE_SHARE} sandbox ${STAGEDIR}${WWWDIR} "-not ( -type f -perm -a=x )")
	# now copy all files having an execution bit and preserve to x bit
	(cd ${WRKSRC} && ${COPYTREE_BIN} sandbox ${STAGEDIR}${WWWDIR} "-type f -perm -a=x")

	#${MKDIR} ${STAGEDIR}/var/db/grist
	# Configuration
	${INSTALL_DATA} ${FILESDIR}/grist.conf.sample ${STAGEDIR}${PREFIX}/etc/grist.conf.sample

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/grist.conf.sample$$/ s#^@sample #@sample(grist,wheel,0600) #;' >> ${TMPPLIST}
	#@${ECHO_CMD} "@dir(grist,grist) /var/db/grist" >> ${TMPPLIST}
	@${ECHO_CMD} "@sample(grist,wheel,0600) etc/grist.conf.sample" >> ${TMPPLIST}

# To update
# 1. comment DISTFILES
# 2. Run 'make makesum'
# 3. Run 'make make-yarn-cache'
# 4. Upload yarn cache
# 5. Uncomment DITSFILES
# 6. Run 'make makesum'
make-yarn-cache: patch
	${RM} -r ${WRKDIR}/yarn-offline-cache
	#cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true yarn --frozen-lockfile --ignore-scripts
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true yarn --frozen-lockfile
	cd ${WRKDIR} && ${TAR} -c --zstd -f ${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX} yarn-offline-cache
	@${ECHO_CMD} upload ${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX}
	@${ECHO_CMD} "Please upload the file: scp ${WRKDIR}/${PORTNAME}-yarn-offline-cache-${DISTVERSION}${EXTRACT_SUFX} mfechner@freefall.freebsd.org:public_distfiles/${PORTNAME}/"

.include <bsd.port.mk>
