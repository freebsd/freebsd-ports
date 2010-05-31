# New ports collection makefile for:   elgg
# Date created:		25 Feberury 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	elgg
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://elgg.org/download/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Blogging and social networking platform

USE_PHP=	mysql gd json soap dom xml
USE_GETTEXT=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

NO_BUILD=	yes
SUB_FILES=	pkg-message
ELGGDATADIR=	${WWWDIR}data

.include <bsd.port.pre.mk>
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

	@${INSTALL} -d ${ELGGDATADIR}
	@${CHMOD} 777 ${ELGGDATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} 777 ${ELGGDATADIR}' \
		>> ${TMPPLIST}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
