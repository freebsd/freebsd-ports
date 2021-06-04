# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	midori
PORTVERSION=	9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	www xfce

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libp11-kit.so:security/p11-kit \
		libgcr-base-3.so:security/gcr \
		libpeas-1.0.so:devel/libpeas \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gnome \
		libarchive localbase:ldflags pkgconfig sqlite tar:bzip2
USE_GNOME=	cairo glib20 gtk30 intltool introspection librsvg2:build \
		libxml2

CFLAGS+=	-Wno-return-type
CMAKE_ARGS=	-DUSE_APIDOCS:BOOL=OFF

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

USE_GITHUB=	yes
GH_ACCOUNT=	midori-browser
GH_PROJECT=	core

OPTIONS_DEFINE=		ZEITGEIST
OPTIONS_SUB=		yes

ZEITGEIST_DESC=		User logs activities

ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist
ZEITGEIST_CMAKE_OFF=	-DUSE_ZEITGEIST:BOOL=OFF

post-patch:
# Avoid errors with CMake
.for dir in config extensions
	@${RM} ${WRKSRC}/${dir}/*.orig
.endfor

.include <bsd.port.mk>
