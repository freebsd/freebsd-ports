PORTNAME=	wlclock
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	x11-clocks
MASTER_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

PATCH_SITES=	https://git.sr.ht/~leon_plickat/${PORTNAME}/commit/
PATCHFILES+=	0d8ab34550aa.patch:-p1 # unbreak EPOLL=off

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Digital analog clock for Wayland desktops

LICENSE=	GPLv3

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	EPOLL MANPAGES
OPTIONS_DEFAULT=EPOLL MANPAGES

EPOLL_DESC=		Handle signals via epoll-shim
EPOLL_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
EPOLL_MESON_ENABLED=	handle-signals

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
