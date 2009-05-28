# New ports collection makefile for:	phpmyfaq
# Date created:		2005-04-15
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	phpmyfaq
PORTVERSION=	2.0.14
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/

MAINTAINER=	flo@kasimir.com
COMMENT=	A multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PHP=	mysql pcre pdf session xml xmlrpc zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

do-install:
	-${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}
.for i in ${FAQ_DIR}
	-@${MKDIR} ${WWWDIR}/${i}
	@${CHMOD} 777 ${WWWDIR}/${i}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
