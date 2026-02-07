PORTNAME=	xfce4-genmon-plugin
PORTVERSION=	4.3.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Generic Monitor Xfce4 panel plugin
WWW=		https://docs.xfce.org/panel-plugins/xfce4-genmon-plugin/start

LICENSE=	LGPL21

USES=		compiler:c11 gettext-tools gnome meson pkgconfig shebangfix \
		tar:xz xfce
USE_GNOME=	glib20 gtk30
USE_XFCE=	libmenu panel xfconf
SHEBANG_FILES=	scripts/datetime \
		scripts/disktemp \
		scripts/dkspuse \
		scripts/gmail \
		scripts/googcal.in \
		scripts/monBandwidth \
		scripts/monBat \
		scripts/monCPU \
		scripts/monTime \
		scripts/monUSB \
		scripts/monWIFI \
		scripts/sysstat

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
