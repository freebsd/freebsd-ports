PORTNAME=	wlclock
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11-clocks wayland
MASTER_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Digital analog clock for Wayland desktops
WWW=		https://git.sr.ht/~leon_plickat/wlclock

LICENSE=	GPLv3

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo
CFLAGS+=	-Wno-error=strict-prototypes # https://lists.sr.ht/~leon_plickat/public-inbox/%3Cttzs-maz0-wny%40FreeBSD.org%3E
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
