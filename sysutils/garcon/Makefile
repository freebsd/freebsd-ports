PORTNAME=	garcon
PORTVERSION=	4.20.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Freedesktop compliant menu library
WWW=		https://gitlab.xfce.org/xfce/garcon

# garcon's source code is licensed under GPLv2, while its
# documentation is under GFDL 1.1.
LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes
USE_XFCE=	libmenu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR NLS
OPTIONS_DEFAULT=	GIR
OPTIONS_SUB=		yes

GIR_DESC=	Use Gobject Introspection

GIR_USE=		GNOME=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
