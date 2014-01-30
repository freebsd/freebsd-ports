# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=	xfce4-systemload-plugin
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	System Load plugin for XFce4

LICENSE=	BSD

LIB_DEPENDS=	libupower-glib.so:${PORTSDIR}/sysutils/upower

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil panel
USES=	pkgconfig gmake

OPTIONS_DEFINE= NLS
OPTIONS_DEFAULT=        NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
