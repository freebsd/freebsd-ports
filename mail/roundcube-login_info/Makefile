# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	login_info
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://www.std-soft.de/webmail/plugins/
PKGNAMEPREFIX=	roundcube-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}_rc0.5_v${DISTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Roundcube login info plugin

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube${PHP_PKGNAMESUFFIX}>=0.5:mail/roundcube@${PHP_FLAVOR}

USES=	php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${LOCALBASE}/www/roundcube
PLUGDIR=	${WWWDIR}/plugins/login_info
PLIST_SUB+=	PLUGDIR="www/roundcube/plugins/login_info"
WRKSRC=		${WRKDIR}/login_info

do-install:
	@${ECHO} "Installing in ${PLUGDIR}"
	${MKDIR} ${STAGEDIR}/${PLUGDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${PLUGDIR}

.include <bsd.port.mk>
