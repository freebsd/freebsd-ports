# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$
#

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	misc xfce geography
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce 4 weather module for xfce4-panel

LIB_DEPENDS=	soup-2:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		pkgconfig gettext pathfix
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack libxml2
USE_XFCE=	configenv libmenu libutil panel

OPTIONS_DEFINE=	UPOWER
UPOWER_DESC=	Power state support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUPOWER}
LIB_DEPENDS+=	upower-glib:${PORTSDIR}/sysutils/upower
CONFIGURE_ARGS+=--enable-upower
.else
CONFIGURE_ARGS+=--disable-upower
.endif

.include <bsd.port.mk>
