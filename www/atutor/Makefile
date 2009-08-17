# New ports collection makefile for:	atutor
# Date created:		11 Feb 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	atutor
PORTVERSION=	1.6.3
CATEGORIES=	www
MASTER_SITES=	SFP/${PORTNAME}/ATutor/ATutor%20${PORTVERSION}/
DISTNAME=	ATutor-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source Web-based Learning Content Management System (LCMS)

USE_PHP=	session mbstring zlib mysql
WRKSRC=		${WRKDIR}/ATutor

.include <bsd.port.pre.mk>

NO_BUILD=	yes
SUB_FILES=	pkg-message

ATUTDATDIR=	${WWWDIR}/content
ATUTCONFIG=	include/config.inc.php

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} a+x {} \;
	@${INSTALL_DATA} -d ${ATUTDATDIR}
	@${CHMOD} 777 ${ATUTDATDIR}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${ATUTDATDIR}' >> ${TMPPLIST}
	@${CHMOD} 666 ${WWWDIR}/${ATUTCONFIG}
	@${ECHO_CMD} '@exec ${CHMOD} 666 \
		${WWWDIR}/${ATUTCONFIG}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
