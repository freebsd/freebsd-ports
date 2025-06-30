PORTNAME=	font-manager
DISTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	x11-fonts gnome

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
		libgraphene-1.0.so:graphics/graphene \
		libharfbuzz.so:print/harfbuzz \
		libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		libarchive meson pkgconfig python shebangfix sqlite vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	FontManager
USE_GNOME=	cairo glib20 gtk40 libxml2 pango
GLIB_SCHEMAS=	com.github.FontManager.FontManager.gschema.xml \
		com.github.FontManager.FontViewer.gschema.xml
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

# Requires webkit2gtk-4.1, which is currently unavailable in ports
MESON_ARGS=	-Dwebkit=false

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
