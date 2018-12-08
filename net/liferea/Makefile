# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liferea
DISTVERSION=	1.12.6
DISTVERSIONSUFFIX=b
CATEGORIES=	net gnome
MASTER_SITES=	https://github.com/lwindolf/liferea/releases/download/v${PORTVERSION:S/.r/-rc/}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Simple RSS/RDF feed reader

LICENSE=	GPLv2

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libpeas-1.0.so:devel/libpeas \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

USES=		compiler:c++11-lang desktop-file-utils gettext \
		gmake gnome libtool localbase \
		pathfix pkgconfig python:3.4+ sqlite tar:bzip2
USE_GNOME=	cairo dconf:run gtk30 intltool introspection \
		libxslt libxml2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-introspection

GLIB_SCHEMAS=	net.sf.liferea.gschema.xml
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
