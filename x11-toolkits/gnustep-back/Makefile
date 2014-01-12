# $FreeBSD$

PORTNAME=	gnustep-back
PORTVERSION=	0.24.0
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core
PKGNAMESUFFIX?=	${BACK_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	GNUstep GUI backend

LIB_DEPENDS+=	gif.5:${PORTSDIR}/graphics/giflib
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-gif-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gif-include=${LOCALBASE}/include
USES=			pkgconfig
USE_GNUSTEP=		yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_XORG=		xft xrender xmu xext x11 xcursor xfixes xmu 
USE_GL=			yes

MAKE_FLAGS+=		OPTFLAG="${CFLAGS} -I${LOCALBASE}/include"
MAKE_ENV+=		GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
BACKVERSION=		${PORTVERSION:C/([0-9])*[.]([0-9]*).*/\1\2/1}
BREAKS_IF_PEDANTIC=	yes

CFLAGS+=		-I${LOCALBASE}/include/freetype2
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=	--enable-graphics=cairo --with-name=cairo
CONFIGURE_ARGS+=	--disable-glitz
PLIST_SUB+=		BACK=cairo-${BACKVERSION}
BACK_SUFFIX?=		-cairo

NO_STAGE=	yes
.include <bsd.port.pre.mk>

MAKE_FLAGS+=		messages=yes
PLIST_SUB+=		BACKVERSION=${PORTVERSION:C/([0-9])*[.]([0-9]*).*/\1\2/1}

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

.include <bsd.port.post.mk>
