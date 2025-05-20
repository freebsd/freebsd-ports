PORTNAME=	xfce4-cpugraph-plugin
PORTVERSION=	1.3.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical representation of the CPU load
WWW=		https://docs.xfce.org/panel-plugins/xfce4-cpugraph-plugin/start

LICENSE=	GPLv2

USES=		compiler:c++17-lang gettext-tools gnome meson pkgconfig tar:xz \
		xfce
USE_CXXSTD=	c++17
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel xfconf

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
