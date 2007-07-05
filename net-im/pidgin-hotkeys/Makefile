# New ports collection makefile for:	pidgin-hotkeys
# Date created:		2006-11-23
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	pidgin-hotkeys
PORTVERSION=	0.2.4
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A pidgin plugin that allows user to assign global hotkeys

LIB_DEPENDS=	purple.0:${PORTSDIR}/net-im/libpurple
BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

USE_GNOME=	pkgconfig gtk20
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/pidgin/hotkeys.so \
		lib/pidgin/hotkeys.la

.include <bsd.port.mk>
