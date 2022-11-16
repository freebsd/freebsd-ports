PORTNAME=	libXt
DISTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits

# CHERI support (merged upstream)
PATCH_SITES=	https://gitlab.freedesktop.org/xorg/lib/libxt/-/merge_requests/
PATCHFILES=	46.patch:-p1 47.patch:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Toolkit library
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

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
