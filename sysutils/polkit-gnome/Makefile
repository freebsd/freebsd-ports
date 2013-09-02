# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/polkit-gnome/Makefile,v 1.20 2012/12/18 13:05:11 kwm Exp $

PORTNAME=	polkit-gnome
PORTVERSION=	0.102
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework

LIB_DEPENDS=	polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehack gnomeprefix gtk20 intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-gtk=2.0 \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
