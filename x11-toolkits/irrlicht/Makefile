# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	irrlicht
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SF/${PORTNAME}/Irrlicht%20SDK/${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance realtime 3D engine

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/readme.txt

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

DOS2UNIX_GLOB=	Makefile *.cpp *.h *.txt
USES=		alias dos2unix gmake zip
USE_GL=		gl
USE_XORG=	x11 xxf86vm
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

OPTIONS_DEFINE=	DEBUG EXAMPLES

DEBUG_MAKE_ENV_OFF=	NDEBUG=1

BROKEN_sparc64=	Does not compile

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == ia64
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e '/#define.*_IRR_USE_NON_SYSTEM_JPEG_LIB_/ d' \
		-e '/#define.*_IRR_USE_NON_SYSTEM_LIB_PNG_/ d' \
		-e '/#define.*_IRR_USE_NON_SYSTEM_ZLIB_/ d' \
		-e '/#define.*_IRR_USE_NON_SYSTEM_BZLIB_/ d' \
		-e '/#define.*_IRR_COMPILE_WITH_JOYSTICK_EVENTS_/ d' \
		${WRKSRC}/include/IrrCompileConfig.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/include && \
		${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD/libIrrlicht.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/FreeBSD/libIrrlicht.so.${SHARED_LIB_VER} \
		${STAGEDIR}${PREFIX}/lib && ${LN} -s libIrrlicht.so.${SHARED_LIB_VER} \
			${STAGEDIR}${PREFIX}/lib/libIrrlicht.so

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "${EXAMPLEDIRS}" ${STAGEDIR}${EXAMPLESDIR} "( -name Makefile -or -name *\.cpp -or -name *\.h )"
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/media
	cd ${WRKSRC}/media && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/media
.endif

.include <bsd.port.mk>
