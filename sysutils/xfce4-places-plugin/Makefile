PORTNAME=	xfce4-places-plugin
PORTVERSION=	1.9.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	File browser launcher for Xfce4 panel plugin
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-places-plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	gtk30
USE_XFCE=	libexo libmenu panel xfconf
USE_XORG=	ice sm x11

MESON_ARGS=	-Dlibnotify=enabled

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
