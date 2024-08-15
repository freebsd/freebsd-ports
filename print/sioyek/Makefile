PORTNAME=	sioyek
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	print

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	PDF viewer with focus on technical books and research papers
WWW=		https://sioyek.info

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmupdf.so:graphics/mupdf \
		libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2 \
		libjbig2dec.so:graphics/jbig2dec \
		libmujs.so:lang/mujs \
		libopenjp2.so:graphics/openjpeg \
		libsynctex.so:devel/tex-synctex

USES=		desktop-file-utils jpeg gl qmake qt:5 sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	ahrm
USE_GL=		gl
USE_QT=		3d buildtools:build core gui network opengl widgets

post-extract:
.for f in sqlite3.h sqlite3ext.h sqlite3.c shell.c
	${RM} ${WRKSRC}/pdf_viewer/$f
.endfor

pre-configure:
	${REINPLACE_CMD} -e 's,%%ETCDIR%%,${ETCDIR},' \
		-e 's,%%DATADIR%%,${DATADIR},' ${WRKSRC}/pdf_viewer/main.cpp

post-install:
.for f in keys prefs
	${MV} ${STAGEDIR}${ETCDIR}/$f.config ${STAGEDIR}${ETCDIR}/$f.config.sample
.endfor

.include <bsd.port.mk>
