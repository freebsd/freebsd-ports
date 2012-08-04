# New ports collection makefile for:	glclock
# Date created:		20 September 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	glclock
DISTVERSION=	6.0b6.0
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL spinning pocket watch demo and benchmark utility

USE_XORG=	xi xmu xext x11
USE_GL=		gl glu glut
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" LN="${CXX}" OPT="${OPT}" \
		INCLUDE_PATH="-I${LOCALBASE}/include" \
		LIB_PATH="-L${LOCALBASE}/lib"

OPT=		-DIMAGE_PATH="\\\"${PREFIX}/lib/X11/glclock/\\\"" \
		${CFLAGS}

PROGRAMS=	glclock glclockmark

SCRIPTS=	chromeclock chromeclock_L crystalclock crystalclock_L \
		glclock_L glclockmark_ALL marbleclock marbleclock_L \
		metalclock metalclock_L mwclock mwclock_L woodclock \
		woodclock_L

TEXTURES=	light.ppm marble.ppm sky.ppm wood.ppm detail.pgm \
		detail2.pgm detail_b.pgm filter.pgm

PLIST_FILES=
.for f in ${PROGRAMS}
PLIST_FILES+=	bin/${f}
.endfor
.for f in ${SCRIPTS}
PLIST_FILES+=	bin/${f}
.endfor
.for f in ${TEXTURES}
PLIST_FILES+=	lib/X11/glclock/${f}
.endfor

PLIST_DIRS=	lib/X11/glclock

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fexpensive-optimizations \
		-fomit-frame-pointer -fforce-mem -fforce-addr
.if (${ARCH} != "alpha")
CFLAGS+=	-ffast-math
.endif
.endif

do-install:
.for f in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/lib/X11/glclock
.for f in ${TEXTURES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/X11/glclock
.endfor

.include <bsd.port.post.mk>
