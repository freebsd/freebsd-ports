# New ports collection makefile for:	mkfontscale
# Date Created:				28 Aug 2005
# Whom:					Pawel Worach
#
# $FreeBSD$
#

PORTNAME=	mkfontscale
PORTVERSION=	1.0.8
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Creates an index of scalable font files for X

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

XORG_CAT=	app
USE_XORG=	xproto fontenc

PLIST_FILES=	bin/mkfontscale
MAN1=		mkfontscale.1

.include <bsd.port.mk>
