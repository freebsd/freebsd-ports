PORTNAME=	hotcrp
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${WWW}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based conference management software
WWW=		https://www.read.seas.harvard.edu/~kohler/hotcrp/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pdftohtml:graphics/poppler-utils

USES=		php mysql:server
USE_PHP=	ctype gd mysqli session zlib

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
