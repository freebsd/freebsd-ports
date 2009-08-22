# New ports collection makefile for:   freeway
# Date created:		22 Sep 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeway
PORTVERSION=	1.4.2.197
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}-ecom/Freeway/${PORTVERSION}%20Sathish
DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,_,g}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Advanced Open Source eCommerce Platform

USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-message

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
