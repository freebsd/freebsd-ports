# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	passman
PORTVERSION=	2.3.8
CATEGORIES=	security
MASTER_SITES=	https://releases.passman.cc/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Full featured password manager for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=14:www/nextcloud@${PHP_FLAVOR}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
