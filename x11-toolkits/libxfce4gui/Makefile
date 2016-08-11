# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	libxfce4gui
PORTVERSION=	4.10.0
PORTREVISION=	5
CATEGORIES=	x11-toolkits xfce
MASTER_SITES=	XFCE/src/archive/libxfcegui4/${PORTVERSION:R}
DISTNAME=	libxfcegui4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Various Gtk widgets for the Xfce Desktop

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gmake libtool pathfix pkgconfig gettext-tools xfce tar:bzip2
USE_GNOME=	gtk20 intltool intlhack libglade2
USE_LDCONFIG=	yes
USE_XFCE=	libutil
USE_XORG=	sm x11

CONFIGURE_ARGS+=--disable-gladeui --disable-static \
	--without-html-dir

OPTIONS_DEFINE=		NLS STARTUP
OPTIONS_DEFAULT=	STARTUP
STARTUP_DESC=	Startup notification
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
STARTUP_LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification
STARTUP_CONFIGURE_ENABLE=	startup-notification
OPTIONS_SUB=	yes

.include <bsd.port.mk>
