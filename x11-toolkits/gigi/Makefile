# Created by: alepulver
# $FreeBSD$

PORTNAME=	gigi
PORTVERSION=	0.8.0.1074
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	oliver

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	OpenGL Graphic User Interface Library

LIB_DEPENDS=	libIL.so:${PORTSDIR}/graphics/devil \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libfreetype.so:${PORTSDIR}/print/freetype2

BROKEN=		Does not compile on 10 or higher
DEPRECATED=	Does not compile on 10 or higher
EXPIRATION_DATE=2014-04-30

USE_GCC=	yes
USES=		cmake
CMAKE_ARGS=	-DBUILD_TUTORIALS:BOOL=OFF
USE_BZIP2=	yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
# Ensure local headers are found first, otherwise updating would fail.
CFLAGS+=	-I.

OPTIONS_DEFINE=	OGRE
OGRE_DESC=	Ogre (3D engine) support

SHLIB_VER=	0
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
GIGI_LIBS=	GiGi GiGiSDL
WRKSRC=		${WRKDIR}/gigi/GG

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOGRE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
RUN_DEPENDS+=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
PLIST_SUB+=	OGRE=""
GIGI_LIBS+=	GiGiOgre GiGiOgrePlugin_OIS
.else
CMAKE_ARGS+=	-DBUILD_OGRE_DRIVER:BOOL=OFF -DBUILD_OGRE_OIS_PLUGIN:BOOL=OFF
PLIST_SUB+=	OGRE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|TIME_UTC)|TIME_UTC_)|' \
		${WRKSRC}/src/GUI.cpp
	@${REINPLACE_CMD} -e 's| move_backward| ::adobe::move_backward|g' \
		${WRKSRC}/GG/adobe/vector.hpp
post-build:
	@${REINPLACE_CMD} -Ee 's,^prefix=.*,prefix=${PREFIX},' \
		${WRKSRC}/*.pc

do-install:
	${MKDIR} ${PREFIX}/include/GG
	cd ${WRKSRC}/GG && ${FIND} . -name "*.h" -o -name "*.hpp" -depth | ${CPIO} -pdmv ${PREFIX}/include/GG
.for lib in ${GIGI_LIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/lib${lib}.so \
		${PREFIX}/lib/lib${lib}.so.${SHLIB_VER}
	cd ${PREFIX}/lib && ${LN} -sf lib${lib}.so.${SHLIB_VER} lib${lib}.so
	-[ -f ${WRKSRC}/${lib}.pc ] && ${INSTALL_DATA} ${WRKSRC}/${lib}.pc ${PREFIX}/libdata/pkgconfig
.endfor

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r 1074 https://${PORTNAME}.svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.mk>
