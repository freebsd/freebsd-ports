# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmpeg2
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free library for decoding MPEG-2 and MPEG-1 video streams

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared

PORTDOCS=	libmpeg2.txt README

OPTIONS_DEFINE=	DOCS SDL X11

SDL_USE=	SDL=yes
SDL_CONFIGURE_ENABLE=	sdl
X11_USE=	XORG=sm,xv
X11_CONFIGURE_WITH=	x

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| -O3|| ; s|<termio|&s|' \
		${WRKSRC}/configure
# AMD64 prefers position independent code
.if ${ARCH:L} == "amd64"
	@${REINPLACE_CMD} -e '/CFLAGS/s| -prefer-non-pic||' \
		${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libmpeg2.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/libvo/libvo.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/video_out.h \
		${STAGEDIR}${PREFIX}/include/mpeg2dec
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpeg2convert.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmpeg2.so.0

.include <bsd.port.mk>
