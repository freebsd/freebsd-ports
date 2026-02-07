PORTNAME=	dpdk
DISTVERSION=	22.11.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://fast.dpdk.org/rel/
PKGNAMESUFFIX=	22.11

MAINTAINER=	bruce.richardson@intel.com
COMMENT=	DPDK: Software libraries for packet processing
WWW=		https://dpdk.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/README

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only tested on 64-bit x86 hardware

BUILD_DEPENDS=	objdump:devel/binutils \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

LIB_DEPENDS=	libelf.so:devel/elfutils \
		libjansson.so:devel/jansson \
		libpcap.so.1:net/libpcap \
		libisal.so:devel/isa-l

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR}

USES=		kmod meson pkgconfig:both python shebangfix ssl tar:xz
USE_LDCONFIG=	yes
SHEBANG_FILES=	examples/ipsec-secgw/test/pkttest.py \
		examples/ipsec-secgw/test/pkttest.sh \
		examples/ipsec-secgw/test/run_test.sh \
		examples/ipsec-secgw/test/trs_ipv6opts.py \
		examples/ipsec-secgw/test/tun_null_header_reconstruct.py \
		examples/pipeline/examples/vxlan_table.py \
		usertools/dpdk-devbind.py usertools/dpdk-hugepages.py \
		usertools/dpdk-pmdinfo.py usertools/dpdk-telemetry-client.py \
		usertools/dpdk-telemetry.py

.if defined(CPUTYPE)
DPDK_CPUTYPE=${CPUTYPE}
.else
DPDK_CPUTYPE=default
.endif

MESON_ARGS=	-Ddefault_library=shared \
		-Denable_driver_sdk=true \
		-Denable_kmods=true \
		-Dc_link_args=-Wl,--undefined-version \
		-Dmachine=${DPDK_CPUTYPE}

WRKSRC=		${WRKDIR}/${PORTNAME}-stable-${DISTVERSION}

OPTIONS_DEFINE=		EXAMPLES TEST TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

TEST_DESC=		Build and install automated unit test binary
TOOLS_DESC=		Install tool scripts

EXAMPLES_MESON_ON=	-Dexamples=all
TEST_MESON_TRUE=	tests
TOOLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR}

.include <bsd.port.mk>
