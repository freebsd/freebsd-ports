# New ports collection makefile for:	phpmyfaq
# Date created:		2005-04-15
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	phpmyfaq
PORTVERSION=	1.6.11
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PHP=	mysql pcre pdf session xml xmlrpc zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

do-install:
	-${MKDIR} ${WWWDIR}
	@${CHMOD} 755 ${WWWDIR}
	@${CP} -R ${WRKSRC}/ ${WWWDIR}
.for i in ${FAQ_DIR}
	@${MKDIR} ${WWWDIR}/${i}
	@${CHMOD} 777 ${WWWDIR}/${i}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
