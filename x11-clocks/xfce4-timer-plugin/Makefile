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

USES=		libtool pkgconfig gettext gmake xfce:gtk3 tar:bzip2
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gtk30 intltool
USE_XFCE=	panel

.include <bsd.port.mk>
