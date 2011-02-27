# New ports collection makefile for:	TDFSB
# Date created:				31 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tdfsb
PORTVERSION=	0.0.9
PORTREVISION=	10
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.determinate.net/webdata/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D filesystem browser

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_GL=		glut
USE_SDL=	image sdl

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

COMPILE_SCRIPT=	compile.sh

do-build:
	@(cd ${BUILD_WRKSRC}; ${SH} ${COMPILE_SCRIPT})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

post-patch:
# Dirty hack below (ripping -lm) is needed in order to build the port on
# NVidia-infected system.  Without it, it may complain on conflicting
# libm.so versions (x11/nvidia-driver gets one via misc/compat5x port).
# However, since libGLU.so already depends on it, we should be fine.
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}| ; \
			s|gcc|${CC}| ; s| -lm|| ; \
			s|/usr/local|${LOCALBASE}|g ; \
			s|/usr/X11R6|${LOCALBASE}|g ; \
			s|-O2|${CFLAGS}|g' \
				${WRKSRC}/${COMPILE_SCRIPT}

.include <bsd.port.post.mk>
