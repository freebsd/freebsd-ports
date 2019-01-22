# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-appfinder
PORTVERSION=	4.12.0
PORTREVISION=	1
CATEGORIES=	misc xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application launcher and finder

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake gnome pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 intlhack intltool
USE_XFCE=	garcon

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		GTK3 NLS
OPTIONS_SUB=		yes

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE_OFF=		gnome=gtk20
GTK3_USE=		gnome=gtk30
GTK3_USES_OFF=		xfce
GTK3_USES=		xfce:gtk3

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
	${REINPLACE_CMD} -e 's|=gtk-find|=system-search|' \
		${WRKSRC}/data/xfce4-appfinder.desktop.in
	${REINPLACE_CMD} -e 's|=gtk-execute|=system-run|' \
		${WRKSRC}/data/xfce4-run.desktop.in

.include <bsd.port.mk>
