# New ports collection makefile for:	fox
# Date created:		23 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.0.53
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fox-toolkit.org/ftp/ \
		ftp://ftp.fox-toolkit.org/pub/ \
		ftp://ftp.uni-koeln.de/windows/xcontrib/ \
		ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/

MAINTAINER?=	araujo@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	fox-1.2.* fox-1.4.* fox-1.6.*

LATEST_LINK=	fox10

USE_AUTOTOOLS=	libtool:15
USE_GL=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-opengl=mesa --with-x

MAN1=	reswrap.1

OPTIONS=	SHM	"Enable Shared Memory support" on \
		CUPS	"Enable CUPS support" off \
		DEBUG	"Build with DEBUG support" off \
		FOX_APPLICATIONS	"Install sample applications" off \
		OPTIMIZED_CXXFLAGS	"Enable additional optimizations" off \
		PROFILING	"Build with PROFILING support" off

##
## Additional Options
##
#
.if defined(WITHOUT_SHM)
CONFIGURE_ARGS+=--with-shm=no
.else
CONFIGURE_ARGS+=--with-shm=yes
.endif
#
.if defined(WITH_CUPS)
CONFIGURE_ARGS+=--enable-cups
.else
CONFIGURE_ARGS+=--disable-cups
.endif
#
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--enable-release
.endif
#
.if defined(WITH_FOX_APPLICATIONS)
PLIST_SUB+=	APPS=""

MAN1+=	PathFinder.1 adie.1 calculator.1
.else
PLIST_SUB+=	APPS="@comment "
.endif

SPECFLAGS=	-ffast-math -finline-functions -fomit-frame-pointer -fexpensive-optimizations
#
.if defined(WITH_OPTIMIZED_CXXFLAGS)
# turn distribution-recommended optimization flags back on
CXXFLAGS+=	-Wuninitialized ${SPECFLAGS}
.endif
#
.if defined(WITH_PROFILING)
CONFIGURE_ARGS+=--with-profiling=gprof
.endif

post-patch:
# Remove additional flags
	@${REINPLACE_CMD} -E -e \
		's|${SPECFLAGS}||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# CXXFLAGS safeness
.if !defined(WITH_OPTIMIZED_CXXFLAGS)
	@${REINPLACE_CMD} -E -e \
		's|-O2|${CXXFLAGS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.else
	@${REINPLACE_CMD} -E -e \
		's|-O2|-O2 ${CXXFLAGS}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
	@${REINPLACE_CMD} -E -e \
		's|lMesaGL|lGL|g' \
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

.include <bsd.port.mk>
