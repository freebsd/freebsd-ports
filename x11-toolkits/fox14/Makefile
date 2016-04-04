# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	1.4.35
PORTREVISION=	13
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fox-toolkit.org/ftp/ \
		ftp://ftp.fox-toolkit.org/pub/ \
		http://fresh.t-systems-sfr.com/unix/src/misc/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

MAJORVER=	${PORTVERSION:R}
SHVER=		${PORTVERSION:S/${MAJORVER}.//}
PLIST_SUB+=	MAJORVER=${MAJORVER} SHVER=${SHVER}

USES=		jpeg libtool
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl=yes \
		--bindir=${PREFIX}/bin/${PORTNAME}-${MAJORVER} \
		--enable-threadsafe
USE_LDCONFIG=	yes
PORTDOCS=	*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS CUPS DEBUG APPS PROFILE SHM XFT DOCS
OPTIONS_DEFAULT=SHM XFT
APPS_DESC=	Install sample applications
SHM_DESC=	Shared Memory support

.include <bsd.port.options.mk>

##
## Additional Options
##
#
.if ${PORT_OPTIONS:MXFT}
CONFIGURE_ARGS+=--with-xft=yes
USE_XORG+=	xft
CPPFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`
.else
CONFIGURE_ARGS+=	--with-xft=no
.endif
#
.if ${PORT_OPTIONS:MSHM}
CONFIGURE_ARGS+=	--with-xshm=yes
.else
CONFIGURE_ARGS+=	--with-xshm=no
.endif
#
.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:print/cups
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif
#
.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--enable-release
.endif
#
.if ${PORT_OPTIONS:MAPPS}
PLIST_SUB+=	APPS=""
.else
PLIST_SUB+=	APPS="@comment "
.endif
#
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
# turn distribution-recommended optimization flags back on
CXXFLAGS+=	-O2 -Wuninitialized -ffast-math -finline-functions -fomit-frame-pointer -fexpensive-optimizations
.endif
#
.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--with-profiling=gprof
.endif

post-patch:
# Rename man pages as in manpage.1 --> manpage-14.1 to avoid
# conflicts with fox16 and fox17
	files=$$(${FIND} ${WRKSRC} -name *.1); \
	for f in $$files; do \
		${MV} $$f `echo $$f | ${SED} -e 's|\.1|-14.1|'`; \
	done;
	${FIND} ${WRKSRC} -name Makefile.am -o -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -i '' -e '/man_MANS/s|\.1|-14.1|g'
# CXXFLAGS safeness
	@${REINPLACE_CMD} -E -e \
		's|-O2|${CXXFLAGS}|g ; \
		 s|-lc_r|-lpthread|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# doc prefix safeness
	@${REINPLACE_CMD} -E -e \
		's|^(htmldir).*$$|\1=${DOCSDIR}/html|' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|^(artdir).*$$|\1=${DOCSDIR}/html|' \
		${WRKSRC}/doc/art/Makefile.in
	@${REINPLACE_CMD} -E -e \
		's|^(screenshotsdir).*$$|\1=${DOCSDIR}/html|' \
		${WRKSRC}/doc/screenshots/Makefile.in
.if ${PORT_OPTIONS:MDOCS} == ""
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s/ doc//' \
		${WRKSRC}/Makefile.in
.endif
.if ${PORT_OPTIONS:MAPPS} == ""
	@${REINPLACE_CMD} -E -e \
		's,^(SUBDIRS.*)adie,\1,; \
		s,^(SUBDIRS.*)pathfinder,\1,; \
		s,^(SUBDIRS.*)calculator,\1,' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
