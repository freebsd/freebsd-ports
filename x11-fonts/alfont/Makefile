# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alfont
PORTVERSION=	209
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://opensnc.sourceforge.net/alfont/mirror/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:nemysis
#		http://opensnc.sourceforge.net/alfont/:opensnc
DISTFILES=	AlFont${DISTVERSION}.rar \
		alfont.c:nemysis
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	AlFont${DISTVERSION}.rar

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Wrapper around the freetype2 library

LICENSE=	FTL
LICENSE_NAME=	The FreeType Project LICENSE (FTL)
LICENSE_FILE=	${WRKSRC}/docs/FTL.txt
LICENSE_PERMS=	auto-accept

BROKEN=		unfetchable

EXTRACT_DEPENDS=	unrar:archivers/unrar
LIB_DEPENDS=	liballeg.so.4:devel/allegro \
		libfreetype.so:print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake iconv
USE_LDCONFIG=	yes

CPPFLAGS+=	-Iinclude -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/freetype2 $$(freetype-config --cflags)
LDFLAGS+=	-L${LOCALBASE}/lib -lalleg $$(freetype-config --libs)

PLIST_FILES=	include/alfont.h \
		include/alfontdll.h \
		lib/libalfont.so.${MAJORVER} \
		lib/libalfont.so

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGES.txt README.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	ALFONT.txt AUTHORS.txt

OPTIONS_DEFINE=	DOCS

MAJORVER=	${PORTVERSION:S/209/2.0.9/}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${LOCALBASE}/bin/unrar x -y -idq \
		${_DISTDIR}/AlFont${DISTVERSION}.rar

post-patch:
	@${CP} -af ${_DISTDIR}/alfont.c ${WRKSRC}/src

	@${REINPLACE_CMD} -e \
		's|#define ALFONT_WINDOWS|//#define ALFONT_WINDOWS|; \
		 s|//#define ALFONT_LINUX|#define ALFONT_LINUX|; \
		 s|^ALFONT_DLL_DECLSPEC void alfont_get_string.*||' \
		${WRKSRC}/include/alfont.h

do-build:
	cd ${WRKSRC} ; ${CC} ${CPPFLAGS} -fPIC -DPIC -c src/alfont.c -o \
		src/alfont.o
	cd ${WRKSRC} ; ${CC} -shared ${LDFLAGS} src/alfont.o -o \
		libalfont.so.${MAJORVER}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libalfont.so.${MAJORVER} \
		${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libalfont.so.${MAJORVER}
	@(cd ${STAGEDIR}${PREFIX}/lib ; ${LN} -sf libalfont.so.${MAJORVER} \
		libalfont.so)
	${INSTALL_DATA} ${WRKSRC}/include/alfont*.h ${STAGEDIR}${PREFIX}/include

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
