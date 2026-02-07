PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.7.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device
WWW=		https://docs.xfce.org/panel-plugins/xfce4-wavelan-plugin/start

LICENSE=	BSD3CLAUSE

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	libmenu panel

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
