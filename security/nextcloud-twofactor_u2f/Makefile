PORTNAME=	twofactor_u2f
PORTVERSION=	6.3.0
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

DEPRECATED=	Upstream deprecated this port in favor of twofactor_webauthn. Check\
		https://github.com/nextcloud/twofactor_webauthn\#migration-from-two-factor-u2f\
		for migration instructions
EXPIRATION_DATE=2022-08-01

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=20:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	82
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${RM} ${STAGEDIR}${WWWDIR}/COPYING

.include <bsd.port.mk>
