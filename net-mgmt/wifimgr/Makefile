# Created by: J.R. Oldroyd <fbsd@opal.com>

PORTNAME=	wifimgr
PORTVERSION=	1.16
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://opal.com/freebsd/ports/net-mgmt/wifimgr/ \
		LOCAL/ehaupt

MAINTAINER=	fbsd@opal.com
COMMENT=	WiFi Networks Manager

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		desktop-file-utils gnome pkgconfig tar:bzip2 xorg
USE_GNOME=	cairo gtk30
INSTALLS_ICONS=	yes
USE_XORG=	x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime gettext-tools
NLS_MAKE_ENV_OFF=	WITHOUT_NLS=yes
NLS_CFLAGS_OFF=	-DWITHOUT_NLS

.include <bsd.port.mk>
