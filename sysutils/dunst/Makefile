# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	dunst
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.knopwob.org/public/dunst-release/

MAINTAINER=	rodperson@rodperson.com
COMMENT=	Lightweight notification daemon

LICENSE=	BSD

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango \
		libxdg-basedir.so:${PORTSDIR}/x11/libxdg-basedir

USES=		gmake pkgconfig:build perl5 tar:bzip2
USE_GNOME=	glib20
USE_XORG=	xext xft xinerama xscrnsaver
MAKE_ARGS+=	MANPREFIX="${PREFIX}/man"

ALL_TARGET=	dunst dunstify dunst.1
INSTALL_TARGET=	install

LDFLAGS+=	-Wall -rdynamic -lexecinfo

PLIST_FILES=	bin/dunst \
		share/dunst/dunstrc \
		man/man1/dunst.1.gz \
		share/dbus-1/services/org.knopwob.dunst.service

.include <bsd.port.mk>
