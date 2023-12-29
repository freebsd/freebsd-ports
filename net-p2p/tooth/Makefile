PORTNAME=	tooth
DISTVERSION=	g20230115
PORTREVISION=	1
CATEGORIES=	net-p2p

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK Mastodon Client - Fork of Tootle
WWW=		https://github.com/GeopJr/Tooth

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Project has been renamed to Tuba. Consider porting to the new project. See https://github.com/GeopJr/Tuba
EXPIRATION_DATE=	2024-03-29

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		valac:lang/vala
LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libgee-0.8.so:devel/libgee \
		libgraphene-1.0.so:graphics/graphene \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup

USES=		desktop-file-utils gettext gnome meson pkgconfig python:build
USE_GITHUB=	yes
GH_ACCOUNT=	GeopJr
GH_PROJECT=	Tooth
GH_TAGNAME=	ea4f976
USE_GNOME=	gdkpixbuf2 glib20 gtk40 libxml2 pango

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	@${RLN} ${STAGEDIR}${PREFIX}/bin/dev.geopjr.tooth \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
