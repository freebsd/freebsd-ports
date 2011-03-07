# New ports collection makefile for:	irrlicht
# Date created:				19 September 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	irrlicht
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SF/${PORTNAME}/Irrlicht%20SDK/1.7/${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	High performance realtime 3D engine

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_DOS2UNIX=	Makefile *.cpp *.h *.txt
USE_GMAKE=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
MAKE_ENV+=	SHLIB_VER=${SHARED_LIB_VER}

PLIST_SUB+=	SHARED_LIB_VER=${SHARED_LIB_VER}
SUB_FILES=	pkg-message
BUILD_WRKSRC=	${WRKSRC}/source/Irrlicht

SHARED_LIB_VER=	1
EXAMPLEDIRS=	01.HelloWorld 02.Quake3Map 03.CustomSceneNode 04.Movement 05.UserInterface \
		06.2DGraphics 07.Collision 08.SpecialFX 09.Meshviewer 10.Shaders \
		11.PerPixelLighting 12.TerrainRendering 13.RenderToTexture 15.LoadIrrFile \
		Demo

OPTIONS=	DEBUG	"Compile with debugging simbols" off \
		EXAMPLES	"Install example files"	on \
		JOYSTICK	"Support for Linux Joystick" off

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
CFLAGS+=	-fPIC
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if !defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if defined(WITH_JOYSTICK)
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
HAVE_JOYSTICK=	true
.endif

.if !defined(WITH_DEBUG)
MAKE_ENV+=	NDEBUG=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/source/Irrlicht/CImageLoaderPNG.cpp
.if !defined(HAVE_JOYSTICK)
	@${REINPLACE_CMD} -e '/define.*_IRR_COMPILE_WITH_JOYSTICK_EVENTS_/ d' \
		${WRKSRC}/include/IrrCompileConfig.h
.endif

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/include && \
		${INSTALL_DATA} *.h ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD/libIrrlicht.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/FreeBSD/libIrrlicht.so.${SHARED_LIB_VER} \
		${PREFIX}/lib && ${LN} -s libIrrlicht.so.${SHARED_LIB_VER} \
			${PREFIX}/lib/libIrrlicht.so

.if !defined(WITHOUT_EXAMPLES)
.for DIRE in ${EXAMPLEDIRS}
	${MKDIR} ${EXAMPLESDIR}/${DIRE}
	${INSTALL_DATA} ${WRKSRC}/examples/${DIRE}/Makefile \
		${EXAMPLESDIR}/${DIRE}
	${FIND} ${WRKSRC}/examples/${DIRE} \( -name "*.cpp" -or -name "*.h" \) \
		-exec ${INSTALL_DATA} "{}" ${EXAMPLESDIR}/${DIRE} \;
.endfor
	${MKDIR} ${EXAMPLESDIR}/media
	${FIND} ${WRKSRC}/media -type f \
		-exec ${INSTALL_DATA} "{}" ${EXAMPLESDIR}/media \;
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
