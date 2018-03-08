# Created by: Marek Holienka	<marekholienka@gmail.com>
# $FreeBSD$

PORTNAME=	nibbleblog
PORTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}/
DISTNAME=	nibbleblogv302

MAINTAINER=	marekholienka@gmail.com
COMMENT=	Lightweight blog system for general use

RUN_DEPENDS=	pear:devel/pear@${PHP_FLAVOR}

USES=		cpe php zip
NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	session filter xml simplexml gd
PKGMESSAGE=	${MASTERDIR}/pkg-message
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=	APACHE

APACHE_USE=		APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -r ${WRKDIR}/${PORTNAME}/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
