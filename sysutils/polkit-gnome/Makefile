PORTNAME=	polkit-gnome
PORTVERSION=	0.105
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework
WWW=		https://www.freedesktop.org/wiki/Software/polkit/

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		gettext gmake gnome pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
