PORTNAME=	xfce4-time-out-plugin
PORTVERSION=	1.2.0
CATEGORIES=	x11-clocks xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Time out plugin for Xfce
WWW=		https://docs.xfce.org/panel-plugins/xfce4-time-out-plugin/start

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel
USE_XORG=	x11

MESON_ARGS=	-Dx11=enabled

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
