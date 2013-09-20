# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	phpsysinfo
PORTVERSION=	3.0.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	walt@relnor.com
COMMENT=	A PHP script for displaying system information

LICENSE=	GPLv2

USE_PHP=	dom pcre xml simplexml mbstring
WANT_PHP_WEB=	yes

LATEST_LINK=	phpsysinfo-dev

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message

NO_STAGE=	yes
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
