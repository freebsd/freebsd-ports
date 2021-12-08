# Created by: J.R. Oldroyd <fbsd@opal.com>

PORTNAME=	wifimgr
PORTVERSION=	1.19
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	https://opal.com/src/wifimgr/

MAINTAINER=	fbsd@opal.com
COMMENT=	WiFi Networks Manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gnome pkgconfig tar:xz xorg
USE_GNOME=	cairo
USE_XORG=	x11

OPTIONS_DEFINE=	GTK2 NLS
OPTIONS_SUB=	yes

GTK2_USE=	GNOME=gtk20
GTK2_MAKE_ENV=	GTK_VERSION=2
GTK2_USE_OFF=	GNOME=gtk30

NLS_USES=	gettext-runtime gettext-tools
NLS_MAKE_ENV_OFF=	WITHOUT_NLS=yes
NLS_CFLAGS_OFF=	-DWITHOUT_NLS

.include <bsd.port.mk>
