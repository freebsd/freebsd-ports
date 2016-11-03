# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	dunst
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	rodperson@rodperson.com
COMMENT=	Lightweight notification daemon

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2 \
		libnotify.so:devel/libnotify \
		libpango-1.0.so:x11-toolkits/pango \
		libxdg-basedir.so:x11/libxdg-basedir

USE_GITHUB=	yes
GH_ACCOUNT=	knopwob
USES=		execinfo gmake pkgconfig:build perl5
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

post-extract:
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/VERSION

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dunst

.include <bsd.port.mk>
