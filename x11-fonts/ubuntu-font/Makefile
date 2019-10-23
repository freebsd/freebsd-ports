# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ubuntu-font
PORTVERSION=	0.83
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://assets.ubuntu.com/v1/
DISTNAME=	0cef8205-${ARCHIVE_NAME}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Ubuntu font family

LICENSE=	UFL
LICENSE_FILE=	${WRKSRC}/LICENCE.txt
LICENSE_NAME=	Ubuntu Font License (UFL)
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${ARCHIVE_NAME}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

ARCHIVE_NAME=	${PORTNAME}-family-${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
