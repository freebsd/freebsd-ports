# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snort
DISTVERSION=	3.0.1-2
PORTEPOCH=	1
CATEGORIES=	security
PKGNAMESUFFIX=	3

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libdnet.so:net/libdnet \
		libpcap.so:net/libpcap \
		libluajit-5.1.so:lang/luajit \
		libhwloc.so:devel/hwloc \
		libuuid.so:misc/e2fsprogs-libuuid \
		libdaq.so:net/libdaq

USES=		cmake compiler:c++14-lang cpe localbase pathfix pkgconfig shebangfix ssl iconv
USE_GITHUB=	yes

GH_ACCOUNT=	snort3
GH_PROJECT=	snort3

SHEBANG_FILES=	tools/appid_detector_builder.sh

OPTIONS_DEFINE=		ADDRESSSANITIZER DEBUG DOCS FLATBUFFERS LARGEPCAP PIE THREADSANITIZER STATICDAQ
OPTIONS_DEFINE_amd64=	HYPERSCAN TSC
OPTIONS_DEFAULT=	STATICDAQ
OPTIONS_DEFAULT_amd64=	HYPERSCAN

ADDRESSSANITIZER_DESC=	Enable address sanitizer
FLATBUFFERS_DESC=	Enable flatbuffers support
HYPERSCAN_DESC=		Enable high-performance regular expression lib
LARGEPCAP_DESC=		Enable support for pcaps larger than 2 GB
PIE_DESC=		Enable PIE (Broken)
STATICDAQ_DESC=		Link static DAQ modules
THREADSANITIZER_DESC=	Enable thread sanitizer
TSC_DESC=		Use timestamp counter register clock (x86 only)

ADDRESSSANITIZER_CMAKE_BOOL=	ENABLE_ADDRESS_SANITIZER
DEBUG_CMAKE_BOOL=	ENABLE_COREFILES ENABLE_GDB
DOCS_CMAKE_BOOL=	MAKE_HTML_DOC MAKE_PDF_DOC MAKE_TEXT_DOC
LARGEPCAP_CMAKE_BOOL=	ENABLE_LARGE_PCAP
PIE_CMAKE_BOOL=		ENABLE_PIE
STATICDAQ_CMAKE_BOOL=	ENABLE_STATIC_DAQ
THREADSANITIZER_CMAKE_BOOL=	ENABLE_THREAD_SANITIZER
TSC_CMAKE_BOOL=		ENABLE_TSC_CLOCK

FLATBUFFERS_LIB_DEPENDS=libflatbuffers.so:devel/flatbuffers
HYPERSCAN_LIB_DEPENDS=	libhs.so:devel/hyperscan

CONFLICTS=	snort-2*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHYPERSCAN}
PLIST_SUB+=	HYPERSCAN=""
.else
PLIST_SUB+=	HYPERSCAN="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|_LIBDIR}/pkgconfig|_PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/cmake/create_pkg_config.cmake

.include <bsd.port.mk>
