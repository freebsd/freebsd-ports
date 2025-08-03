PORTNAME=	gstreamer
PORTVERSION=	${_GST_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer/
PKGNAMESUFFIX=	1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Media applications framework
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libunwind.so:devel/libunwind

USES=		bison libtool gnome gstreamer:_internal meson ninja \
		pkgconfig python:build shebangfix tar:xz
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER=	#
USE_LDCONFIG=	yes

SHEBANG_FILES=	docs/gst-plugins-doc-cache-generator.py \
		gst/parse/get_flex_version.py \
		scripts/extract-release-date-from-doap-file.py \

MESON_ARGS=	-D dbghelp=disabled \
		-D doc=disabled \
		-D examples=disabled \
		-D libdw=disabled \
		-D tests=disabled

PORTSCOUT=	limitw:1,even

PLIST_SUB=	SOVERSION=${_GST_SOVERSION} \
		VERSION=${_GST_LIB_VER}

OPTIONS_DEFINE=		BASH NLS
OPTIONS_DEFAULT=	BASH
# The PTP helper requires Rust since GStreamer 1.24.0, so only enable it on
# platforms that have Rust support.
.for arch in aarch64 amd64 armv7 i386 powerpc64 powerpc64le powerpc riscv64
OPTIONS_DEFINE_${arch}=	PTP
OPTIONS_DEFAULT_${arch}=PTP
.endfor
OPTIONS_SUB=		yes

BASH_BUILD_DEPENDS=	bash-completion>0:shells/bash-completion
BASH_MESON_ENABLED=	bash-completion

NLS_USES=		gettext
NLS_MESON_ENABLED=	nls

PTP_DESC=		Precision Time Protocol support
PTP_BUILD_DEPENDS=	rustc:lang/rust
PTP_MESON_ENABLED=	ptp-helper

.include <bsd.port.options.mk>

.if ${ARCH:Naarch64:Namd64:Narmv7:Ni386:Npowerpc64:Npowerpc64le:Npowerpc:Nriscv64}
MESON_ARGS+=	-D ptp-helper=disabled
.endif

# Custom target to update distinfo for all gstreamer1 ports under control of
# _GST1_VERSION set in Mk/Uses/gstreamer.mk
makesum-all: makesum
.for p in editing-services libav rtsp-server vaapi
	@${MAKE} -C ${.CURDIR:H:H}/multimedia/gstreamer1-${p} makesum
.endfor
	@${MAKE} -C ${.CURDIR:H:H}/multimedia/gstreamer1-plugins makesum-all
	@${MAKE} -C ${.CURDIR:H:H}/multimedia/py-gstreamer1 makesum

.include <bsd.port.mk>
