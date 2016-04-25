# Created by: chinsan <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	phpmyfaq
PORTVERSION=	2.8.27
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/
DISTNAME=	phpMyFAQ-${PORTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		cpe
USE_PHP=	filter json mysql pcre pdf session xml xmlrpc xmlwriter zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES
NO_ARCH=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
.for i in ${FAQ_DIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${i}
.endfor

.include <bsd.port.mk>
