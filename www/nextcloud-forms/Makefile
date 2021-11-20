# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	forms
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	nextcloud/${PORTNAME}-${DISTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Forms app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=20:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
