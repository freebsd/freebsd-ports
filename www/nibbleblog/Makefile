# New ports collection makefile for:	nibbleblog
# Date created:				15 January 2011
# Whom:		Marek Holienka	<marekholienka@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	nibbleblog
PORTVERSION=	3.0.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}/
DISTNAME=	nibbleblogv302

MAINTAINER=	marekholienka@gmail.com
COMMENT=	A lightweight blog system for general use

RUN_DEPENDS=	pear:${PORTSDIR}/devel/pear

OPTIONS=	APACHE "Enable Apache Support" on \
		LIGHTTPD "Enable Lighttpd Support" off

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	session filter xml simplexml gd
PKGMESSAGE=	${MASTERDIR}/pkg-message
SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if defined(WITH_APACHE)
USE_APACHE=	1.3+
.endif
.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/${PORTNAME}/ ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
