# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdv
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quasar DV codec (libdv): software codec for DV video encoding format

LICENSE=	LGPL21

LIB_DEPENDS=	libpopt.so:devel/popt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
LDFLAGS_i386=	-Wl,-znotext

DOCS=		AUTHORS COPYING COPYRIGHT ChangeLog NEWS README \
		README.dvconnect README.encoder TODO

OPTIONS_DEFINE=	SDL DOCS

SDL_USES=	sdl
SDL_USE=	SDL=sdl
SDL_CONFIGURE_ENABLE=	sdl

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|sys/types.h|' \
		${WRKSRC}/libdv/dv.h \
		${WRKSRC}/libdv/dv_types.h \
		${WRKSRC}/libdv/headers.c \
		${WRKSRC}/libdv/encode.c
	@${REINPLACE_CMD} -E -e 's|^void swab.+$$||' ${WRKSRC}/libdv/encode.c
	@${REINPLACE_CMD} -e 's|SDL/||' ${WRKSRC}/playdv/display.h
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/encodedv/dvavi.c \
		${WRKSRC}/encodedv/dvconnect.c
# XXX - revise at every port update
# protect popt from prefix changes
	@${REINPLACE_CMD} -E -e 's|(@REQUIRES_NOPKGCONFIG@)|-L${PREFIX}/include \1|' \
		${WRKSRC}/libdv.pc.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# XXX - work around compiler bug
# Optimizations -O{1,s,2,3} work
# However, lack of -O{1,s,2,3} or -O0 BREAK the build
# Therefore, make sure we have AT LEAST -O and avoid -O0
CFLAGS:=	-O ${CFLAGS:N-O0}
