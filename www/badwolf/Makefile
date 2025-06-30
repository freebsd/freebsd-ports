PORTNAME=	badwolf
DISTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://hacktivis.me/releases/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Minimalist and privacy-oriented WebKitGTK browser
WWW=		https://hacktivis.me/projects/badwolf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		desktop-file-utils gnome ninja pkgconfig
USE_GNOME=	atk cairo gdkpixbuf gtk30 libxml2 pango
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	WITH_WEBKITGTK=4.0

OPTIONS_DEFINE=			GSTREAMER NLS
OPTIONS_DEFAULT=		GSTREAMER LIBSOUP
OPTIONS_SINGLE=			URI_PARSER
OPTIONS_SINGLE_URI_PARSER=	GURI LIBSOUP
OPTIONS_SUB=			yes

GURI_DESC=		Use GUri from glib-2.0
LIBSOUP_DESC=		Use libsoup
URI_PARSER_DESC=	URI PARSER

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=bad,good,libav
GURI_CONFIGURE_ENV=	WITH_URI_PARSER=guri
LIBSOUP_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup
LIBSOUP_CONFIGURE_ENV=	WITH_URI_PARSER=libsoup2

NLS_USES=		gettext
NLS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-configure

GURI_USE_GNOME=		glib20
LIBAV_USE_GSTREAMER=	libav

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
