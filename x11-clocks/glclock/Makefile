# New ports collection makefile for:	glclock
# Date created:		20 September 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	glclock
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Spinning pocketwatch demo and benchmark utility

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_X_PREFIX=	yes
USE_GL=		yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" LN="${CXX}" OPT="${OPT}" \
		INCLUDE_PATH="-I${X11BASE}/include" \
		LIB_PATH="-L${X11BASE}/lib" LIBS="${LIBS}"
ALL_TARGET=	${PORTNAME}

OPT=		${CXXFLAGS} ${PTHREAD_CFLAGS} \
		-DGLCLOCK_DIR="\\\"${PREFIX}/lib/X11/glclock/\\\""
LIBS=		-lglut -lGLU -lGL -lXext -lXmu -lX11 -lm -lXi ${PTHREAD_LIBS}

SCRIPTS=	benchclock crystalclock f_crystalclock f_glclock	\
	  f_marbleclock f_metalclock f_mwclock f_woodclock marbleclock	\
	  metalclock mwclock woodclock

TEXTURES=	marble.ppm sky.ppm wood.ppm

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CXXFLAGS+=	-O3 -fexpensive-optimizations \
		-fomit-frame-pointer -fforce-mem -fforce-addr
.if (${ARCH} != "alpha")
CXXFLAGS+=	-ffast-math
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glclock ${PREFIX}/bin
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/lib/X11/glclock
.for f in ${TEXTURES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/X11/glclock
.endfor

.include <bsd.port.post.mk>
