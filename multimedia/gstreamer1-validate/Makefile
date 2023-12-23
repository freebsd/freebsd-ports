PORTNAME=	gstreamer1-validate
PORTVERSION=	1.16.3
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-validate/
DISTNAME=	gst-validate-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer element validation suite
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgstrtspserver-1.0.so:multimedia/gstreamer1-rtsp-server \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-runtime gmake gnome gstreamer libtool pathfix \
		pkgconfig python shebangfix tar:xz
SHEBANG_FILES=	tools/gst-validate-launcher.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
INSTALL_TARGET=	install-strip
USE_PYTHON=	noflavors

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_SUB=	VERSION=1.0 SOVERSION=0.1603.0

.include <bsd.port.mk>
