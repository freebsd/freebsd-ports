# Created by: Clemens Zauner <czauner+ports@onlineloop.com>
# $FreeBSD$

PORTNAME=	wbxml2
PORTVERSION=	0.10.9
CATEGORIES=	textproc devel
MASTER_SITES=	SF/libwbxml/libwbxml/${PORTVERSION}
DISTNAME=	libwbxml-${PORTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Library & tools for converting wbxml<->xml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

WRKSRC=			${WRKDIR}/libwbxml-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKDIR}/libwbxml-${PORTVERSION}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}

USES=		cmake iconv tar:bzip2
CMAKE_SOURCE_PATH=	..
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/libwbxml

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS BUGS ChangeLog NEWS README References THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
