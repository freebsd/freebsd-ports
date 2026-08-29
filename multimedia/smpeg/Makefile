PORTNAME=	smpeg
DISTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free MPEG1 video player library with sound support
WWW=		http://icculus.org/smpeg/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	icculus
GH_TAGNAME=	release_${PORTVERSION:S/./_/g}

USES=		autoreconf compiler gmake libtool:build pkgconfig sdl
USE_SDL=	sdl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLBASE="${LOCALBASE}" \
		CC="${CC}" CXX="${CXX} -std=gnu++98" \
		SDL_CONFIG="${SDL_CONFIG}"
#If you want to try the opengl/gtk player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player \
		--disable-gtk-player \
		--enable-mmx
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-c++11-narrowing
LDFLAGS_i386=	-Wl,-znotext
MAKE_ARGS=	LIBTOOL=${LOCALBASE}/bin/libtool
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
