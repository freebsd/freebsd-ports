# Created by: gahr
# $FreeBSD$

PORTNAME=	carddav
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=${PORTNAME}_
CATEGORIES=	mail
MASTER_SITES=	https://github.com/blind-coder/rcmcarddav/releases/download/${PORTNAME}_${PORTVERSION}/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	rcm${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube CardDAV plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	roundcube>=1.0:mail/roundcube
RUN_DEPENDS=	roundcube>=1.0:mail/roundcube

NO_BUILD=	yes
NO_ARCH=	yes

USES=		php tar:bz2
USE_PHP=	simplexml sockets curl

WWWDIR=		${PREFIX}/www/roundcube/plugins/carddav

do-install:
	${FIND} ${WRKSRC} -name "*.orig" -delete
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
