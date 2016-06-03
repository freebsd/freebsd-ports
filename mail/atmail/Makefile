# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	atmail
PORTVERSION=	1.0.4
CATEGORIES=	mail
MASTER_SITES=	http://atmail.org/download/
DISTNAME=	atmailopen

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Webmail Client

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		tar:tgz
USE_PHP=	mysql pcre session
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	LDAP MBSTRING ICONV
MBSTRING_DESC=	Support for UTF8 folder names

LDAP_USE=	PHP=ldap
MBSTRING_USE=	PHP=mbstring
ICONV_USE=	PHP=iconv

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
