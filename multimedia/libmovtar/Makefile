# New ports collection makefile for:	libmovtar
# Date created:		Mon Oct 15 23:35:04 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmovtar
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mjpeg

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Supports reading/writing of MJPEG video in YUV 4:2:2 JPEG

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-m4data-prefix=${PREFIX}/share
CONFIGURE_ENV=  SDL_CONFIG="${SDL_CONFIG}" \
		LOCALBASE="${LOCALBASE}"
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}

SDL_CONFIG?=    ${LOCALBASE}/bin/sdl11-config

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' \
		${WRKSRC}/rtjpeg/rtjshow.c \
		${WRKSRC}/movtar_play.c
	@${REINPLACE_CMD} -E -e 's|^(LIBS="-ljpeg )|\1 -L${LOCALBASE}/lib|; \
		s|(LIBS -ljpeg)"|\1 -L${LOCALBASE}/lib"|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if ${ARCH} != "i386"
# emms opcode should be noop in non-i386 non-MMX ARCH
		@${REINPLACE_CMD} -E \
		-e 's|^.*"emms".*$$||' \
		${WRKSRC}/movtar_play.c
.endif

.include <bsd.port.post.mk>
