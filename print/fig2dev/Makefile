# $FreeBSD$

PORTNAME=	fig2dev
PORTVERSION=	3.2.7
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/mcj/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools to convert Xfig .fig files

RUN_DEPENDS=	ppmtogif:graphics/netpbm \
		gs:print/ghostscript9-agpl-base
LIB_DEPENDS=	libpng.so:graphics/png

CONFLICTS=	transfig-*

USES=		alias ghostscript:run iconv tar:xz xorg
CFLAGS+=	-Wno-return-type
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-transfig
CONFIGURE_ARGS+=	GSEXE=gs
USE_XORG=	xpm

.include <bsd.port.mk>
