# Created by: chinsan <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	phpmyfaq
PORTVERSION=	2.9.5
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/
DISTNAME=	phpMyFAQ-${PORTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		cpe php:web
USE_PHP=	filter json mysql pcre pdf session xml xmlrpc xmlwriter zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
NO_ARCH=	YES
IGNORE_WITH_PHP=70

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
.for i in ${FAQ_DIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${i}
.endfor

.include <bsd.port.mk>
