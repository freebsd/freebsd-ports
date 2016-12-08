# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	g2ipmsg
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	http://ipmsg.org/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Popup style message communication tool for GNOME2

LICENSE=	GPLv2+

USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intltool libgnomeui
USE_GSTREAMER=	vorbis
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc \
		--enable-systray \
		--disable-applet \
		--with-ssl=${OPENSSLBASE}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	g2ipmsg.schemas

.include <bsd.port.mk>
