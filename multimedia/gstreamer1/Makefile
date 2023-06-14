PORTNAME=	gstreamer
PORTVERSION=	1.22.4
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer/
PKGNAMESUFFIX=	1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Media applications framework
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison libtool gnome meson ninja pkgconfig python:build shebangfix tar:xz
USE_GNOME=     glib20 introspection:build

LIB_DEPENDS=	libdw.so:devel/elfutils \
		libunwind.so:devel/libunwind

CONFIGURE_ARGS=	-D tests=disabled \
	-D examples=disabled \
	-D dbghelp=disabled \
	-D doc=disabled
PLIST_SUB=	VERSION=${GST10_VERSION} \
		SOVERSION=0.2204.0

USE_LDCONFIG=	yes
GST10_VERSION=	1.0

PORTSCOUT=	limitw:1,even

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BASH NLS
OPTIONS_DEFAULT=BASH

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_MESON_ENABLED=	bash-completion

NLS_USES=	gettext
NLS_MESON_ENABLED=      nls

SHEBANG_FILES=  gst/parse/get_flex_version.py \
	scripts/extract-release-date-from-doap-file.py \
	docs/gst-plugins-doc-cache-generator.py
python_OLD_CMD= "/usr/bin/env python3"
python_CMD=     ${SETENV} ${PYTHON_VERSION}

.include <bsd.port.mk>
