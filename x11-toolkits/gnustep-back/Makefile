# $FreeBSD$

PORTNAME=	gnustep-back
PORTVERSION=	0.24.1
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	GNUSTEP/core

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep GUI backend

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

LIB_DEPENDS+=	libgif.so:${PORTSDIR}/graphics/giflib \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libXft.so:${PORTSDIR}/x11-fonts/libXft \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libcairo.so:${PORTSDIR}/graphics/cairo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tiff-library=${LOCALBASE}/lib \
		--with-tiff-include=${LOCALBASE}/include \
		--with-jpeg-library=${LOCALBASE}/lib \
		--with-jpeg-include=${LOCALBASE}/include \
		--with-gif-library=${LOCALBASE}/lib \
		--with-gif-include=${LOCALBASE}/include \
		--enable-graphics=cairo \
		--disable-glitz

USES=		gnustep jpeg pkgconfig
USE_GNUSTEP=	base gui build
USE_XORG=	xft xrender xmu xext x11 xcursor xfixes xmu
USE_GL=		yes
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

MAKE_FLAGS+=	OPTFLAG="${CFLAGS} -I${LOCALBASE}/include"
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
BACKVERSION=	${PORTVERSION:C/([0-9])*[.]([0-9]*).*/\1\2/1}

CFLAGS+=	-I${LOCALBASE}/include/freetype2
PLIST_SUB+=	BACK=back-${BACKVERSION}
PLIST_SUB+=	BACKVERSION=${PORTVERSION:C/([0-9])*[.]([0-9]*).*/\1\2/1}

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

.include <bsd.port.mk>
