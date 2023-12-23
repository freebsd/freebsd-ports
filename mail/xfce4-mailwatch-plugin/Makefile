PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	mail xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mail notification applet for the Xfce panel
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-mailwatch-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libexo panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		IPV6 NLS
OPTIONS_SUB=		yes

IPV6_CONFIGURE_ENABLE=	ipv6

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's|xfce-mail|mail-send|' \
		${WRKSRC}/panel-plugin/mailwatch-plugin.c

.include <bsd.port.mk>
