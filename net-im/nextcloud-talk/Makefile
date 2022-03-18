# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	talk
PORTVERSION=	13.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im www
MASTER_SITES=	https://github.com/nextcloud-releases/spreed/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	spreed-${DISTVERSIONPREFIX}${DISTVERSION}
DIST_SUBDIR=	nextcloud

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Online meeting app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=23:www/nextcloud@${PHP_FLAVOR}

USES=		cpe php:flavors
CPE_VENDOR=	nextcloud
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/spreed
WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/spreed

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
