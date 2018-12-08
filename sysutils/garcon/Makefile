# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	garcon
PORTVERSION=	0.6.2
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Freedesktop compliant menu library

# garcon's source code is licensed under GPLv2, while its
# documentation is under GFDL 1.1.
LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake libtool pathfix pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	glib20 gtk20 gtk30 intltool cairo gdkpixbuf2
USE_XFCE=	libmenu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--without-html-dir \
		--enable-gtk2

OPTIONS_DEFINE=		NLS
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=		yes

.include <bsd.port.mk>
