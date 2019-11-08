# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-nettool
PORTVERSION=	3.8.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME utility that provides network information statistics

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop
RUN_DEPENDS=	${LOCALBASE}/bin/dig:dns/bind-tools

USE_GNOME=	gtk30 intlhack libxml2:build
USES=		gettext gmake gnome libtool localbase:ldflags pathfix pkgconfig \
		tar:xz
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnome-nettool.gschema.xml

.include <bsd.port.mk>
