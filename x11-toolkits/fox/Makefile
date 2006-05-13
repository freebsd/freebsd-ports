# New ports collection makefile for:	fox
# Date created:		23 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	1.0.48
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fox-toolkit.org/ftp/ \
		ftp://ftp.fox-toolkit.org/pub/ \
		ftp://ftp.uni-koeln.de/windows/xcontrib/ \
		ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	fox-1.1.*

USE_GL=		yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-opengl=mesa --with-x

MAN1=	reswrap.1

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
#
.if defined(NOPORTDOCS)
MAKE_ARGS+=	DOC=
.else
MAKE_ARGS+=	DOC=doc
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
.if !defined(WITH_FOX_APPLICATIONS)
	@${REINPLACE_CMD} -E -e \
		's,^(SUBDIRS.*)adie,\1,; \
		s,^(SUBDIRS.*)pathfinder,\1,; \
		s,^(SUBDIRS.*)calculator,\1,' \
		${WRKSRC}/Makefile.in
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CXXFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can enable additional compilation optimizations'
	@${ECHO_MSG} 'by defining WITH_OPTIMIZED_CXXFLAGS'
.endif
.if !defined(WITH_CUPS)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can enable CUPS support by defining WITH_CUPS'
.endif
.if !defined(WITH_DEBUG)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can build DEBUG support by defining WITH_DEBUG'
.endif
.if !defined(WITH_FOX_APPLICATIONS)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can install FOX sample applications by defining WITH_FOX_APPLICATIONS'
.endif
.if !defined(WITH_PROFILING)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can build PROFILING support by defining WITH_PROFILING'
.endif
.if !defined(WITHOUT_SHM)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can disable Shared Memory support by defining WITHOUT_SHM'
.endif
	@${ECHO_MSG}

.include <bsd.port.mk>
