PORTNAME=	xfce4-calculator-plugin
PORTVERSION=	0.8.0
CATEGORIES=	math xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple calculator for the Xfce panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-calculator-plugin/start

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel
USE_XORG=	x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
