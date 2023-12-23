PORTNAME=	font-manager
PORTVERSION=	0.8.8
PORTREVISION=	5
CATEGORIES=	x11-fonts gnome

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b65f10af7996945d1cc3e1fcc0b157df701173f4.patch:-p1

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Font management application for the GNOME desktop
WWW=		https://fontmanager.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cmake:devel/cmake-core \
		itstool:textproc/itstool \
		yelp-build:textproc/yelp-tools
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		meson pkgconfig python shebangfix sqlite vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	FontManager
USE_GNOME=	cairo glib20 gtk30 libxml2 pango
GLIB_SCHEMAS=	org.gnome.FontManager.gschema.xml \
		org.gnome.FontViewer.gschema.xml
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_MESON_TRUE=	enable-nls

post-patch:
	@${REINPLACE_CMD} \
		-e "s|\(find_installation.*\)python3|\1${PYTHON_CMD}|" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
