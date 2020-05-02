# $FreeBSD$

PORTNAME=	hotcrp
PORTVERSION=	2.94
PORTREVISION=	13
CATEGORIES=	www
MASTER_SITES=	http://www.read.seas.harvard.edu/~kohler/hotcrp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based conference management software

RUN_DEPENDS=	pdftohtml:graphics/poppler-utils \
		zip:archivers/zip

USES=		php mysql:server
USE_PHP=	mysqli gd session ctype

NO_BUILD=	yes
SUB_FILES=	pkg-message

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
