PORTNAME=	gnome-calculator
PORTVERSION=	47.3
PORTREVISION=	1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME calculator tool
WWW=		https://apps.gnome.org/Calculator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libsoup-3.0.so:devel/libsoup3

USES=		compiler:c11 gettext gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz vala:build
USE_GNOME=	glib20 gtk40 gtksourceview5 introspection:build libxml2 \
		libadwaita
BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Ddoc=false

GLIB_SCHEMAS=	org.gnome.calculator.gschema.xml

.include <bsd.port.mk>
