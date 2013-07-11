# Created by: Anderson S. Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	tuntun
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	security gnome
MASTER_SITES=	http://tuntun.googlecode.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome applet gui for OpenVPN

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify

USES=		gmake pkgconfig pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	`pkg-config --cflags libgnomeui-2.0`
CONFIGURE_ARGS=	--libdir=${PREFIX}/libdata/servers

USE_GNOME=	gnomehier intlhack gnomeprefix gnomepanel glib20 libgnomeui

.include <bsd.port.mk>
