# Created by: Anderson S. Ferreira <anderson@cnpm.embrapa.br>
# $FreeBSD$

PORTNAME=	tuntun
PORTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	security gnome
MASTER_SITES=	http://tuntun.googlecode.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome applet gui for OpenVPN

DEPRECATED=	gnome-panel 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify

USES=		gmake pkgconfig pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	`pkg-config --cflags libgnomeui-2.0`
CONFIGURE_ARGS=	--libdir=${PREFIX}/libdata/servers

USE_GNOME=	gnomehier intlhack gnomeprefix gnomepanel glib20 libgnomeui

NO_STAGE=	yes
.include <bsd.port.mk>
