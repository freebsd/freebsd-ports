# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	dunst
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	sysutils

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Lightweight notification daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		gmake gnome perl5 pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	dunst-project

USE_GNOME=	cairo gdkpixbuf2 pango
USE_PERL5=	build
USE_XORG=	x11 xext xinerama xrandr xscrnsaver

MAKE_ARGS=	MANPREFIX="${PREFIX}/man"
ALL_TARGET=	dunst
TEST_TARGET=	test

PLIST_FILES=	bin/dunst \
		share/dunst/dunstrc \
		man/man1/dunst.1.gz \
		share/dbus-1/services/org.knopwob.dunst.service

OPTIONS_DEFINE=	DUNSTIFY
OPTIONS_DEFAULT=	DUNSTIFY

DUNSTIFY_DESC=	Install dunstify (alternative to the notify-send)

DUNSTIFY_ALL_TARGET=	dunstify
DUNSTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
DUNSTIFY_PLIST_FILES=	bin/dunstify

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dunst/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dunst

post-install-DUNSTIFY-on:
	${INSTALL_PROGRAM} ${WRKSRC}/dunstify ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
