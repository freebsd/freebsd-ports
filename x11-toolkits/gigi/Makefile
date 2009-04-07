# New ports collection makefile for:	gigi
# Date created:				2007-04-29
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gigi
PORTVERSION=	0.7.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DISTNAME=	GG-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Graphic User Interface Library

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		boost_python.4:${PORTSDIR}/devel/boost-python \
		freetype.9:${PORTSDIR}/print/freetype2

USE_SCONS=	yes
SCONS_ARGS=	prefix="" pkgconfigdir=""
USE_SDL=	sdl
USE_LDCONFIG=	yes
# Ensure local headers are found first, otherwise updating would fail.
CFLAGS+=	-I.

OPTIONS=	OGRE "Enable Ogre (3D engine) support" off

SHLIB_VER=	0
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
GIGI_LIBS=	GiGi GiGiSDL

.include <bsd.port.pre.mk>

.if defined(WITH_OGRE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
RUN_DEPENDS+=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
PLIST_SUB+=	OGRE=""
GIGI_LIBS+=	GiGiOgre
.else
SCONS_ARGS+=	build_ogre_driver=0 build_ogre_ois_plugin=0
PLIST_SUB+=	OGRE="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	${REINPLACE_CMD} -E 's|#include <boost/serialization/is_abstract.hpp>||g; \
		s|BOOST_IS_ABSTRACT.*||g' \
		${WRKSRC}/GG/BrowseInfoWnd.h \
		${WRKSRC}/GG/Control.h
	@rm -f ${WRKSRC}/GG/BrowseInfoWnd.h.bak ${WRKSRC}/GG/Control.h.bak
	${REINPLACE_CMD} -E 's|system_error\(\) == EIO|code\(\) == boost::system::posix_error::io_error|g; \
		s|filesystem/cerrno|system/system_error|g' \
		${WRKSRC}/src/dialogs/FileDlg.cpp
# for graphics/ogre3d version 1.6.x
#	${REINPLACE_CMD} -E 's|CMPF_ALWAYS_PASS, 0)|CMPF_ALWAYS_PASS, 0, false)|g' \
#		${WRKSRC}/src/Ogre/OgreGUI.cpp

post-build:
	@${REINPLACE_CMD} -Ee 's,^(prefix|(lib|include)dir)=,&${PREFIX},' \
		${WRKSRC}/*.pc

do-install:
	${MKDIR} ${PREFIX}/include/GG
	${CP} -R ${WRKSRC}/GG/* ${PREFIX}/include/GG
.for lib in ${GIGI_LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/lib${lib}.so \
		${PREFIX}/lib/lib${lib}.so.${SHLIB_VER}
	cd ${PREFIX}/lib && ${LN} -sf lib${lib}.so.${SHLIB_VER} lib${lib}.so
	${INSTALL_DATA} ${WRKSRC}/${lib}.pc ${PREFIX}/libdata/pkgconfig
.endfor

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://${PORTNAME}.svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.post.mk>
