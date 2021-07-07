# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	talk
PORTVERSION=	11.2.2
CATEGORIES=	net-im www
MASTER_SITES=	https://github.com/nextcloud/${DISTNAME:C/-.*//}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	spreed-${PORTVERSION}
DIST_SUBDIR=	nextcloud/${DISTNAME}
WRKSRC=		${WRKDIR}/spreed

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Online meeting app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=21:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/spreed

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
