# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/sysutils/drwright/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	drwright
PORTVERSION=	3.2.5
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 RSI prevention tool

LIB_DEPENDS=	libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3 \
		libnotify.so:${PORTSDIR}/devel/libnotify

NO_STAGE=	yes
USE_XZ=		yes
USE_GNOME=	intlhack gtk30 gnomecontrolcenter3
USE_XORG=	x11 xscrnsaver
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.settings-daemon.plugins.typing-break.gschema.xml

.include <bsd.port.mk>
