# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-calculator
PORTVERSION=	3.24.0
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 calculator tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		vala:lang/vala
LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libsoup-2.4.so:devel/libsoup

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 gtksourceview3 intltool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.calculator.gschema.xml

.include <bsd.port.mk>
