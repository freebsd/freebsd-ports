PORTNAME=	xfce4-dict
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	textproc xfce
MASTER_SITES=	XFCE/apps
PKGNAMESUFFIX=	-plugin
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce4 plugin to query different dictionaries
WWW=		https://goodies.xfce.org/projects/applications/xfce4-dict

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libmenu panel
USE_XORG=	x11
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
