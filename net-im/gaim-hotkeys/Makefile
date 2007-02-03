# New ports collection makefile for:	gaim-hotkeys
# Date created:		2006-11-23
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	gaim-hotkeys
PORTVERSION=	0.2.2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A gaim plugin that allows user to assign global hotkeys

LIB_DEPENDS=	gaim.0:${PORTSDIR}/net-im/libgaim
BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim-devel
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim-devel

USE_GNOME=	pkgconfig gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/gaim/hotkeys.so \
		lib/gaim/hotkeys.la

.include <bsd.port.mk>
