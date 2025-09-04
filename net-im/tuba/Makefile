PORTNAME=	Tuba
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
CATEGORIES=	net-im

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Browse the Fediverse
WWW=		https://github.com/GeopJr/Tuba \
		https://tuba.geopjr.dev

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgraphene-1.0.so:graphics/graphene \
		libicuuc.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig \
		vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	GeopJr
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 gtksourceview5 libadwaita libxml2
GLIB_SCHEMAS=	dev.geopjr.Tuba.gschema.xml

OPTIONS_DEFAULT=	CLAPPER GNOMEKEYRING GSTREAMER SPELLING WEBP
OPTIONS_GROUP=		FEATURES
OPTIONS_GROUP_FEATURES=	BROWSER CLAPPER EXIV2 GSTREAMER SPELLING WEBP
OPTIONS_SINGLE=		KEYRING
OPTIONS_SINGLE_KEYRING=	GNOMEKEYRING

BROWSER_DESC=	Enable in-app WebKit Browser
CLAPPER_DESC=	Install the default video player
SPELLING_DESC=	Install spellcheck library
WEBP_DESC=	Enable WebP support

BROWSER_BUILD_DEPENDS=		webkit2-gtk_60>0:www/webkit2-gtk@60
BROWSER_RUN_DEPENDS=		webkit2-gtk_60>0:www/webkit2-gtk@60
BROWSER_MESON_ENABLED=		in-app-browser
CLAPPER_LIB_DEPENDS=		libclapper-0.0.so:multimedia/clapper \
				libclapper-gtk-0.0.so:multimedia/clapper
CLAPPER_MESON_ENABLED=		clapper
EXIV2_LIB_DEPENDS=		libgexiv2.so:graphics/gexiv2
EXIV2_MESON_ENABLED=		gexiv2
GNOMEKEYRING_RUN_DEPENDS=	gnome-keyring:security/gnome-keyring
GSTREAMER_USES=			gstreamer
GSTREAMER_USE=			GSTREAMER=fdkaac,good
GSTREAMER_MESON_ENABLED=	gstreamer
SPELLING_LIB_DEPENDS=		libspelling-1.so:x11-toolkits/libspelling
SPELLING_MESON_ENABLED=		spelling
WEBP_RUN_DEPENDS=		webp-pixbuf-loader>=0:graphics/webp-pixbuf-loader

post-patch:
	@${REINPLACE_CMD} '176,190d' ${WRKSRC}/meson.build

post-install:
	(cd ${BUILD_WRKSRC} && \
		${STRIP_CMD} dev.geopjr.${PORTNAME} && \
		${LN} dev.geopjr.${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl} && \
		${INSTALL_MAN} data/dev.geopjr.${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME:tl}.1)

.include <bsd.port.mk>
