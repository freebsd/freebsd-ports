# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	sauserprefs
PORTVERSION=	1.10 # PLEASE MIRROR DISTFILE WITH VERSIONED DIR
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.tehinterweb.co.uk/roundcube/plugins/ \
		LOCAL/bdrewery/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}

MAINTAINER=	stb@lassitu.de
COMMENT=	Roundcube plugin to manage SpamAssassin prefs

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.8:mail/roundcube@${PHP_FLAVOR}

USES=	php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/sauserprefs

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}/${WWWDIR}

.include <bsd.port.mk>
