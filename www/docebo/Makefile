# New ports collection makefile for:   docebo
# Date created:		6 April 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	docebo
PORTVERSION=	3.5.0.4
CATEGORIES=	www
MASTER_SITES=	http://www.docebo.org/doceboCms/index.php?mn=docs&op=download&pi=5_4&id=57/
DISTNAME=	${PORTNAME}3504

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open Source e-Learning platform (LMS and LCMS)

USE_PHP=	mysql
USE_ZIP=	yes
SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "config.php admin.php index.php" ${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "doceboCms doceboCore doceboCrm" ${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "doceboEcom doceboLms doceboScs" ${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "doceboCms doceboCore doceboCrm" ${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "files install readmelicense" ${WWWDIR}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "template upgrade xml_language" ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
