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

USES=		bison gnome gstreamer:_internal meson ninja \
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
.for p in editing-services libav rtsp-server
	@${MAKE} -C ${.CURDIR:H:H}/multimedia/gstreamer1-${p} makesum
.endfor
	@${MAKE} -C ${.CURDIR:H:H}/devel/gstreamer1-devtools makesum
	@${MAKE} -C ${.CURDIR:H:H}/multimedia/gstreamer1-plugins makesum-all
	@${MAKE} -C ${.CURDIR:H:H}/multimedia/py-gstreamer1 makesum

# Automatically creates a VuXML entry for the GSreamer suite. This uses a
# python script to scrape https://gstreamer.freedesktop.org/security/
# and is pretty good in auto mode, but the output should still be verifed.
# The script can be run manually with finer parameters for quirky cases.
create-vuxml:
	@if ! ${PYTHON_CMD} -c "import bs4" 2>/dev/null; then \
		${ECHO_MSG} "====>  Error: create-vuxml target requires the bs4 Python module."; \
		${ECHO_MSG} "====>  Please install it: pkg install ${PYTHON_PKGNAMEPREFIX}beautifulsoup4"; \
		exit 1; \
	fi
	@if ! ${PYTHON_CMD} -c "import requests" 2>/dev/null; then \
		${ECHO_MSG} "====>  Error: create-vuxml target requires the requests Python module."; \
		${ECHO_MSG} "====>  Please install it: pkg install ${PYTHON_PKGNAMEPREFIX}requests"; \
		exit 1; \
	fi
	@${ECHO_MSG} "===>  Auto-generating VuXML entry for GStreamer ${PORTVERSION}..."
	@if [ -f "${FILESDIR}/generate-vuxml-entry.py" ]; then \
		current_year=$$(date +%Y); \
		vuxml_file="${.CURDIR:H:H}/security/vuxml/vuln/$${current_year}.xml"; \
		tmp_vuxml=$$(${MKTEMP} -t gst_vuxml); \
		trap '${RM} -f "$${tmp_vuxml}"' EXIT; \
		if ! ${SETENV} ${PYTHON_CMD} ${FILESDIR}/generate-vuxml-entry.py -a -v "${PORTVERSION}" > "$${tmp_vuxml}"; then \
			${ECHO_MSG} "====>  Error: Python VuXML generator failed."; \
			exit 1; \
		fi; \
		if [ -s "$${tmp_vuxml}" ]; then \
			if [ -f "$${vuxml_file}" ]; then \
				${ECHO_CMD} "====> Prepending entry to $${vuxml_file}..."; \
				${CAT} "$${tmp_vuxml}" "$${vuxml_file}" > "$${vuxml_file}.new"; \
				${MV} "$${vuxml_file}.new" "$${vuxml_file}"; \
			else \
				${ECHO_CMD} "====> Warning: $${vuxml_file} not found. Saving to ${.CURDIR}/vuxml_entry.xml instead. Maybe it's the new year and security/vuxml needs to be updated?"; \
				${CP} "$${tmp_vuxml}" ${.CURDIR}/vuxml_entry.xml; \
			fi; \
		fi; \
	else \
		${ECHO_CMD} "====> Warning: ${FILESDIR}/generate-vuxml-entry.py not found. Skipping VuXML generation."; \
	fi

.include <bsd.port.mk>
