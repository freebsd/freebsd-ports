# New ports collection makefile for:	irrlicht
# Date created:				19 September 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	irrlicht
PORTVERSION=	0.10.0
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	barner@gmx.de
COMMENT=	High performance realtime 3D engine

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GL=		yes
USE_ZIP=	yes
USE_REINPLACE=	yes
WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}/source/Irrlicht
INSTALLS_SHLIB=	yes

EXAMPLEDIRS=	01.HelloWorld 02.Quake3Map 03.CustomSceneNode 04.Movement 05.UserInterface \
		06.2DGraphics 07.Collision 08.SpecialFX 09.Meshviewer 10.Shaders \
		11.PerPixelLighting 12.TerrainRendering 13.RenderToTexture Demo

.include <bsd.port.pre.mk>

# g++ 2.95.4 does not support the language features used by Irrlicht
USE_GCC=	3.3+

.if !defined(NOPORTDOCS)
PORTDOCS=	examples media
POST_INSTALL_SEQ+=	doc-install
.endif

# The source is resides in a zip file inside the distribution archive
post-extract:
	@cd ${WRKBASE}/source && \
		${UNZIP_CMD} -a source.zip > /dev/null
	@${RM} -rf ${WRKSRC}/zlib ${WRKSRC}/jpeglib ${WRKSRC}/libpng

do-install:
	@${MKDIR} ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/libIrrlicht.a ${PREFIX}/lib
	@${INSTALL_PROGRAM} ${WRKSRC}/libIrrlicht.so.1 ${PREFIX}/lib
	@cd ${PREFIX}/lib && ${RM} -f libIrrlicht.so &&  ${LN} libIrrlicht.so.1 libIrrlicht.so
	@${MKDIR} ${PREFIX}/include/irrlicht
	@${FIND} ${WRKSRC}/include -name "*.h" -exec ${INSTALL_DATA} {} \
		${PREFIX}/include/irrlicht \;

post-install: ${POST_INSTALL_SEQ}

doc-install:
# These are example applications.
.for dir in ${EXAMPLEDIRS}
	@${MKDIR} ${DOCSDIR}/examples/${dir}
	@${REINPLACE_CMD}	-e 's|../../include|${PREFIX}/include/${PORTNAME}|' \
				-e 's|../../lib/Linux|${LOCALBASE}/lib|' \
		${WRKBASE}/examples/${dir}/Makefile
	@${INSTALL_DATA} ${WRKBASE}/examples/${dir}/Makefile \
		${DOCSDIR}/examples/${dir}
	@${FIND} ${WRKBASE}/examples/${dir} \( -name "*.cpp" -or -name "*.h" \) \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/examples/${dir} \;
.endfor
	@${MKDIR} ${DOCSDIR}/media
	@${FIND} ${WRKBASE}/media -type f \
		-exec ${INSTALL_DATA} {} ${DOCSDIR}/media \;

.include <bsd.port.post.mk>
