# Created by: gahr
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	1.7.62
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.fox-toolkit.org/pub/ \
		ftp://ftp.fox-toolkit.org/pub/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit (development version)

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c++11-lib libtool localbase pathfix
USE_GL=		gl glu
USE_XORG=	ice sm x11 xcursor xext xfixes xft xi xrandr xrender
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl=yes \
		--with-xim \
		--enable-png \
		--bindir=${PREFIX}/bin/${PORTNAME}-${MAJORVER}
INSTALL_TARGET=	install-strip

MAJORVER=	${PORTVERSION:R}
PLIST_SUB+=	MAJORVER=${MAJORVER}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${MAJORVER}
PORTDOCS=	*

BROKEN_aarch64=		Fails to compile: cannot initialize a parameter of type void * with an lvalue of type long
BROKEN_powerpc=		missing __sync_bool_compare_and_swap_8()

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES OPTIMIZED_CFLAGS PROFILE TEST
OPTIONS_GROUP=		IMGFMTS
OPTIONS_GROUP_IMGFMTS=	JPEG OPENJPEG TIFF WEBP
OPTIONS_DEFAULT=	JPEG OPENJPEG TIFF WEBP
IMGFMTS_DESC=		Image formats

DEBUG_CONFIGURE_ENABLE=	debug
DEBUG_CXXFLAGS_OFF=	-DNDEBUG

JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg

OPENJPEG_LIB_DEPENDS=	libopenjpeg.so:graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	jp2

PROFILE_CONFIGURE_ON=	--with-profiling=gprof

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ENABLE=	tiff

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_CONFIGURE_ENABLE=	webp

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CXXFLAGS+=	-O2 -ffast-math
.  if !${PORT_OPTIONS:MPROFILE}
CXXFLAGS+=	-fomit-frame-pointer
.  endif
.  if ${COMPILER_TYPE} == "gcc"
CXXFLAGS+=	-fexpensive-optimizations -finline-functions
.  endif
.endif

post-patch:
# Rename man pages as in manpage.1 --> manpage-17.1 to avoid
# conflicts with fox14 and fox16
	@files=$$(${FIND} ${WRKSRC} -name *.1); \
	for f in $$files; do \
		${MV} $$f `${ECHO_CMD} $$f | ${SED} -e 's|\.1|-17.1|'`; \
	done;
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/man_MANS/s|\.1|-17.1|g'
	@${REINPLACE_CMD} -e '/^Libs:/s|$$| -pthread|; s|"||g' ${WRKSRC}/fox17.pc.in
# CXXFLAGS safeness
	@${REINPLACE_CMD} -e \
		's|^\(CXXFLAGS=""\)|#\1|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e \
		's|^\(SUBDIRS.*\)adie|\1|; \
		 s|^\(SUBDIRS.*\)pathfinder|\1|; \
		 s|^\(SUBDIRS.*\)shutterbug|\1|; \
		 s|^\(SUBDIRS.*\)calculator|\1|' \
		${WRKSRC}/Makefile.in

post-patch-TEST-off:
	@${REINPLACE_CMD} -e \
		's|^\(SUBDIRS.*\)glviewer|\1|; \
		 s|^\(SUBDIRS.*\)tests|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
