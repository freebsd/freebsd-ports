# New ports collection makefile for:   elgg
# Date created:		25 Feberury 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	elgg
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	http://elgg.org/download/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Blogging and social networking platform

USE_PHP=	mysql gd json soap dom
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

NO_BUILD=	yes
SUB_FILES=	pkg-message
ELGGDATADIR=	www/elggdata

.include <bsd.port.pre.mk>
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

	@${INSTALL} -d ${PREFIX}/${ELGGDATADIR}
	@${CHMOD} 777 ${PREFIX}/${ELGGDATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${PREFIX}/${ELGGDATADIR}' \
		>> ${TMPPLIST}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
