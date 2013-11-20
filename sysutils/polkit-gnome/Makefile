# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/polkit-gnome/Makefile 18866 2013-11-08 11:27:41Z gusi $

PORTNAME=	polkit-gnome
PORTVERSION=	0.105
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework

LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk20 gtk30 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-gtk=2.0 \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
