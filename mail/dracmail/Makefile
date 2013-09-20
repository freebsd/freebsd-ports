# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	dracmail
PORTVERSION=	0.1.2
CATEGORIES=	mail
MASTER_SITES=	SF/dracmail/release/
DISTNAME=	dracMail-${PORTVERSION}_release

MAINTAINER=	fgheorghe@dracmail.net
COMMENT=	DracMail is a webmail interface built using PHP

RUN_DEPENDS+=	php:${PORTSDIR}/lang/php5

USE_PHP+=	mysql imap dom tidy iconv mbstring
USE_MYSQL=	yes
NO_BUILD=	yes
WWWOWN=		www
WWWGRP=		${WWWOWN}

PKGMESSAGE=	${WRKDIR}/${PORTNAME}/pkg-message
SUB_FILES=      pkg-message
PLIST_DIRSTRY=	%%WWWDIR%%

OPTIONS_DEFINE=	PGSQL APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif
.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif
.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
