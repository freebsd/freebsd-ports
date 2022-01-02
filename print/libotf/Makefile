# Created by: Kimura Fuyuki <fuyuki@hadaly.org>

PORTNAME=	libotf
DISTVERSION=	0.9.16
PORTREVISION=	1
CATEGORIES=	print devel textproc
MASTER_SITES=	SAVANNAH/m17n

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Library for handling OpenType fonts

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf pathfix pkgconfig libtool:keepla
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_USES=		localbase xorg
X11_USE=		XORG=ice,sm,x11,xaw,xt,xmu
X11_CONFIGURE_WITH=	x

.include <bsd.port.mk>
