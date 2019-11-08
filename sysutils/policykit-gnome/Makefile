# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/policykit-gnome/Makefile,v 1.6 2008/10/03 17:19:43 marcus Exp $

PORTNAME=	policykit-gnome
PORTVERSION=	0.9.2
PORTREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/
DISTNAME=	PolicyKit-gnome-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework

LIB_DEPENDS=	libpolkit.so:sysutils/policykit

USES=		gettext gmake gnome libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gconf2 gnomedocutils intlhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	polkit-gnome.schemas

.include <bsd.port.mk>
