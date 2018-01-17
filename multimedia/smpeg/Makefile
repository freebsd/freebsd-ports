# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smpeg
PORTVERSION=	0.4.4
PORTREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		GENTOO

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free MPEG1 video player library with sound support

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		compiler:features gmake libtool
USE_SDL=	sdl
USE_LDCONFIG=	yes
CONFIGURE_ENV=	GLBASE="${LOCALBASE}" \
		CC="${CXX}" REAL_CC="${CC}" \
		SDL_CONFIG="${SDL_CONFIG}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${COMPILER_FEATURES:Mc++11:C/.+/-Wno-error=narrowing/}

#If you want to try the opengl/gtk player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player \
		--disable-gtk-player \
		--enable-mmx

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsmpeg.so

.include <bsd.port.mk>
