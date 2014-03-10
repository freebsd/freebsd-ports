# Created by: Marek Holienka	<marekholienka@gmail.com>
# $FreeBSD$

PORTNAME=	nibbleblog
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}/
DISTNAME=	nibbleblogv302

MAINTAINER=	marekholienka@gmail.com
COMMENT=	A lightweight blog system for general use

RUN_DEPENDS=	pear:${PORTSDIR}/devel/pear

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

USES=		zip
NO_BUILD=	yes
USE_PHP=	session filter xml simplexml gd
PKGMESSAGE=	${MASTERDIR}/pkg-message
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif
.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CP} -r ${WRKDIR}/${PORTNAME}/ ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
