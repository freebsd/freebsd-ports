# Created by: Clemens Zauner <czauner+ports@onlineloop.com>
# $FreeBSD$

PORTNAME=	wbxml2
PORTVERSION=	0.11.2
CATEGORIES=	textproc devel
MASTER_SITES=	SF/libwbxml/libwbxml/${PORTVERSION}
DISTNAME=	libwbxml-${PORTVERSION}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Library & tools for converting wbxml<->xml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		cmake:outsource iconv tar:bzip2
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/libwbxml-${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/libwbxml

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS BUGS ChangeLog NEWS README References THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
