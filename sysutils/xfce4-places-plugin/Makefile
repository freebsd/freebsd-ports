# $FreeBSD$

PORTNAME=	xfce4-places-plugin
PORTVERSION=	1.8.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	File browser launcher for Xfce4 panel plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	panel thunar
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

.include <bsd.port.mk>
