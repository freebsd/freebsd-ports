# New ports collection makefile for:	fonttosfnt
# Date Created:				17 Feb 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fonttosfnt
PORTVERSION=	1.0.4
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wrap a bitmap font in a sftn wrapper

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

XORG_CAT=	app
USE_XORG=	xproto fontenc

PLIST_FILES=	bin/fonttosfnt

MAN1=		fonttosfnt.1

.include <bsd.port.mk>
