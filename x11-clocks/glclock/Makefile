# Created by: Randall Hopper <aa8vb@ipass.net>

PORTNAME=	glclock
DISTVERSION=	6.0b6.0
PORTREVISION=	7
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL spinning pocket watch demo and benchmark utility

USES=		gl xorg
USE_XORG=	xi xmu xext x11
USE_GL=		gl glu glut
MAKEFILE=	makefile

CFLAGS+=	-DIMAGE_PATH="\\\"${PREFIX}/lib/X11/glclock/\\\""

PLIST_FILES=	${PROGRAMS:S,^,bin/,} ${SCRIPTS:S,^,bin/,} \
		${TEXTURES:S,^,lib/X11/glclock/,}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=\
		-O3 -fexpensive-optimizations -ffast-math \
		-fomit-frame-pointer

PROGRAMS=	glclock glclockmark
SCRIPTS=	chromeclock chromeclock_L crystalclock crystalclock_L \
		glclock_L glclockmark_ALL marbleclock marbleclock_L \
		metalclock metalclock_L mwclock mwclock_L woodclock \
		woodclock_L
TEXTURES=	light.ppm marble.ppm sky.ppm wood.ppm detail.pgm \
		detail2.pgm detail_b.pgm filter.pgm

post-patch:
	@${REINPLACE_CMD} -e \
		's|g\+\+|$${CXX}| ; \
		 s|-O2|$${CXXFLAGS}| ; \
		 s|/usr/X11R6|$${LOCALBASE}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|glPolygonOffsetEXT|glPolygonOffset|' \
		${WRKSRC}/GLextensions.cpp

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/glclock
	${INSTALL_DATA} ${TEXTURES:S,^,${WRKSRC}/,} \
		${STAGEDIR}${PREFIX}/lib/X11/glclock

.include <bsd.port.mk>
