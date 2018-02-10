# Created by: Bernard Spil <brnrd@freebsd.org>
# $FreeBSD$

PORTNAME=	passman
PORTVERSION=	2.1.4
CATEGORIES=	security
MASTER_SITES=	https://releases.passman.cc/
PKGNAMEPREFIX=	nextcloud-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	brnrd@freebsd.org
COMMENT=	Full featured password manager for Nextcloud

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nextcloud>=9:www/nextcloud

WRKSRC=		${WRKDIR}/${PORTNAME}


NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/nextcloud/apps/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	${RM} ${STAGEDIR}${WWWDIR}/COPYING ${STAGEDIR}${WWWDIR}/LICENSE

.include <bsd.port.mk>
