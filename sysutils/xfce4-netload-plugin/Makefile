PORTNAME=	xfce4-netload-plugin
PORTVERSION=	1.5.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Network Load plugin for Xfce4
WWW=		https://docs.xfce.org/panel-plugins/xfce4-netload-plugin/start

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-tools gnome meson pkgconfig \
		tar:xz xfce
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's/ || defined \{0,1\}(__FreeBSD_kernel__)//' \
		${WRKSRC}/panel-plugin/net.c \
		${WRKSRC}/panel-plugin/net.h \
		${WRKSRC}/panel-plugin/os.h

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
