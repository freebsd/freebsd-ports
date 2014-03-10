# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	irrlicht
PORTVERSION=	1.8
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SF/${PORTNAME}/Irrlicht%20SDK/${PORTVERSION}/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	High performance realtime 3D engine

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

DOS2UNIX_GLOB=	Makefile *.cpp *.h *.txt
USES=		dos2unix gmake zip
USE_GL=		yes
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ENV+=	SHLIB_VER=${SHARED_LIB_VER}

PLIST_SUB+=	SHARED_LIB_VER=${SHARED_LIB_VER}
SUB_FILES=	pkg-message
BUILD_WRKSRC=	${WRKSRC}/source/Irrlicht

SHARED_LIB_VER=	1
EXAMPLEDIRS=	01.HelloWorld 02.Quake3Map 03.CustomSceneNode 04.Movement 05.UserInterface \
		06.2DGraphics 07.Collision 08.SpecialFX 09.Meshviewer 10.Shaders \
		11.PerPixelLighting 12.TerrainRendering 13.RenderToTexture 15.LoadIrrFile \
		Demo

OPTIONS_DEFINE=	DEBUG EXAMPLES JOYSTICK
JOYSTICK_DESC=	Support for Linux Joystick

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
CFLAGS+=	-fPIC
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MJOYSTICK}
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
HAVE_JOYSTICK=	true
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	NDEBUG=1
.endif

post-extract:
#	@${RM} ${WRKSRC}/media/Thumbs.db

post-patch:
	@${REINPLACE_CMD} -e '/#define.*_IRR_USE_NON_SYSTEM_JPEG_LIB_/ d' \
		-e '/#define.*_IRR_USE_NON_SYSTEM_LIB_PNG_/ d' \
		-e '/#define.*_IRR_USE_NON_SYSTEM_ZLIB_/ d' \
		-e '/#define.*_IRR_USE_NON_SYSTEM_BZLIB_/ d' \
		${WRKSRC}/include/IrrCompileConfig.h
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

.if ${PORT_OPTIONS:MEXAMPLES}
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

.include <bsd.port.mk>
