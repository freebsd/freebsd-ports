# $FreeBSD$

PORTNAME=	wlrobs
DISTVERSIONPREFIX=	v
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONFULL:C/.*-//}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland screen capture plugin for obs-studio

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libobs.so:multimedia/obs-studio

USES=		gl meson pkgconfig
USE_GL=		egl
DATADIR=	${PREFIX}/lib/obs-plugins
PORTDATA=	lib${PORTNAME}.so

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c11
.endif

.include <bsd.port.mk>
