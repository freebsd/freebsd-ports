# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	twofactor_u2f
PORTVERSION=	6.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://github.com/${PKGNAMEPREFIX}releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}/${DISTNAME}-${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	U2F multi-factor auth app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=20:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${RM} ${STAGEDIR}${WWWDIR}/COPYING

.include <bsd.port.mk>
