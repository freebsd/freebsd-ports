# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXt
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe xorg xorg-cat:lib
USE_XORG=	x11 sm ice xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxt

CONFIGURE_ARGS=	--disable-specs

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
