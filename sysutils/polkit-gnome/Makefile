# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/polkit-gnome/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	polkit-gnome
PORTVERSION=	0.105
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework

LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk20 gtk30 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-gtk=2.0 \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
