PORTNAME=	Tuba
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	2
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
RUN_DEPENDS=	gnome-keyring>=0:security/gnome-keyring

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	GeopJr
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 gtksourceview5 libadwaita libxml2
GLIB_SCHEMAS=	dev.geopjr.Tuba.gschema.xml

OPTIONS_DEFINE=		SPELLCHECK
OPTIONS_DEFAULT=	SPELLCHECK

SPELLCHECK_DESC=	Enable spell-checking support
SPELLCHECK_LIB_DEPENDS=	libspelling-1.so:x11-toolkits/libspelling

USE_GSTREAMER1+=	yes

post-install:
	@(cd ${WRKSRC}/_build && \
		${STRIP_CMD} dev.geopjr.Tuba && \
		${LN} dev.geopjr.Tuba ${STAGEDIR}${PREFIX}/bin/tuba)

.include <bsd.port.mk>
