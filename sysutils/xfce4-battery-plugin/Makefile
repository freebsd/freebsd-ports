# New ports collection makefile for:	xfce-battery-plugin
# Date created:		31 June 2003
# Whom:			Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	xfce4-battery-plugin
PORTVERSION=	1.0.5
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Battery monitor panel plugin for Xfce4

ONLY_FOR_ARCHS=	i386 amd64

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack pkgconfig
USE_XFCE=	configenv libmenu libutil panel
INSTALLS_ICONS=	yes

OPTIONS_DEFINE= NLS
OPTIONS_DEFAULT=        NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
