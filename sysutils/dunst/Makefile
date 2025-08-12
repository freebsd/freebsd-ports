PORTNAME=	dunst
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
CATEGORIES=	sysutils

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Lightweight notification daemon
WWW=		https://dunst-project.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libharfbuzz.so:print/harfbuzz
# textproc/jq required by completions
RUN_DEPENDS=	jq:textproc/jq
TEST_DEPENDS=	bash:shells/bash \
		valgrind:devel/valgrind

USES=		gmake gnome perl5 pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	dunst-project

USE_GNOME=	cairo gdkpixbuf pango
USE_PERL5=	build
USE_XORG=	x11 xext xinerama xrandr xscrnsaver

MAKE_ARGS=	MANPREFIX="${PREFIX}/share/man" \
		SYSCONFDIR="${PREFIX}/etc" \
		SYSTEMD=0
TEST_TARGET=	test

OPTIONS_DEFINE=		DUNSTIFY WAYLAND
OPTIONS_DEFAULT=	DUNSTIFY WAYLAND
OPTIONS_SUB=		yes

DUNSTIFY_DESC=	Install dunstify (alternative to the notify-send)

DUNSTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
DUNSTIFY_MAKE_ENV_OFF=	DUNSTIFY=0

WAYLAND_CATEGORIES=	wayland
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MAKE_ENV_OFF=	WAYLAND=0

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/usr/bin,${PREFIX}/bin,g' \
		-e 's,/usr/share,${PREFIX}/share,g' \
		-e 's,/etc,${PREFIX}&,g' \
		${WRKSRC}/docs/dunst.?.pod \
		${WRKSRC}/dunstrc \
		${WRKSRC}/src/settings_data.h \
		${WRKSRC}/src/icon-lookup.c

pre-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dunst
	${MV} ${STAGEDIR}/${ETCDIR}/dunstrc ${STAGEDIR}/${ETCDIR}/dunstrc.sample

post-install-DUNSTIFY-on:
	${INSTALL_PROGRAM} ${WRKSRC}/dunstify ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
