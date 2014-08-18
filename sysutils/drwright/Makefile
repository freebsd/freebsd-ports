# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/sysutils/drwright/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	drwright
PORTVERSION=	3.5.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 RSI prevention tool

LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libnotify.so:${PORTSDIR}/devel/libnotify

USE_GNOME=	intlhack gtk30 gnomecontrolcenter3
USE_XORG=	x11 xscrnsaver
USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.settings-daemon.plugins.typing-break.gschema.xml

.include <bsd.port.mk>
