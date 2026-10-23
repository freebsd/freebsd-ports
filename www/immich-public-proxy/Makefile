PORTNAME=	immich-public-proxy
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-Immich/releases/download/ipp-v${DISTVERSION}/:buildkit
DISTFILES=	${PORTNAME}-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}:buildkit

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Share Immich photos and albums without exposing the server
WWW=		https://github.com/alangrainger/immich-public-proxy

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/npm:www/npm-node22

USES=		nodejs:22,build,run

USE_GITHUB=	yes
GH_ACCOUNT=	alangrainger

USE_RC_SUBR=	immich_public_proxy

# The buildkit distfile carries the npm cache, so that the build needs no
# network. It is made by unpacking the release tarball and running, in the
# workspace root, both installs the build does:
#   npm ci --workspace=app --cache <kit>/npm-cache --ignore-scripts
#   npm ci --workspace=app --omit=dev --cache <kit>/npm-cache --ignore-scripts
BUILDKIT=	${WRKDIR}/${PORTNAME}-freebsd-buildkit-${DISTVERSION}

MAKE_ENV=	CI=1

SUB_FILES=	pkg-message
SUB_LIST=	NODE=${LOCALBASE}/bin/node

USERS=		immich
GROUPS=		immich

NO_ARCH=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm ci --workspace=app --offline \
		--ignore-scripts --cache ${BUILDKIT}/npm-cache
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm run build --workspace=shared --workspace=app
	cd ${WRKSRC} && ${RM} -r node_modules && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm ci --workspace=app --omit=dev --offline \
		--ignore-scripts --cache ${BUILDKIT}/npm-cache
	cd ${WRKSRC} && ${RM} -r node_modules/${PORTNAME} \
		node_modules/${PORTNAME}-upload node_modules/.bin/${PORTNAME}*
	cd ${WRKSRC} && ${CP} -RL node_modules prod_modules
	cd ${WRKSRC}/prod_modules/@ipp/core && ${RM} -r src tests tsconfig.json \
		vitest.config.ts dist/tsconfig.tsbuildinfo
	${RM} -f ${WRKSRC}/app/dist/tsconfig.tsbuildinfo

do-install:
	${INSTALL_DATA} ${FILESDIR}/immich-public-proxy.env.sample \
		${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich-public-proxy.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich-public-proxy.conf
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/app && ${PAX} -rw dist public package.json \
		${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/node_modules
	cd ${WRKSRC}/prod_modules && ${PAX} -rw . \
		${STAGEDIR}${WWWDIR}/node_modules
	${INSTALL_DATA} ${WRKSRC}/app/config.json \
		${STAGEDIR}${WWWDIR}/config.json.sample

post-install:
	@${FIND} ${STAGEDIR}${WWWDIR} -depth -type d -empty -delete

.include <bsd.port.mk>
