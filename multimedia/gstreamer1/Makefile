PORTNAME=	gstreamer
PORTVERSION=	1.20.5
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer/
PKGNAMESUFFIX=	1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Media applications framework
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison libtool gnome meson ninja pkgconfig python:3.8+,build shebangfix tar:xz
USE_GNOME=     glib20 introspection:build

CONFIGURE_ARGS=	-D tests=disabled \
	-D examples=disabled \
	-D dbghelp=disabled \
	-D doc=disabled
PLIST_SUB=	VERSION=${GST10_VERSION} \
		SOVERSION=0.2005.0

USE_LDCONFIG=	yes
GST10_VERSION=	1.0

PORTSCOUT=	limitw:1,even

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS

OPTIONS_DEFINE_aarch64=		LIBUNWIND
OPTIONS_DEFFAULT_aarch64=	LIBUNWIND
OPTIONS_DEFINE_amd64=		LIBUNWIND
OPTIONS_DEFAULT_amd64=		LIBUNWIND
OPTIONS_DEFINE_i386=		LIBUNWIND
OPTIONS_DEFFAULT_i386=		LIBUNWIND

NLS_USES=	gettext
NLS_MESON_ENABLED=      nls

LIBUNWIND_DESC=		Libunwind is optionally used by the leaks tracer
LIBUNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
LIBUNWIND_MESON_ENABLED=        libunwind

SHEBANG_FILES=  gst/parse/get_flex_version.py \
	scripts/extract-release-date-from-doap-file.py \
	docs/gst-plugins-doc-cache-generator.py
python_OLD_CMD= "/usr/bin/env python3"
python_CMD=     ${SETENV} ${PYTHON_VERSION}

.include <bsd.port.mk>
