PORTNAME=	libde265
DISTVERSION=	1.0.19
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/strukturag/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source h.265 video codec
WWW=		https://www.libde265.org

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lib cpe pkgconfig
CPE_VENDOR=	struktur
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON \
		-DENABLE_ENCODER:BOOL=OFF \
		-DENABLE_INTERNAL_DEVELOPMENT_TOOLS:BOOL=OFF

OPTIONS_DEFINE=		SDL
OPTIONS_DEFAULT=	SDL
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CMAKE_BOOL=		ENABLE_SDL

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/dec265 \
		${STAGEDIR}${PREFIX}/bin/libde265-dec265

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
CMAKE_ARGS+=	-DCMAKE_ASM_FLAGS="${CFLAGS} -B${LOCALBASE}/bin -no-integrated-as"
LLD_UNSAFE=	yes
.endif

.include <bsd.port.post.mk>
