# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmpeg2
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Free library for decoding mpeg-2 and mpeg-1 video streams

USES=		pathfix
USE_GNOME=	ltverhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared

MAN1=	extract_mpeg2.1 mpeg2dec.1

PORTDOCS=	libmpeg2.txt README

OPTIONS_DEFINE=	DOCS SDL X11

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	yes
CONFIGURE_ARGS+=	--enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	sm xv
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.include <bsd.port.pre.mk>

# We must be able to build EV6 code; actual CPU-type optimizations
# are chosen at runtime.
.if ${ARCH} == "alpha"
CFLAGS:=	${CFLAGS:N-mcpu=*}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||;s|<termio.h>|<termios.h>|' \
		${WRKSRC}/configure
# AMD64 prefers position independent code
.if ${ARCH:L} == "amd64"
	@${REINPLACE_CMD} -e 's|-prefer-non-pic||' \
		${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libmpeg2.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/libvo/libvo.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/video_out.h \
		${PREFIX}/include/mpeg2dec

.include <bsd.port.post.mk>
