# New ports collection makefile for:	phpSysInfo
# Date created:				Mon Mar 04, 2002
# Whom:					Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$

PORTNAME=	phpsysinfo
DISTVERSION=	2.5.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	walt@relnor.com
COMMENT=	A PHP script for displaying system information

CONFLICTS=	phpsysinfo-3.[0-9]*
LATEST_LINK=	phpsysinfo-dev

USE_PHP=	pcre xml simplexml
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:L}
NO_BUILD=	yes

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

.include <bsd.port.post.mk>
