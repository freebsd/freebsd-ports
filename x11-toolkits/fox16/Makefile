# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	1.6.51
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fox-toolkit.org/pub/ \
		http://ftp.fox-toolkit.org/pub/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- ver.1.6

LICENSE=	LGPL3+

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		jpeg libtool pathfix
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl --with-x --with-xim
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	MAJORVER="${MAJORVER}"

PORTDOCS=	*

OPTIONS_DEFINE=		APPS DEBUG DOCS OPTIMIZED_CFLAGS PROFILE SHM \
			XCURSOR XFT XINPUT XRANDR XRENDER
OPTIONS_DEFAULT= 	SHM XCURSOR XFT XINPUT XRANDR XRENDER
OPTIONS_SUB=		yes

APPS_DESC=		Install sample applications
DEBUG_CONFIGURE_ON=	--enable-debug
DEBUG_CONFIGURE_OFF=	--enable-release
OPTIMIZED_CFLAGS_CXXFLAGS=\
			-ffast-math -fexpensive-optimizations \
			-finline-functions -fomit-frame-pointer
PROFILE_CONFIGURE_ON=	--with-profiling=gprof
SHM_DESC=		Shared Memory support
SHM_CONFIGURE_ON=	--with-xshm=yes
SHM_CONFIGURE_OFF=	--with-xshm=no
XCURSOR_USE=		xorg=xcursor
XCURSOR_CONFIGURE_ON=	--with-xcursor=yes
XCURSOR_CONFIGURE_OFF=	--with-xcursor=no
XFT_USE=		xorg=xft
XFT_CONFIGURE_ON=	--with-xft=yes
XFT_CONFIGURE_OFF=	--with-xft=no
XFT_CPPFLAGS=		$$(freetype-config --cflags)
XFT_LDFLAGS=		$$(freetype-config --libs)
XFT_IMPLIES=		XRENDER
XINPUT_DESC=		X Input extension library support
XINPUT_USE=		xorg=xi
XINPUT_CONFIGURE_ON=	--with-xinput=yes
XINPUT_CONFIGURE_OFF=	--with-xinput=no
XRANDR_USE=		xorg=xrandr
XRANDR_CONFIGURE_ON=	--with-xrandr=yes
XRANDR_CONFIGURE_OFF=	--with-xrandr=no
XRENDER_DESC=		X Render extension library support
XRENDER_USE=		xorg=xrender
XRENDER_CONFIGURE_ON=	--with-xrender=yes
XRENDER_CONFIGURE_OFF=	--with-xrender=no

MAJORVER=	${PORTVERSION:R}

post-patch:
# Rename man pages as in manpage.1 --> manpage-16.1 to avoid
# conflicts with fox14 and fox17
	files=$$(${FIND} ${WRKSRC} -name *.1); \
	for f in $$files; do \
		${MV} $$f `${ECHO_CMD} $$f | ${SED} -e 's|\.1|-16.1|'`; \
	done;
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/man_MANS/s|\.1|-16.1|g'
	@${REINPLACE_CMD} -e \
		'/^Libs:/s|$$| -pthread|; \
		 s|"||g' ${WRKSRC}/fox.pc.in
# CXXFLAGS safeness
	@${REINPLACE_CMD} -e \
		's|^\(CXXFLAGS=""\)|#\1|; \
		 /CXXFLAGS/s|-O2 ||; \
		 /CXXFLAGS/s|\(-Wuninitialized\).*"|\1"|; \
		 /LDFLAGS/s|-s ||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# doc prefix safeness
	@${REINPLACE_CMD} -e \
		's|^\(htmldir\).*$$|\1=${DOCSDIR}/html|' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		's|^\(artdir\).*$$|\1=${DOCSDIR}/html|' \
		${WRKSRC}/doc/art/Makefile.in
	@${REINPLACE_CMD} -e \
		's|^\(screenshotsdir\).*$$|\1=${DOCSDIR}/html|' \
		${WRKSRC}/doc/screenshots/Makefile.in

post-patch-APPS-off:
	@${REINPLACE_CMD} -e \
		's|^\(SUBDIRS.*\)adie|\1|; \
		 s|^\(SUBDIRS.*\)pathfinder|\1|; \
		 s|^\(SUBDIRS.*\)calculator|\1|' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libCHART-${MAJORVER}.so.[0-9].*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libFOX-${MAJORVER}.so.[0-9].*

.include <bsd.port.mk>
