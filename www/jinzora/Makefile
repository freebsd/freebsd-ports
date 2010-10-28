# New ports collection makefile for:	jinzora
# Date created:		27 October 2010
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jinzora
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	www multimedia
MASTER_SITES=	SF/${PORTNAME}/Jinzora%20${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A web based media streaming and management system

USE_PHP=	mysql session iconv gd pdf

WWWDOCROOT?=	www

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
SUB_FILES=      pkg-message

do-install:
	${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@if [ ! -f ${WWWDIR}/settings.php ]; then \
	${TOUCH} ${WWWDIR}/settings.php ; fi
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR} 
	${CHMOD} 755 ${WWWDIR}/jukebox/settings.php
	${CHMOD} -R 755 ${WWWDIR}/temp
	${CHMOD} -R 755 ${WWWDIR}/data

post-install:
	@${CAT} ${PKGMESSAGE}
	@${FIND} -s -d ${WWWDIR} -type f -print | \
		${SED} -e "s#${PREFIX}/##g" >> ${TMPPLIST}
	@${FIND} -s -d ${WWWDIR} -type d  -print | \
		${SED} -E -e "s#${PREFIX}/#@dirrm #g" >> ${TMPPLIST}

.include <bsd.port.mk>
