PORTNAME=	xlibre-xf86-input-vmmouse
PORTVERSION=	25.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre vmmouse input driver
WWW=		https://github.com/X11Libre/xf86-input-vmmouse/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xlibre-cat:driver

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	vmmouse protocol is only supported on x86-compatible architectures

.include <bsd.port.mk>
