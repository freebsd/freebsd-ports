# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	1.6.49
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fox-toolkit.org/pub/ \
    		http://ftp.fox-toolkit.org/pub/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- ver.1.6

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

MAJORVER=	${PORTVERSION:R}
PLIST_SUB+=	MAJORVER=${MAJORVER}

USES=		libtool pathfix
USE_GL=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl --with-x
PORTDOCS=	*

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS CUPS DEBUG DOCS APPS PROFILE SHM XFT
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
LIB_DEPENDS+=	libcups.so:${PORTSDIR}/print/cups-client
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
CXXFLAGS+=	-O2 -Wuninitialized -ffast-math -finline-functions -fexpensive-optimizations
.if ${PORT_OPTIONS:MPROFILE} == "" # Incompatible with profiling flags
CXXFLAGS+=	-fomit-frame-pointer
.endif
.endif
#
.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--with-profiling=gprof
.endif

post-patch:
# Rename man pages as in manpage.1 --> manpage-16.1 to avoid
# conflicts with fox14 and fox17
	files=$$(${FIND} ${WRKSRC} -name *.1); \
	for f in $$files; do \
		${MV} $$f `echo $$f | sed -e 's|\.1|-16.1|'`; \
	done;
	${FIND} ${WRKSRC} -name Makefile.am -o -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -i '' -e '/man_MANS/s|\.1|-16.1|g'
	${REINPLACE_CMD} -e '/^Libs:/s|$$| ${PTHREAD_LIBS}|; s|"||g' ${WRKSRC}/fox.pc.in
# CXXFLAGS safeness
	@${REINPLACE_CMD} -E -e \
		's|-O2|${CXXFLAGS}|g ; \
		 s|-lc_r|${PTHREAD_LIBS}|g' \
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

.include <bsd.port.mk>
