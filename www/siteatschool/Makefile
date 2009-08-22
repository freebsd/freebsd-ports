# New ports collection makefile for:   siteatschool
# Date created:		16 March 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	siteatschool
PORTVERSION=	2.4.10
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Site%40School/Site%40School%20${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	CMS to manage and maintain a school website

USE_PHP=	mysql
USE_ZIP=	yes
SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKDIR} && ${COPYTREE_SHARE} "starnet agenda index.php" ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
