# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	dunst
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.knopwob.org/public/dunst-release/

MAINTAINER=	rodperson@rodperson.com
COMMENT=	Lightweight notification deamon

LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		dbus:${PORTSDIR}/devel/dbus \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		freetype:${PORTSDIR}/print/freetype2 \
		notify:${PORTSDIR}/devel/libnotify \
		pango:${PORTSDIR}/x11-toolkits/pango \
		xdg-basedir:${PORTSDIR}/x11/libxdg-basedir

USES=		gmake pkgconfig:build
USE_BZIP2=	yes
USE_GNOME=	glib20
USE_PERL=	yes
USE_XORG=	xext xft xinerama xscrnsaver
MAKE_ARGS+=	MANPREFIX="${PREFIX}/man"

ALL_TARGET=	dunst dunstify dunst.1
INSTALL_TARGET=	install

LDFLAGS+=	-O3 -g -Wall -rdynamic -lexecinfo
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/dunst \
		share/dunst/dunstrc \
		man/man1/dunst.1.gz \
		share/dbus-1/services/org.knopwob.dunst.service
PLIST_DIRS=	share/dunst

.include <bsd.port.mk>
