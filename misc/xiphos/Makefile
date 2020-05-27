# $FreeBSD$

PORTNAME=	xiphos
DISTVERSION=	4.1.0-72
DISTVERSIONSUFFIX=	-g9e573336
PORTREVISION=	2
CATEGORIES=	misc gnome

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Bible interface utilizing the sword framework

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		desktop-file-validate:devel/desktop-file-utils \
		itstool:textproc/itstool \
		yelp-build:textproc/yelp-tools
LIB_DEPENDS=	libbiblesync.so:misc/biblesync \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libenchant.so:textproc/enchant \
		libicui18n.so:devel/icu \
		libsoup-2.4.so:devel/libsoup \
		libsword.so:misc/sword \
		libuuid.so:misc/e2fsprogs-libuuid \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		cmake gettext gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	crosswire
USE_GNOME=	cairo gconf2 gtk30 gtkhtml4 intltool libgsf
INSTALLS_ICONS=	yes

CMAKE_OFF=	EPUB
CMAKE_ON=	GTKHTML

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS

.include <bsd.port.mk>
