PORTNAME=	tdlib-purple
DISTVERSION=	0.9.6
CATEGORIES=	net-im devel
MASTER_SITES=	https://github.com/UnitedMarsupials/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Telegram plugin for libpurple, using tdlib
WWW=		https://github.com/UnitedMarsupials/tdlib-purple

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpurple.so:net-im/libpurple \
		librlottie.so:graphics/rlottie \
		libtdapi.so:net-im/tdlib
# Stickers are WebP, which Pidgin decodes with GdkPixbuf
RUN_DEPENDS=	${LOCALBASE}/lib/gdk-pixbuf-2.0/2.10.0/loaders/libpixbufloader-webp.so:graphics/webp-pixbuf-loader
TEST_DEPENDS=	${LOCALBASE}/lib/libgtest.so:devel/googletest

USES=		cmake gnome localbase pkgconfig tar:xz
USE_GNOME=	glib20

CMAKE_ON+=	NoVoip # tgvoip is yet to be ported

TEST_TARGET=	run-tests

OPTIONS_DEFINE=		NLS PIDGIN
OPTIONS_DEFAULT=	PIDGIN
OPTIONS_SUB=		yes
PIDGIN_DESC=		Features of Pidgin's conversation window (needs its headers)

NLS_USES=		gettext-runtime gettext-tools
NLS_CMAKE_OFF+=		-DNoTranslations=1
PIDGIN_BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:net-im/pidgin
PIDGIN_CMAKE_BOOL_OFF=	NoPidgin

.include <bsd.port.mk>
