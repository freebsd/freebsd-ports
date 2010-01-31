# New ports collection makefile for:	phpSysInfo
# Date created:				Mon Mar 04, 2002
# Whom:					Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$

PORTNAME=	phpSysInfo
DISTVERSION=	3.0-RC9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/3.0-RC9

MAINTAINER=	walt@relnor.com
COMMENT=	A PHP script for displaying system information

USE_PHP=	pcre xml simplexml mbstring
WANT_PHP_WEB=	yes

CONFLICTS=	phpsysinfo-2.[0-9]*
IGNORE=		please use www/phpsysinfo

WRKSRC=		${WRKDIR}/${PORTNAME:L}
NO_BUILD=	yes

SUB_FILES=	pkg-message
LATEST_LINK=	phpsysinfo

.include <bsd.port.pre.mk>

post-install:
	@if [ ! -f ${WWWDIR}/config.php ]; then \
		${CP} -p ${WWWDIR}/config.php ${WWWDIR}/config.php.bak ; \
	fi

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CHMOD} -R ${BINMODE} ${WWWDIR}
	${FIND} ${WWWDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}
	${CP} ${WWWDIR}/config.php.new ${WWWDIR}/config.php

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.include <bsd.port.post.mk>
