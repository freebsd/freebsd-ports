# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smpeg
PORTVERSION=	0.4.4
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free MPEG1 video player library with sound support

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
CONFIGURE_ENV=	GLBASE="${LOCALBASE}" \
		CC="${CXX}" REAL_CC="${CC}" \
		SDL_CONFIG="${SDL_CONFIG}"
CPPFLAGS+=	-I${LOCALBASE}/include

#If you want to try the opengl/gtk player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player \
		--disable-gtk-player \
		--enable-mmx

MAN1=		gtv.1 plaympeg.1

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
