# Created by: Pawel Worach
# $FreeBSD$

PORTNAME=	mkfontscale
PORTVERSION=	1.1.1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Creates an index of scalable font files for X

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

XORG_CAT=	app
USE_XORG=	xproto fontenc

CONFIGURE_ARGS+=--disable-maintainer-mode

PLIST_FILES=	bin/mkfontscale man/man1/mkfontscale.1.gz

.include <bsd.port.mk>
