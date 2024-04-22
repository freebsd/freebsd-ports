PORTNAME=	xf86-video-savage
PORTVERSION=	2.3.9
PORTREVISION=	8
CATEGORIES=	x11-drivers

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/driver/${PORTNAME}/-/commit/
PATCHFILES+=	0ece556daa8a88771b669d8104396abd9166d2d0.patch:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org savage display driver
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl xorg-cat:driver
USE_GL=		gl

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
