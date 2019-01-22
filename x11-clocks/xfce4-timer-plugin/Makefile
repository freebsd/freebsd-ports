# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-timer-plugin
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	x11-clocks xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Timer plugin for Xfce

LICENSE=	GPLv2

USES=		gettext gmake gnome libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	cairo gtk30 intltool
USE_XFCE=	panel

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
