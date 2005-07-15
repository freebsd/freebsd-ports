# New ports collection makefile for:	jwchat
# Date created:				June 24 2005
# Whom:					Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	jwchat
PORTVERSION=	1.0.b1
CATEGORIES=	www net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.b,beta,}

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Full featured, web-based Jabber client

USE_APACHE=	yes

NO_BUILD=	yes

PLIST_SUB+=	WWW_ROOT=www
SUB_FILES=	pkg-message
SUB_LIST=	WWW_ROOT=www PORTNAME=${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/www
	${CP} -R ${WRKSRC} ${PREFIX}/www/${PORTNAME}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
