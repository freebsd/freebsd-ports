# Created by: Lars Koeller
# $FreeBSD$

PORTNAME=	hp2xx
PORTVERSION=	3.4.4
PORTREVISION=	7
CATEGORIES=	print x11
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HPGL to vector and raster formats converter and previewer for X11

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

WRKSRC_SUBDIR=	sources

USES=		makeinfo
MAKE_ENV=	DEFINES="${CPPFLAGS}" ALL_LIBS="${LDFLAGS}"

CPPFLAGS+=	-DUNIX -I${LOCALBASE}/include
LDFLAGS+=	-lm -L${LOCALBASE}/lib -ltiff -lpng -lz

INFO=		hp2xx
PLIST_FILES=	bin/hp2xx man/man1/hp2xx.1.gz

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11

X11_USE=		XORG=x11
X11_MAKE_ENV=		PREVIEWER=to_x11
X11_MAKE_ENV_OFF=	PREVIEWER=no_prev
X11_CPPFLAGS=		-DHAS_UNIX_X11 -I${LOCALBASE}/include
X11_LDFLAGS=		-L${LOCALBASE}/lib -lX11

.include <bsd.port.mk>
