# Created by: Thorsten Greiner <thorsten.greiner@web.de>
# $FreeBSD$

PORTNAME=	xfce4-systemload-plugin
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	System Load plugin for Xfce4 panel

LICENSE=	BSD

LIB_DEPENDS=	libupower-glib.so:${PORTSDIR}/sysutils/upower

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil panel

OPTIONS_DEFINE= NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.mk>
