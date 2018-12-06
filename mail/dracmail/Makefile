# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	dracmail
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/dracmail/release/
DISTNAME=	dracMail-${PORTVERSION}_release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DracMail is a webmail interface built using PHP

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73
USE_PHP+=	mysql imap dom tidy iconv mbstring
USE_MYSQL=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	PGSQL APACHE LIGHTTPD
OPTIONS_DEFAULT=APACHE

PGSQL_USE=	PHP=pgsql
APACHE_USE=	APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd

post-extract:
	@${MKDIR} ${WRKSRC}
	-@${MV} ${WRKDIR}/* ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -rp ${WRKSRC}/* ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
