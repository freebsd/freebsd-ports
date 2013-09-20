# Created by: Alexander Novitsky <alecn2002@yandex.ru>
# $FreeBSD$

PORTNAME=	fox
PORTVERSION=	${MAJORVER}.${SHVER}
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fox-toolkit.org/pub/ \
    		http://ftp.fox-toolkit.org/pub/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- ver.1.6

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		Xft:${PORTSDIR}/x11-fonts/libXft

LATEST_LINK=	fox16

MAJORVER=	1.6
SHVER=		49
PLIST_SUB+=	MAJORVER=${MAJORVER} SHVER=${SHVER}

USE_GNOME=	lthack gnomehack
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl --with-x
USE_LDCONFIG=	yes

MAN1=		shutterbug.1 reswrap.1

CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS CUPS DEBUG APPS PROFILE SHM XFT
OPTIONS_DEFAULT=SHM XFT
APPS_DESC=	Install sample applications
SHM_DESC=	Shared Memory support

NO_STAGE=	yes
.include <bsd.port.options.mk>

##
## Additional Options
##
#
.if ${PORT_OPTIONS:MXFT}
CONFIGURE_ARGS+=	--with-xft=yes
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
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
.endif
#
.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--enable-release
.endif
#
.if ${PORT_OPTIONS:MAPPS}
MAN1+=		PathFinder.1 adie.1 calculator.1
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
	${REINPLACE_CMD} -e '/^Libs:/s|$$| ${PTHREAD_LIBS}|; s|"||g' ${WRKSRC}/fox.pc.in
# CXXFLAGS safeness
	@${REINPLACE_CMD} -E -e \
		's|-O2|${CXXFLAGS}|g ; \
		 s|-lc_r|${PTHREAD_LIBS}|g ; \
		 s|FOX_INTERFACE_VERSION=0|FOX_INTERFACE_VERSION=${SHVER}|g' \
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
