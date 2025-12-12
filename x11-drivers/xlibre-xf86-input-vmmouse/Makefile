PORTNAME=	xlibre-xf86-input-vmmouse
PORTVERSION=	13.2.0.2
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre vmmouse input driver
WWW=		https://github.com/X11Libre/xf86-input-vmmouse/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	xf86-input-vmmouse

USES=		gmake xlibre-cat:driver

GH_TAGNAME=	fa6a064

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	vmmouse protocol is only supported on x86-compatible architectures

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
