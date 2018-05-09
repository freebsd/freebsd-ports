# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	dunst
PORTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	dg@syrec.org
COMMENT=	Lightweight notification daemon

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libxdg-basedir.so:x11/libxdg-basedir

USES=		gmake perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dunst-project
USE_GNOME=	cairo gdkpixbuf2 pango
USE_PERL5=	build
USE_XORG=	x11 xrandr xinerama xscrnsaver

MAKE_ARGS=	MANPREFIX="${PREFIX}/man"
TEST_TARGET=	test

PLIST_FILES=	bin/dunst \
		share/dunst/dunstrc \
		man/man1/dunst.1.gz \
		share/dbus-1/services/org.knopwob.dunst.service

post-patch:
	@${REINPLACE_CMD} -e '/dunst\.systemd\.service/d' ${WRKSRC}/Makefile
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/VERSION

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dunst/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dunst

.include <bsd.port.mk>
