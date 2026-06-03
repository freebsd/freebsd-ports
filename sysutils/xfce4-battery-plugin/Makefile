PORTNAME=	xfce4-battery-plugin
PORTVERSION=	1.2.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Battery monitor panel plugin for Xfce4
WWW=		https://docs.xfce.org/panel-plugins/xfce4-battery-plugin/start

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

USES=		gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_LDCONFIG=	yes
USE_XFCE=	libmenu panel

SSP_UNSAFE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
