# Created by: Lars Koeller
# $FreeBSD$

PORTNAME=	hp2xx
PORTVERSION=	3.4.4
PORTREVISION=	5
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HPGL to vector and raster formats converter and previewer for X11

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${DISTNAME}/sources

USES=		makeinfo
MAKE_ENV=	DEFINES="${CPPFLAGS}" ALL_LIBS="${LDFLAGS}"

PLIST_FILES=	bin/hp2xx man/man1/hp2xx.1.gz
INFO=		hp2xx

CPPFLAGS+=	-DUNIX -I${LOCALBASE}/include
LDFLAGS+=	-lm -L${LOCALBASE}/lib -ltiff -lpng -lz

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=	XORG=x11
X11_CPPFLAGS=	-DHAS_UNIX_X11 -I${LOCALBASE}/include
X11_LDFLAGS=	-L${LOCALBASE}/lib -lX11
X11_MAKE_ENV=		PREVIEWER=to_x11
X11_MAKE_ENV_OFF=	PREVIEWER=no_prev

post-patch:
	@${REINPLACE_CMD} -E 's,(bin|info|man1)dir),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
