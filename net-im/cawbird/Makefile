PORTNAME=	cawbird
PORTVERSION=	1.5
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of Corebird GTK Twitter client
WWW=		https://github.com/IBBoard/cawbird

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		liboauth.so:net/liboauth \
		librest-0.7.so:devel/librest \
		libsoup-gnome-2.4.so:devel/libsoup

USES=		gettext gnome meson pkgconfig sqlite:3 vala:build

USE_GITHUB=	yes
GH_ACCOUNT=	IBBoard

USE_GNOME=	glib20 gtk30

GLIB_SCHEMAS=	uk.co.ibboard.cawbird.gschema.xml

MESON_ARGS=	-Dconsumer_key_base64=YUVNOE14dE5xMVdHRzl2emo5SzNNSlNUeg== \
	        -Dconsumer_secret_base64=c0J0cmc2clNJTFN6bHlSbFNXc2J1MmdvWWk3b0FzTGZHOGI4OG5QRzB3Tmx1Y0ZtOHQ=

OPTIONS_DEFINE=	SPELLCHECK VIDEO

SPELLCHECK_LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3
SPELLCHECK_MESON_OFF=	-Dspellcheck=false

VIDEO_USES=		gstreamer
VIDEO_MESON_OFF=	-Dvideo=false

.include <bsd.port.mk>
