# Created by: gahr
# $FreeBSD$

PORTNAME=	carddav
PORTVERSION=	2.0.4
CATEGORIES=	mail
MASTER_SITES=	https://github.com/blind-coder/rcmcarddav/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube CardDAV plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	roundcube>=1.0:mail/roundcube
RUN_DEPENDS=	roundcube>=1.0:mail/roundcube

WRKSRC=		${WRKDIR}/${PORTNAME}

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
