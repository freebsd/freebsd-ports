# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	stoken
PORTVERSION=	0.6
CATEGORIES=	security
MASTER_SITES=	SF/stoken

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Software Token for UNIX compatible with RSA SecurID

LICENSE=	GPLv2

LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_CONFIGURE_WITH=	gtk
X11_DESC=	Build GUI token interface
X11_USE=		GNOME=gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfigdir="${PREFIX}/libdata/pkgconfig"

USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USES=		pkgconfig libtool

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
