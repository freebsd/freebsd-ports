# New ports collection makefile for:	wifimgr
# Date created:				2009 November 10
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	wifimgr
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	net-mgmt sysutils
MASTER_SITES=	http://opal.com/freebsd/ports/net-mgmt/wifimgr/ \
		LOCAL/pgollucci

MAINTAINER=	fbsd@opal.com
COMMENT=	WiFi Networks Manager

USE_BZIP2=	yes
USE_XORG=	x11
USE_GNOME=	gtk20 pkgconfig
INSTALLS_ICONS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CFLAGS+=	-DWITHOUT_NLS
PLIST_SUB+=	NLS="@comment "
.endif

MAN8=		wifimgr.8

.include <bsd.port.mk>
