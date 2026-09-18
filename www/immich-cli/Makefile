PORTNAME=	immich-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
CATEGORIES=	www
MASTER_SITES=	https://github.com/joneum/FreeBSD-Immich/releases/download/v${DISTVERSION}/:buildkit
DISTFILES=	immich-freebsd-buildkit-${DISTVERSION}${EXTRACT_SUFX}:buildkit

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Command line interface for Immich
WWW=		https://immich.app/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/npm:www/npm-node22

USES=		cpe nodejs:22,build,run
CPE_VENDOR=	futo
CPE_PRODUCT=	immich

USE_GITHUB=	yes
GH_ACCOUNT=	immich-app
GH_PROJECT=	immich

# Shares the buildkit distfile with www/immich, see the comment there on
# how it is made.
BUILDKIT=	${WRKDIR}/immich-freebsd-buildkit-${DISTVERSION}
PNPM=		${WRKDIR}/pnpm-prefix/bin/pnpm
PNPM_VERSION=	11.22.0

MAKE_ENV=	CI=1 \
		COREPACK_ENABLE_STRICT=0

SUB_FILES=	immich
SUB_LIST=	NODE=${LOCALBASE}/bin/node

NO_ARCH=	yes

pre-build:
	cd ${WRKDIR} && ${SETENV} PATH=${PATH} \
		${LOCALBASE}/bin/npm install -g --prefix ${WRKDIR}/pnpm-prefix \
		${BUILDKIT}/pnpm-${PNPM_VERSION}.tgz

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} install --offline --frozen-lockfile --ignore-scripts \
		--store-dir ${BUILDKIT}/pnpm-store
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --filter @immich/sdk --filter @immich/cli build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PNPM} --store-dir ${BUILDKIT}/pnpm-store --filter @immich/cli \
		--prod --no-optional deploy ${WRKDIR}/cli-pruned

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKDIR}/cli-pruned && ${PAX} -rw . ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/immich ${STAGEDIR}${PREFIX}/bin/immich

.include <bsd.port.mk>
