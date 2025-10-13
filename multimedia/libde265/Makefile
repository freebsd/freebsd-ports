PORTNAME=	libde265
DISTVERSION=	1.0.16
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/strukturag/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source h.265 video codec
WWW=		https://www.libde265.org

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib cpe libtool pathfix pkgconfig
CPE_VENDOR=	struktur
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-sherlock265
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		SDL
OPTIONS_DEFAULT=	SDL
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_ENABLE=	sdl2

_BIN=	bjoentegaard block-rate-estim dec265 gen-enc-table rd-curves tests \
	yuv-distortion

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CONFIGURE_ENV+=	CCASFLAGS="${CFLAGS} -B${LOCALBASE}/bin -no-integrated-as"
LLD_UNSAFE=	yes
.endif

post-install:
.for F in ${_BIN}
	${MV} ${STAGEDIR}${PREFIX}/bin/${F} \
		${STAGEDIR}${PREFIX}/bin/libde265-${F}
.endfor

.include <bsd.port.post.mk>
