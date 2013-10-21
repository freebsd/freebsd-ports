# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	libxfce4gui
PORTVERSION=	4.10.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/archive/libxfcegui4/${PORTVERSION:R}
DISTNAME=	libxfcegui4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Various Gtk widgets for the Xfce Desktop

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 intltool intlhack libglade2
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil
USE_XORG=	sm x11
USES=	pathfix pkgconfig gmake

CONFIGURE_ARGS+=--disable-gladeui

OPTIONS_DEFINE=		DOCS NLS STARTUP
OPTIONS_DEFAULT=	STARTUP
STARTUP_DESC=	Startup notification

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.include <bsd.port.mk>
