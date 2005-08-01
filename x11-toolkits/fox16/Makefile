# New ports collection makefile for:	fox
# Date created:		28 Jul 2005
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	${MAJORVER}.${SHVER}
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.fox-toolkit.org/ftp/ \
		ftp://ftp.fox-toolkit.org/pub/ \
		http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER?=	alecn2002@yandex.ru
COMMENT=	Fast and extensive C++ GUI toolkit -- ver.1.2

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	fox-1.0.* fox-1.4.*

LATEST_LINK=	fox12

MAJORVER=	1.2
SHVER=		16
PLIST_SUB+=	MAJORVER=${MAJORVER} SHVER=${SHVER}

USE_GNOME=	lthack
USE_GL=		yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-opengl --with-x --enable-threadsafe
INSTALLS_SHLIB=	yes

MAN1=		shutterbug.1 reswrap.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

.include <bsd.port.pre.mk>

##
## Additional Options
##
#
.if ${X_WINDOW_SYSTEM:L} == xfree86-3 || defined(WITHOUT_XFT)
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
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
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
CXXFLAGS+=	-O2 -Wuninitialized -ffast-math -finline-functions -fomit-frame-pointer -fexpensive-optimizations
.endif
#
.if defined(WITH_PROFILING)
CONFIGURE_ARGS+=	--with-profiling=gprof
.endif
#
.if defined(NOPORTDOCS)
MAKE_ARGS+=	DOC=
.else
MAKE_ARGS+=	DOC=doc
.endif

post-patch:
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
.if !defined(WITHOUT_XFT)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can disable Xft support by defining WITHOUT_XFT'
.endif
	@${ECHO_MSG}

.include <bsd.port.post.mk>
