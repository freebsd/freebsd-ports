# Created by: gahr
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	1.7.50
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.fox-toolkit.org/pub/ \
		ftp://ftp.fox-toolkit.org/pub/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit (development version)

BROKEN_powerpc=		missing __sync_bool_compare_and_swap_8()

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_GL=		glut
USE_XORG=	sm xft
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-opengl=yes \
		--bindir=${PREFIX}/bin/${PORTNAME}-${MAJORVER}

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
PORTDOCS=	*

MAJORVER=	${PORTVERSION:R}
PLIST_SUB+=	MAJORVER=${MAJORVER}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${MAJORVER}

OPTIONS_DEFINE=	DOCS JPEG PNG TIFF WEBP
OPTIONS_DEFAULT=	JPEG PNG TIFF WEBP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG}
USES+=		jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
.else
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:graphics/tiff
.else
CONFIGURE_ARGS+=--disable-tiff
.endif

.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=	libwebp.so:graphics/webp
.else
CONFIGURE_ARGS+=--disable-webp
.endif

post-patch:
# Rename man pages as in manpage.1 --> manpage-17.1 to avoid
# conflicts with fox14 and fox16
	files=$$(${FIND} ${WRKSRC} -name *.1); \
	for f in $$files; do \
		${MV} $$f `echo $$f | sed -e 's|\.1|-17.1|'`; \
	done;
	${FIND} ${WRKSRC} -name Makefile.am -o -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -i '' -e '/man_MANS/s|\.1|-17.1|g'
	${REINPLACE_CMD} -e '/^Libs:/s|$$| -pthread|; s|"||g' ${WRKSRC}/fox17.pc.in
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^SUBDIRS/s/ doc//' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libFOX-${MAJORVER}.so \
		${STAGEDIR}${PREFIX}/lib/libCHART-${MAJORVER}.so

.include <bsd.port.mk>
