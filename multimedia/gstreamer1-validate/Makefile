# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer1-validate
PORTVERSION=	1.16.1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-validate/
DISTNAME=	gst-validate-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer element validation suite

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libgstrtspserver-1.0.so:multimedia/gstreamer1-rtsp-server

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-runtime gmake gnome libtool pathfix \
		pkgconfig python shebangfix tar:xz
SHEBANG_FILES=	tools/gst-validate-launcher.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
USE_GSTREAMER1=	yes
INSTALL_TARGET=	install-strip
USE_PYTHON=	noflavors

PLIST_SUB=	VERSION=1.0 SOVERSION=0.1601.0

.include <bsd.port.mk>
