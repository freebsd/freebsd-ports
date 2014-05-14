# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	wifimgr
PORTVERSION=	1.11
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://opal.com/freebsd/ports/net-mgmt/wifimgr/ \
		CRITICAL

MAINTAINER=	fbsd@opal.com
COMMENT=	WiFi Networks Manager

USES=		desktop-file-utils pkgconfig tar:bzip2
USE_XORG=	x11
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext pkgconfig
PLIST_SUB+=	NLS=""
.else
CFLAGS+=	-DWITHOUT_NLS
PLIST_SUB+=	NLS="@comment "
MAKE_ENV+=	WITHOUT_NLS=${WITHOUT_NLS}
.endif

.include <bsd.port.mk>
