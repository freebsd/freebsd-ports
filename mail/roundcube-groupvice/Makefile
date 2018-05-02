# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	groupvice
PORTVERSION=	0.1.2
CATEGORIES=	mail
MASTER_SITES=	ftp://renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme for RoundCube Web Mail

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.2:mail/roundcube@${PHP_FLAVOR}

USES=	php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/roundcube/skins/groupvice

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
