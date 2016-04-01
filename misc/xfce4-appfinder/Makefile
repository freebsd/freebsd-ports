# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-appfinder
PORTVERSION=	4.12.0
CATEGORIES=	misc xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application launcher and finder

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig gettext-tools tar:bzip2
USE_GNOME=	glib20 intltool intlhack
USE_XFCE=	garcon

OPTIONS_DEFINE=	GTK3 NLS
GTK3_USES=	xfce:gtk3
GTK3_USE=	gnome=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USES_OFF=	xfce
GTK3_USE_OFF=	gnome=gtk20
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

post-patch:
	${REINPLACE_CMD} -e 's|=gtk-find|=system-search|' \
		${WRKSRC}/data/xfce4-appfinder.desktop.in
	${REINPLACE_CMD} -e 's|=gtk-execute|=system-run|' \
		${WRKSRC}/data/xfce4-run.desktop.in

.include <bsd.port.mk>
