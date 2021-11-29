# Created by: Bernard Spil <brnrd@freebsd.org>

PORTNAME=	appointments
PORTVERSION=	1.11.4
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/raw/${GH_TAGNAME}/build/artifacts/appstore/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	nextcloud/${PORTNAME}-${GH_TAGNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Appointments app for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=21:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

GH_ACCOUNT=	SergeyMosin
GH_TAGNAME=	08fbb2a56af8719f2d65920ad938ae9e53acb5b5

WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
			${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
