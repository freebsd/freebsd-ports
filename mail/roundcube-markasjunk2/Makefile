# Created by: gahr
# $FreeBSD$

PORTNAME=	markasjunk2
PORTVERSION=	1.10
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Roundcube mark-as-junk / mark-as-not-junk plugin

LICENSE=	GPLv3

BUILD_DEPENDS=	roundcube>=1.0:mail/roundcube
RUN_DEPENDS=	roundcube>=1.0:mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	JohnDoh
GH_PROJECT=	Roundcube-Plugin-Mark-as-Junk-2

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/markasjunk2

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
