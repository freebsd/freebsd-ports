# Created by: gahr
# $FreeBSD$

PORTNAME=	carddav
PORTVERSION=	1.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=${PORTNAME}_
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube CardDAV plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	roundcube>=1.0:mail/roundcube
RUN_DEPENDS=	roundcube>=1.0:mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	blind-coder
GH_PROJECT=	rcmcarddav

NO_BUILD=	yes
NO_ARCH=	yes

USE_PHP=	simplexml sockets curl

WWWDIR=		${PREFIX}/www/roundcube/plugins/carddav

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
