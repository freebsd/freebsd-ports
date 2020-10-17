# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	wifimgr
PORTVERSION=	1.13
PORTREVISION=	1
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
USE_XORG=	x11
USE_GNOME=	cairo gtk20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime gettext-tools
NLS_CFLAGS_OFF=	-DWITHOUT_NLS
NLS_MAKE_ENV_OFF=	WITHOUT_NLS=yes

post-patch:
	@${REINPLACE_CMD} -e 's/-o root -g wheel//' ${WRKSRC}/src/Makefile

.include <bsd.port.mk>
