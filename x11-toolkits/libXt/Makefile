PORTNAME=	libXt
DISTVERSION=	1.3.1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit Intrinsics library
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz xorg xorg-cat:lib
USE_XORG=	x11 sm ice xorgproto
CPE_VENDOR=	x
CPE_PRODUCT=	libxt

CONFIGURE_ARGS=	--disable-specs

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
