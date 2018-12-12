# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	geary
PORTVERSION=	0.12.4
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME 3

LICENSE=	BSD2CLAUSE CC-BY-3.0 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libjavascriptcoregtk-4.0.so:www/webkit2-gtk3 \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libnotify.so:devel/libnotify \
		libgee-0.8.so:devel/libgee \
		libgcr-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libsoup-2.4.so:devel/libsoup \
		libenchant.so:textproc/enchant

USES=		cmake:outsource compiler:c11 desktop-file-utils gettext gnome libtool \
		localbase:ldflags pkgconfig shebangfix sqlite tar:xz
USE_GNOME=	cairo gnomedocutils gnomeprefix gtk30 intlhack introspection
SHEBANG_FILES=	desktop/geary-attach
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DNO_FATAL_WARNINGS:BOOL=ON \
		-DISO_CODE_639_XML:STRING=${LOCALBASE}/share/xml/iso-codes/iso_639.xml \
		-DISO_CODE_3166_XML:STRING=${LOCALBASE}/share/xml/iso-codes/iso_3166.xml

GLIB_SCHEMAS=	org.gnome.Geary.gschema.xml

.include <bsd.port.mk>
