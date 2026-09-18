PORTNAME=	immich-public-proxy
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
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
# network. It is made by unpacking the release tarball and running
#   cd app && npm ci --cache <kit>/npm-cache --ignore-scripts
BUILDKIT=	${WRKDIR}/${PORTNAME}-freebsd-buildkit-${DISTVERSION}

MAKE_ENV=	CI=1

SUB_FILES=	pkg-message
SUB_LIST=	NODE=${LOCALBASE}/bin/node

USERS=		immich
GROUPS=		immich

NO_ARCH=	yes

do-build:
	cd ${WRKSRC}/app && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm ci --offline --ignore-scripts \
		--cache ${BUILDKIT}/npm-cache
	cd ${WRKSRC}/app && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm run build
	cd ${WRKSRC}/app && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/npm prune --omit=dev --offline \
		--cache ${BUILDKIT}/npm-cache

do-install:
	${INSTALL_DATA} ${FILESDIR}/immich-public-proxy.env.sample \
		${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich-public-proxy.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich-public-proxy.conf
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/app && ${PAX} -rw dist node_modules public \
		package.json ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/app/config.json \
		${STAGEDIR}${WWWDIR}/config.json.sample

post-install:
	@${FIND} ${STAGEDIR}${WWWDIR} -depth -type d -empty -delete

.include <bsd.port.mk>
