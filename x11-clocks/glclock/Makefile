# Created by: Randall Hopper <aa8vb@ipass.net>
# $FreeBSD$

PORTNAME=	glclock
DISTVERSION=	6.0b6.0
PORTREVISION=	5
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL spinning pocket watch demo and benchmark utility

USE_XORG=	xi xmu xext x11
USE_GL=		gl glu glut
MAKEFILE=	makefile

CFLAGS+=	-DIMAGE_PATH="\\\"${PREFIX}/lib/X11/glclock/\\\""

PLIST_FILES=	${PROGRAMS:S,^,bin/,} ${SCRIPTS:S,^,bin/,} \
		${TEXTURES:S,^,lib/X11/glclock/,}
PLIST_DIRS=	lib/X11/glclock

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=\
		-O3 -fexpensive-optimizations -ffast-math \
		-fomit-frame-pointer -fforce-mem -fforce-addr

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

do-install:
.for i in ${PROGRAMS}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
.for i in ${SCRIPTS}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} \
		${STAGEDIR}${PREFIX}/bin)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/glclock
.for i in ${TEXTURES}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/X11/glclock)
.endfor

.include <bsd.port.mk>
