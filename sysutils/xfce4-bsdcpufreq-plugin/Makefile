# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	xfce4-bsdcpufreq-plugin
PORTVERSION=	0.3
CATEGORIES=	sysutils xfce

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Displays the current CPU clock frequency in the panel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gnome pkgconfig xfce
USE_XFCE=	panel
USE_GNOME=	cairo gdkpixbuf2 gtk30

PLIST_FILES=	lib/xfce4/panel/plugins/libbsdcpufreq.so \
		share/xfce4/panel/plugins/bsdcpufreq.desktop

USE_GITHUB=	yes
GH_ACCOUNT=	riggs-
GH_TAGNAME=	a093f86

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xfce4/panel/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xfce4/panel/plugins
	${INSTALL_LIB} ${WRKSRC}/libbsdcpufreq.so ${STAGEDIR}${PREFIX}/lib/xfce4/panel/plugins
	${INSTALL_DATA} ${WRKSRC}/bsdcpufreq.desktop ${STAGEDIR}${PREFIX}/share/xfce4/panel/plugins

.include <bsd.port.mk>
