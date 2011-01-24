# New ports collection makefile for:	dracmail
# Date created:				14 January 2011
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

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

OPTIONS=	POSTGRE "Use PostgreSQL Database" off \
		APACHE "Use Apache webserver" on \
		LIGHTTPD "Use Lighttpd webserver" off

.include <bsd.port.options.mk>

.if defined(WITH_POSTGRE)
USE_PHP+=	pgsql
.endif
.if defined(WITH_APACHE)
USE_APACHE=	22
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
