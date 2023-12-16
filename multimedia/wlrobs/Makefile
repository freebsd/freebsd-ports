PORTNAME=	wlrobs
DISTVERSIONPREFIX=	v
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	multimedia wayland
MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONFULL:C/.*-//}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland screen capture plugin for obs-studio
WWW=		https://hg.sr.ht/~scoopta/wlrobs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	cmake:devel/cmake-core
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libobs.so:multimedia/obs-studio

USES=		compiler:c11 meson pkgconfig
DATADIR=	${PREFIX}/lib/obs-plugins
PORTDATA=	lib${PORTNAME}.so

.include <bsd.port.mk>
