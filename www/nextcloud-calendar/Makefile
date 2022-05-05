# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	calendar
PORTVERSION=	3.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	nextcloud

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Calendar app for Nextcloud

LICENSE=	AGPLv3

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=20:www/nextcloud@${PHP_FLAVOR}

USES=		cpe php:flavors

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
CPE_VENDOR=	nextcloud

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
