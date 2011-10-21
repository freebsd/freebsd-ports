# New ports collection makefile for:   elgg
# Date created:		25 Feberury 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	elgg
PORTVERSION=	1.8.0.1
CATEGORIES=	www
MASTER_SITES=	http://elgg.org/download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Blogging and social networking platform

LICENSE=	GPLv2

USE_PHP=	mysql gd json soap dom xml
USE_GETTEXT=	yes
USE_ZIP=	yes

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
