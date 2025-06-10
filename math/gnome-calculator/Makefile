PORTNAME=	gnome-calculator
PORTVERSION=	47.1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME calculator tool
WWW=		https://live.gnome.org/Gcalctool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libsoup-3.0.so:devel/libsoup3

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz vala:build
USE_GNOME=	gtk40 gtksourceview5 introspection libxml2 libadwaita
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.calculator.gschema.xml

.include <bsd.port.mk>
