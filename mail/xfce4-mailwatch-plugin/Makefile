PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.4.0
CATEGORIES=	mail xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mail notification applet for the Xfce panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-mailwatch-plugin/start

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	glib20 gtk30
USE_XFCE=	libexo panel
USE_XORG=	x11

OPTIONS_DEFINE=	IPV6 NLS
OPTIONS_SUB=	yes

IPV6_MESON_ENABLED=	ipv6

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
