# Created by: Matt Lancereau <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-genmon-plugin
PORTVERSION=	4.0.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Generic Monitor Xfce4 panel plugin

LICENSE=	LGPL21

USES=		gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce:gtk3
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
