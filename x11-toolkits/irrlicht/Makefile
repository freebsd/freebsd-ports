# New ports collection makefile for:	irrlicht
# Date created:				19 September 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	irrlicht
PORTVERSION=	0.12.0
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance realtime 3D engine

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GL=		yes
USE_ZIP=	yes
WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}/source/Irrlicht
INSTALLS_SHLIB=	yes
SHARED_LIB_VER=	2
PLIST_SUB+=	SHARED_LIB_VER=${SHARED_LIB_VER}

EXAMPLEDIRS=	01.HelloWorld 02.Quake3Map 03.CustomSceneNode 04.Movement 05.UserInterface \
		06.2DGraphics 07.Collision 08.SpecialFX 09.Meshviewer 10.Shaders \
		11.PerPixelLighting 12.TerrainRendering 13.RenderToTexture Demo

.include <bsd.port.pre.mk>

.if (${ARCH} == amd64) || (${ARCH} == ia64)
CFLAGS+=	-fPIC
.endif

# g++ 2.95.4 does not support the language features used by Irrlicht
USE_GCC=	3.3+

PORTDOCS=	examples media

# The source resides in a zip file inside the distribution archive
post-extract:
	@cd ${WRKBASE}/source && \
		${UNZIP_CMD} -a source.zip > /dev/null
	@${RM} -rf ${WRKSRC}/zlib ${WRKSRC}/jpeglib ${WRKSRC}/libpng

do-install:
	${MKDIR} ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libIrrlicht.so.${PORTVERSION} ${PREFIX}/lib/libIrrlicht.so.${SHARED_LIB_VER}
	cd ${PREFIX}/lib && ${RM} -f libIrrlicht.so &&  ${LN} libIrrlicht.so.${SHARED_LIB_VER} libIrrlicht.so
	${MKDIR} ${PREFIX}/include/irrlicht
	${FIND} ${WRKSRC}/include -name "*.h" -exec ${INSTALL_DATA} {} \
		${PREFIX}/include/irrlicht \;

.if !defined(NOPORTDOCS)
# These are example applications.
.for dir in ${EXAMPLEDIRS}
	${MKDIR} ${DOCSDIR}/examples/${dir}
	${REINPLACE_CMD}	-e 's|../../include|${PREFIX}/include/${PORTNAME}|' \
				-e 's|../../lib/Linux|${PREFIX}/lib|' \
		${WRKBASE}/examples/${dir}/Makefile
	${INSTALL_DATA} ${WRKBASE}/examples/${dir}/Makefile \
		${DOCSDIR}/examples/${dir}
	${FIND} ${WRKBASE}/examples/${dir} \( -name "*.cpp" -or -name "*.h" \) \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/examples/${dir} \;
.endfor
	${MKDIR} ${DOCSDIR}/media
	${FIND} ${WRKBASE}/media -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/media \;
.endif

.include <bsd.port.post.mk>
