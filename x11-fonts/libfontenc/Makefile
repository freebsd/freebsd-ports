# Created by: Dejan Lesjak <lesi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfontenc
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The fontenc Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

XORG_CAT=	lib
USE_XORG=	xproto

CONFIGURE_ARGS=	--with-encodingsdir=${LOCALBASE}/share/fonts/encodings

.include <bsd.port.mk>
