# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	xfce4-bsdcpufreq-plugin
PORTVERSION=	0.2
CATEGORIES=	sysutils xfce

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Displays the current CPU clock frequency in the panel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	riggs-
GH_COMMIT=	be17b3a
GH_TAGNAME=	${GH_COMMIT}

USE_GNOME=	gtk20

USES=		pkgconfig

LIB_DEPENDS+=	libxfce4util.so:${PORTSDIR}/x11/libxfce4util \
		libxfce4panel-1.0.so:${PORTSDIR}/x11-wm/xfce4-panel \
		libxfce4ui-1.so:${PORTSDIR}/x11/libxfce4menu

PLIST_FILES=	lib/xfce4/panel/plugins/libbsdcpufreq.so \
		share/xfce4/panel/plugins/bsdcpufreq.desktop

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xfce4/panel/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xfce4/panel/plugins
	${INSTALL_LIB} ${WRKSRC}/libbsdcpufreq.so ${STAGEDIR}${PREFIX}/lib/xfce4/panel/plugins
	${INSTALL_DATA} ${WRKSRC}/bsdcpufreq.desktop ${STAGEDIR}${PREFIX}/share/xfce4/panel/plugins

.include <bsd.port.mk>
