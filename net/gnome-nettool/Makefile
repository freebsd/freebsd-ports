PORTNAME=	gnome-nettool
PORTVERSION=	42.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME utility that provides network information statistics

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop
RUN_DEPENDS=	${LOCALBASE}/bin/dig:dns/bind-tools

USES=		gettext gmake gnome meson pathfix pkgconfig python tar:xz
USE_GNOME=	gtk30 intlhack libxml2:build
GLIB_SCHEMAS=	org.gnome.gnome-nettool.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
