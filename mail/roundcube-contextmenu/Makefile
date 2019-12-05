# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	contextmenu
PORTVERSION=	3.0
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	RoundCube webmail contextmenu plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=1.4.0:mail/roundcube@${PHP_FLAVOR}

USES=	php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	JohnDoh
GH_PROJECT=	roundcube-contextmenu

PLUGINDIR=	${WWWDIR:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
RCDIR_REL=	${WWWDIR_REL:S,/${PORTNAME}$$,,}/roundcube
PLIST_SUB=	RCDIR_REL="${RCDIR_REL}"

do-install:
	${MKDIR} ${STAGEDIR}${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PLUGINDIR}

.include <bsd.port.mk>
