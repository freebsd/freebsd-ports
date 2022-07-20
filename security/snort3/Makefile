PORTNAME=	snort
DISTVERSION=	3.1.36.0
PORTEPOCH=	1
CATEGORIES=	security
PKGNAMESUFFIX=	3

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdaq.so:net/libdaq \
		libdnet.so:net/libdnet \
		libhwloc.so:devel/hwloc2 \
		libpcap.so:net/libpcap \
		libpcre.so:devel/pcre \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake compiler:c++14-lang cpe iconv localbase pathfix pkgconfig \
		shebangfix ssl
USE_GITHUB=	yes

GH_ACCOUNT=	snort3
GH_PROJECT=	snort3

SHEBANG_FILES=	tools/appid_detector_builder.sh

CMAKE_ARGS+=	-DFLEX_INCLUDE_DIR_HINT:PATH=${PREFIX}/include/flex

CONFLICTS=	snort-2*

OPTIONS_DEFINE=		ADDRESSSANITIZER DEBUG DOCS FLATBUFFERS HYPERSCAN \
			LARGEPCAP PIE STATICDAQ THREADSANITIZER
OPTIONS_DEFINE_amd64=	TSC
OPTIONS_DEFAULT=	STATICDAQ
OPTIONS_DEFAULT_amd64=	HYPERSCAN
OPTIONS_SUB=		yes

ADDRESSSANITIZER_DESC=	Enable address sanitizer
FLATBUFFERS_DESC=	Enable flatbuffers support
HYPERSCAN_DESC=		Enable high-performance regular expression lib
LARGEPCAP_DESC=		Enable support for pcaps larger than 2 GB
PIE_DESC=		Enable PIE (Broken)
STATICDAQ_DESC=		Link static DAQ modules
THREADSANITIZER_DESC=	Enable thread sanitizer
TSC_DESC=		Use timestamp counter register clock (x86 only)

ADDRESSSANITIZER_CMAKE_BOOL=	ENABLE_ADDRESS_SANITIZER
DEBUG_CMAKE_BOOL=		ENABLE_COREFILES ENABLE_GDB
DOCS_CMAKE_BOOL=		MAKE_HTML_DOC MAKE_PDF_DOC MAKE_TEXT_DOC
FLATBUFFERS_LIB_DEPENDS=	flatc:devel/flatbuffers205 # until https://github.com/snort3/snort3/issues/250 is fixed
HYPERSCAN_LIB_DEPENDS=		libhs.so:devel/hyperscan
HYPERSCAN_PLIST_SUB=		HYPERSCAN=""
HYPERSCAN_PLIST_SUB_OFF=	HYPERSCAN="@comment "
LARGEPCAP_CMAKE_BOOL=		ENABLE_LARGE_PCAP
PIE_CMAKE_BOOL=			ENABLE_PIE
STATICDAQ_CMAKE_BOOL=		ENABLE_STATIC_DAQ
THREADSANITIZER_CMAKE_BOOL=	ENABLE_THREAD_SANITIZER
TSC_CMAKE_BOOL=			ENABLE_TSC_CLOCK

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
LIB_DEPENDS+=	libluajit-5.1.so:lang/luajit-openresty
.else
LIB_DEPENDS+=	libluajit-5.1.so:lang/luajit
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300000
BUILD_DEPENDS=	flex>0:textproc/flex
.endif

post-patch:
	${REINPLACE_CMD} -e 's|_LIBDIR}/pkgconfig|_PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/cmake/create_pkg_config.cmake

.include <bsd.port.mk>
