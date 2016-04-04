# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	html5_notifier
PORTVERSION=	0.5.2
DISTVERSIONPREFIX=	v
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	HTML5 desktop notifier plugin for roundcube

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube>=1.0:mail/roundcube
BUILD_DEPENDS=	roundcube>=1.0:mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	kitist

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
