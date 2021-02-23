# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	dunst
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	sysutils

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Lightweight notification daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		gmake gnome perl5 pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	dunst-project

USE_GNOME=	cairo gdkpixbuf2 pango
USE_PERL5=	build
USE_XORG=	x11 xext xinerama xrandr xscrnsaver

MAKE_ARGS=	MANPREFIX="${PREFIX}/man" SYSCONFDIR="${PREFIX}/etc"
ALL_TARGET=	dunst
TEST_TARGET=	test

OPTIONS_DEFINE=	DUNSTIFY WAYLAND
OPTIONS_DEFAULT=	DUNSTIFY WAYLAND

DUNSTIFY_DESC=	Install dunstify (alternative to the notify-send)

DUNSTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
DUNSTIFY_PLIST_FILES=	bin/dunstify

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MAKE_ENV_OFF=	WAYLAND=0

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},g' \
		-e 's,/etc,${PREFIX}&,g' \
		${WRKSRC}/config.h \
		${WRKSRC}/docs/dunst.?.pod \
		${WRKSRC}/dunstrc \
		${WRKSRC}/src/settings.c
	@${REINPLACE_CMD} -e 's,/dunstrc,&.sample,' \
		${WRKSRC}/Makefile

post-patch-DUNSTIFY-off:
	@${REINPLACE_CMD} -e '/^all:/s/dunstify//' \
		 -e '/^install:/s/install-dunstify//' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} '/libnotify/d' ${WRKSRC}/config.mk

pre-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dunst

post-install-DUNSTIFY-on:
	${INSTALL_PROGRAM} ${WRKSRC}/dunstify ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
