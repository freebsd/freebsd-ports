# $FreeBSD$

PORTNAME=	hotcrp
PORTVERSION=	2.92
CATEGORIES=	www
MASTER_SITES=	http://www.read.seas.harvard.edu/~kohler/hotcrp/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Web based conference management software

RUN_DEPENDS=	pdftohtml:${PORTSDIR}/graphics/poppler-utils \
		zip:${PORTSDIR}/archivers/zip

USE_PHP=	mysqli gd session ctype
USE_MYSQL=	server

NO_BUILD=	yes
SUB_FILES=	pkg-message

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
