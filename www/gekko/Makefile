# New ports collection makefile for:	gekko
# Date created:				2005-11-21
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	gekko
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gekkoware
DIST_SUBDIR=	gekkoware

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Open Source solution for your Web Content Management

NO_BUILD=	yes
USE_PHP=	bz2 gd mysql pcre session zlib
GEKKODIR?=	www/${PORTNAME}
PLIST_SUB=	GEKKODIR=${GEKKODIR}

do-install:
	${MKDIR} ${PREFIX}/${GEKKODIR}
	cd ${WRKSRC}/src && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${GEKKODIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${GEKKODIR}/{}" \;
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GEKKODIR}

post-install:
	cd ${PREFIX}/${GEKKODIR} && \
		${CHMOD} 660 dbconf.php cgdb.php && \
		${CHMOD} -R 770 temp && \
		${CHMOD} -R 770 data
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
