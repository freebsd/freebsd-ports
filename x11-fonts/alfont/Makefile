# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alfont
PORTVERSION=	2.0.9
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://opensnc.sourceforge.net/alfont/mirror/
DISTNAME=	AlFont${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.rar
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper around the freetype2 library

LICENSE=	FTL
LICENSE_NAME=	The FreeType Project LICENSE (FTL)
LICENSE_FILE=	${WRKSRC}/docs/FTL.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

EXTRACT_DEPENDS=	unrar:archivers/unrar
LIB_DEPENDS=	liballeg.so.4:devel/allegro \
		libfreetype.so:print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake iconv
USE_LDCONFIG=	yes

EXTRACT_CMD=		${LOCALBASE}/bin/unrar
EXTRACT_BEFORE_ARGS=	x -y -idq
EXTRACT_AFTER_ARGS=

CPPFLAGS+=	-Iinclude -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2 $$(freetype-config --cflags)
LDFLAGS+=	-L${LOCALBASE}/lib -lalleg $$(freetype-config --libs)

PLIST_FILES=	include/alfont.h \
		include/alfontdll.h \
		lib/libalfont.so.${PORTVERSION} \
		lib/libalfont.so

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|#define ALFONT_WINDOWS|//#define ALFONT_WINDOWS|; \
		 s|//#define ALFONT_LINUX|#define ALFONT_LINUX|; \
		 s|^ALFONT_DLL_DECLSPEC void alfont_get_string.*||' \
		${WRKSRC}/include/alfont.h

do-build:
	cd ${WRKSRC} ; ${CC} ${CPPFLAGS} -fPIC -DPIC -c src/alfont.c -o \
		src/alfont.o
	cd ${WRKSRC} ; ${CC} -shared ${LDFLAGS} -Wl,-soname=libalfont.so.${PORTVERSION} \
		src/alfont.o -o libalfont.so.${PORTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libalfont.so.${PORTVERSION} \
		${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libalfont.so.${PORTVERSION}
	@(cd ${STAGEDIR}${PREFIX}/lib ; ${LN} -sf libalfont.so.${PORTVERSION} \
		libalfont.so)
	${INSTALL_DATA} ${WRKSRC}/include/alfont*.h ${STAGEDIR}${PREFIX}/include

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES.txt README.txt docs/ALFONT.txt \
		docs/AUTHORS.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
