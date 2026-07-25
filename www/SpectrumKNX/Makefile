PORTNAME=	SpectrumKNX
PORTVERSION=	1.16.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	LOCAL/mfechner/${PORTNAME}/:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	KNX bus and telegram monitor with storage
WWW=		https://github.com/martinhoefling/SpectrumKNX

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Npm cache only for amd64 generated

BUILD_DEPENDS=	npm>=0:www/npm \
		git>=0:devel/git
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=22.2.2:devel/py-pip@${PY_FLAVOR} \
		cargo-cbuild:devel/cargo-c \
		rust>0:lang/rust

USES=		compiler:c++17-lang gmake nodejs python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	martinhoefling
USE_RC_SUBR=	spectrumknx

# Required for node-gyp to work
MAKE_ENV+=	npm_config_build_from_source=true
MAKE_ENV+=	npm_config_nodedir=${PREFIX}
MAKE_ENV+=	npm_config_node_gyp=${LOCALBASE}/bin/node-gyp
MAKE_ENV+=	PYTHON=${PYTHON_CMD}
MAKE_ENV+=	COREPACK_ENABLE_DOWNLOAD_PROMPT=0
MAKE_ENV+=	npm_config_offline=true
MAKE_ENV+=	VITE_APP_VERSION=${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

WWWDIR=		${PREFIX}/www/${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	SPECTRUMKNX_USER=${USERS} \
		SPECTRUMKNX_GROUP=${GROUPS} \
		PYTHON_CMD="${PYTHON_CMD}" \
		APP_VERSION="${PORTVERSION}"
USERS=		spectrumknx
GROUPS=		spectrumknx

pre-build:
	cd ${WRKSRC}/frontend && ${SETENV} ${MAKE_ENV} npm ci --legacy-peer-deps

do-build:
	@cd ${WRKSRC}/frontend && ${SETENV} ${MAKE_ENV} npm run build

do-install:
	${FIND} ${WRKSRC} -name '*.orig' -delete

	# Install backend
	(cd ${WRKSRC}/backend && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	# Install frontend
	(cd ${WRKSRC}/frontend/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/static)

	# Configuration
	${INSTALL_DATA} ${FILESDIR}/spectrumknx.conf.sample ${STAGEDIR}${PREFIX}/etc/spectrumknx.conf.sample

	# User Home directory
	@${MKDIR} ${STAGEDIR}/var/db/spectrumknx

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/spectrumknx.conf.sample$$/ s#^@sample #@sample(spectrumknx,wheel,0600) #;' >> ${TMPPLIST}
	@${ECHO_CMD} "@sample(spectrumknx,wheel,0600) etc/spectrumknx.conf.sample" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner spectrumknx" >> ${TMPPLIST}
	@${ECHO_CMD} "@group spectrumknx" >> ${TMPPLIST}
	@${ECHO_CMD} "@dir /var/db/spectrumknx" >> ${TMPPLIST}

# To update
# 1. comment DISTFILES
# 2. Run 'make makesum'
# 3. Run 'make make-npm-cache'
# 4. Upload npm cache
# 5. Uncomment DITSFILES
# 6. Run 'make makesum'
make-npm-cache: patch
	${RM} -r ${WRKDIR}/npm-offline-cache
	#cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PUPPETEER_SKIP_CHROMIUM_DOWNLOAD=true yarn --frozen-lockfile --ignore-scripts
	cd ${WRKSRC}/frontend && ${SETENV} HOME=${WRKDIR} npm ci --legacy-peer-deps
	cd ${WRKDIR} && ${TAR} -c --zstd -f ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm
	@${ECHO_CMD} upload ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}
	@${ECHO_CMD} "Please upload the file: scp ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} mfechner@freefall.freebsd.org:public_distfiles/${PORTNAME}/"

.include <bsd.port.mk>
