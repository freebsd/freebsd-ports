# New ports collection makefile for:	fox
# Date created:		23 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	${MAJORVER}.${SHVER}
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fox-toolkit.org/ftp/ \
		ftp://ftp.fox-toolkit.org/pub/ \
		ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/ \
		http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Fast and extensive C++ GUI toolkit

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	fox-1.0.*

LATEST_LINK=	fox-devel

MAJORVER=	1.1
SHVER=		42
PLIST_SUB+=	MAJORVER=${MAJORVER} SHVER=${SHVER}

USE_GL=		yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
#USE_MOTIF=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS+=--with-opengl=mesa --with-x \
		--enable-xthreads

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
#
.if defined(WITH_OPTIMIZED_CXXFLAGS)
# turn distribution-recommended optimization flags back on
CXXFLAGS+=	-Wuninitialized -ffast-math -finline-functions -fomit-frame-pointer -fexpensive-optimizations
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
	@${ECHO_MSG} 'You can install FOX sample applications by defining WITH_FOX_APPLICATIONS"
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
