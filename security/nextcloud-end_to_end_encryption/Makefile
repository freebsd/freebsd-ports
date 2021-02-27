# Created by: Bernard Spil <brnrd@freebsd.org>
# $FreeBSD$

PORTNAME=	end_to_end_encryption
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://github.com/${PKGNAMEPREFIX:S/-//}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}/${DISTNAME}

MAINTAINER=	brnrd@freebsd.org
COMMENT=	End-to-End Encryption app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=20:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${RM} ${STAGEDIR}${WWWDIR}/COPYING

.include <bsd.port.mk>
