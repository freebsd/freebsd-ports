PORTNAME=	geary
PORTVERSION=	40.0
PORTREVISION=	4
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME

LICENSE=	BSD2CLAUSE CC-BY-3.0 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	itstool:textproc/itstool \
		vapigen:lang/vala
LIB_DEPENDS=	libappstream-glib.so:devel/appstream-glib \
		libcanberra.so:audio/libcanberra \
		libenchant-2.so:textproc/enchant2 \
		libfolks.so:net-im/folks \
		libgcr-base-3.so:security/gcr \
		libgee-0.8.so:devel/libgee \
		libgmime-3.0.so:mail/gmime30 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgspell-1.so:textproc/gspell \
		libhandy-1.so:x11-toolkits/libhandy \
		libicuuc.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libnotify.so:devel/libnotify \
		libpeas-gtk-1.0.so:devel/libpeas \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libstemmer.so:textproc/snowballstemmer \
		libunwind.so:devel/libunwind \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libytnef.so:converters/ytnef

USES=		compiler:c11 cpe desktop-file-utils gettext gnome meson pkgconfig \
		python:3.5+,build shebangfix sqlite tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo gsound gtk30 libxml2
GLIB_SCHEMAS=	org.gnome.Geary.gschema.xml
USE_LDCONFIG=	yes

SHEBANG_FILES=	desktop/geary-attach

MESON_ARGS=	-Dprofile=release
BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
