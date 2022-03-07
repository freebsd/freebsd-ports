PORTNAME=	twofactor_webauthn
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	rosenke@dssgmbh.de
COMMENT=	U2F webauthn app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=21:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors

MASTER_SITES=	https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
