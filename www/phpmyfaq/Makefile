# Created by: chinsan <chinsan@mail2000.com.tw>

PORTNAME=	phpmyfaq
PORTVERSION=	3.1.1
CATEGORIES=	www
MASTER_SITES=	https://download.phpmyfaq.de/files/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Multilingual, completely database-driven FAQ-system

LICENSE=	MPL20

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		cpe php:web
USE_PHP=	filter json mysqli pcre session xml xmlrpc xmlwriter zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
NO_ARCH=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
.for i in ${FAQ_DIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${i}
.endfor

.include <bsd.port.pre.mk>

.if ${PHP_VER} < 80
USE_PHP+=	pdf
.endif

.include <bsd.port.post.mk>
