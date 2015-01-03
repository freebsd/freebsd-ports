# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-appfinder
PORTVERSION=	4.10.1
PORTREVISION=	1
CATEGORIES=	misc xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application launcher and finder

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20 glib20 intltool intlhack
USE_XFCE=	configenv garcon libmenu libutil xfconf

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=--enable-nls
.else
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
	${REINPLACE_CMD} -e 's|=gtk-find|=system-search|' \
		${WRKSRC}/data/xfce4-appfinder.desktop.in
	${REINPLACE_CMD} -e 's|=gtk-execute|=system-run|' \
		${WRKSRC}/data/xfce4-run.desktop.in

.include <bsd.port.mk>
