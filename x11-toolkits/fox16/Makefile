# New ports collection makefile for:	x11-toolkits/fox16
# Date created:		28 Jul 2005
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	${MAJORVER}.${SHVER}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.fox-toolkit.org/pub/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit -- ver.1.6

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

LATEST_LINK=	fox16

MAJORVER=	1.6
SHVER=		46
PLIST_SUB+=	MAJORVER=${MAJORVER} SHVER=${SHVER}

USE_GNOME=	lthack gnomehack
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-opengl --with-x
USE_LDCONFIG=	yes

MAN1=		shutterbug.1 reswrap.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	XFT	"Enable Xft support" on \
		SHM	"Enable Shared Memory support" on \
		CUPS	"Enable CUPS support" off \
		DEBUG	"Build with DEBUG support" off \
		FOX_APPLICATIONS	"Install sample applications" off \
		OPTIMIZED_CXXFLAGS	"Enable additional optimizations" off \
		PROFILING	"Build with PROFILING support" off

.include <bsd.port.pre.mk>

##
## Additional Options
##
#
.if defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--with-xft=no
.else
CONFIGURE_ARGS+=	--with-xft=yes
CPPFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`
.endif
#
.if defined(WITHOUT_SHM)
CONFIGURE_ARGS+=	--with-xshm=no
.else
CONFIGURE_ARGS+=	--with-xshm=yes
.endif
#
.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
.endif
#
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--enable-release
.endif
#
.if defined(WITH_FOX_APPLICATIONS)
MAN1+=		PathFinder.1 adie.1 calculator.1
PLIST_SUB+=	APPS=""
.else
PLIST_SUB+=	APPS="@comment "
.endif
#
.if defined(WITH_OPTIMIZED_CXXFLAGS)
# turn distribution-recommended optimization flags back on
CXXFLAGS+=	-O2 -Wuninitialized -ffast-math -finline-functions -fexpensive-optimizations
.if !defined(WITH_PROFILING)	# Incompatible with profiling flags
CXXFLAGS+=	-fomit-frame-pointer
.endif
.endif
#
.if defined(WITH_PROFILING)
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
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s/ doc//' \
		${WRKSRC}/Makefile.in
.endif
.if !defined(WITH_FOX_APPLICATIONS)
	@${REINPLACE_CMD} -E -e \
		's,^(SUBDIRS.*)adie,\1,; \
		s,^(SUBDIRS.*)pathfinder,\1,; \
		s,^(SUBDIRS.*)calculator,\1,' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
