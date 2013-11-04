# Created by: Martin Wilke (freebsd@unixfreunde.de)
# $FreeBSD$

PORTNAME=	xfce4-messenger-plugin
PORTVERSION=	0.1.0
PORTREVISION=	18
CATEGORIES=	net-im xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/panel-plugins/4.4/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Messenger plugin for Xfce

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

DEPRECATED=	Deprecated and no update for 7 years
EXPIRATION_DATE=	2014-01-04

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libgui libutil panel
USE_XORG=	x11 xt xaw

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
