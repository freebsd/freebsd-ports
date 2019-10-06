# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	garcon
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Freedesktop compliant menu library

# garcon's source code is licensed under GPLv2, while its
# documentation is under GFDL 1.1.
LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libmenu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--without-html-dir

OPTIONS_DEFINE=		GTK2 NLS
OPTIONS_DEFAULT=	GTK2
OPTIONS_SUB=		yes

GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_ENABLE=	gtk2

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
