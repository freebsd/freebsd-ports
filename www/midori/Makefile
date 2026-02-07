PORTNAME=	midori
PORTVERSION=	9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	14
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine
WWW=		https://astian.org/midori-browser/

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libp11-kit.so:security/p11-kit \
		libgcr-base-3.so:security/gcr3 \
		libpeas-1.0.so:devel/libpeas1 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext gnome \
		libarchive localbase:ldflags pkgconfig sqlite tar:bzip2 vala:build
USE_GNOME=	cairo glib20 gtk30 intltool introspection librsvg2:build

CPE_VENDOR=	midori-browser

CFLAGS+=	-Wno-int-conversion -Wno-return-type
CMAKE_ARGS=	-DUSE_APIDOCS:BOOL=OFF

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
