PORTNAME=	geary
PORTVERSION=	46.0
PORTREVISION=	3
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME
WWW=		https://wiki.gnome.org/Apps/Geary

LICENSE=	BSD2CLAUSE CC-BY-3.0 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	itstool:textproc/itstool \
		iso-codes>0:misc/iso-codes
LIB_DEPENDS=	libappstream-glib.so:devel/appstream-glib \
		libenchant-2.so:textproc/enchant2 \
		libfolks.so:net-im/folks \
		libgcr-base-3.so:security/gcr3 \
		libgee-0.8.so:devel/libgee \
		libgmime-3.0.so:mail/gmime30 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgspell-1.so:textproc/gspell \
		libhandy-1.so:x11-toolkits/libhandy \
		libicuuc.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libnotify.so:devel/libnotify \
		libpeas-gtk-1.0.so:devel/libpeas1 \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libstemmer.so:textproc/snowballstemmer \
		libytnef.so:converters/ytnef \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41

USES=		compiler:c11 cpe desktop-file-utils gettext gnome localbase:ldflags \
		meson pkgconfig python:build shebangfix sqlite tar:xz vala:build
CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf glib20 gsound gtk30 libxml2
GLIB_SCHEMAS=	org.gnome.Geary.gschema.xml
USE_LDCONFIG=	yes

SHEBANG_FILES=	desktop/geary-attach

MESON_ARGS=	-Dprofile=release -Dvaladoc=disabled \
		-Dlibunwind=disabled \
		-Diso_639_xml=${LOCALBASE}/share/xml/iso-codes/iso_639.xml \
		-Diso_3166_xml=${LOCALBASE}/share/xml/iso-codes/iso_3166.xml
BINARY_ALIAS=	python3=${PYTHON_VERSION}

CFLAGS+=	-Wno-error=int-conversion

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
