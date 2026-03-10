PORTNAME=	dpdk
DISTVERSION=	25.11
CATEGORIES=	net
MASTER_SITES=	http://fast.dpdk.org/rel/
PKGNAMESUFFIX=	25.11

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	DPDK: Software libraries for packet processing
WWW=		https://dpdk.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/README

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only tested on 64-bit x86 hardware

BUILD_DEPENDS=	objdump:devel/binutils \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

LIB_DEPENDS=	libelf.so.1:devel/elfutils \
		libjansson.so:devel/jansson \
		libpcap.so.1:net/libpcap \
		libisal.so:devel/isa-l
LIB_DEPENDS+=	${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_amd64=	libIPSec_MB.so:security/intel-ipsec-mb

USES=		kmod meson libarchive localbase:ldflags pkgconfig:both \
		python shebangfix ssl tar:xz
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,--undefined-version
SHEBANG_GLOB=	*.py *.sh
BINARY_ALIAS=	python3=${PYTHON_CMD}

CONFLICTS_INSTALL=	dpdk2[024].11

.if defined(CPUTYPE)
DPDK_CPUTYPE=${CPUTYPE}
.else
DPDK_CPUTYPE=default
.endif

MESON_ARGS=	-Ddefault_library=shared \
		-Denable_driver_sdk=true \
		-Dc_link_args=-Wl,--undefined-version \
		-Dmachine=${DPDK_CPUTYPE}

#WRKSRC=		${WRKDIR}/${PORTNAME}-stable-${DISTVERSION}

OPTIONS_DEFINE=		DOCS EXAMPLES TEST TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

TEST_DESC=		Build and install automated unit test binary
TOOLS_DESC=		Install tool scripts

DOCS_MESON_TRUE=	enable_docs
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			sphinx-build-${PYTHON_VER}:textproc/py-sphinx@${PY_FLAVOR}\
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_BINARY_ALIAS=	sphinx-build=sphinx-build-${PYTHON_VER}
DOCS_PORTDOCS=		*

EXAMPLES_MESON_ON=	-Dexamples=all
EXAMPLES_MESON_OFF=	-Dexamples=''

TEST_MESON_TRUE=	tests

TOOLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR}

PLIST_SUB+=	LIBMAJOR=26 LIBVER=26.0

.include <bsd.port.options.mk>

.if ${ARCH} == "aarch64"
PLIST_SUB+=	AARCH64="" \
		AMD64="@comment "
.elif ${ARCH} == "amd64"
PLIST_SUB+=	AARCH64="@comment " \
		AMD64=""
.endif

post-patch-TOOLS-off:
	# do not build tools
	@${REINPLACE_CMD} -e "/^subdir('usertools')/d" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
