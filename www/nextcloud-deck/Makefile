# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	deck
PORTVERSION=	1.5.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	nextcloud/${PORTNAME}-${DISTVERSION}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Kanban app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=22:www/nextcloud@${PHP_FLAVOR}

USES=		cpe php:flavors
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
