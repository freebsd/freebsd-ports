PORTNAME=	dpdk
DISTVERSION=	20.11.8
CATEGORIES=	net
MASTER_SITES=	http://fast.dpdk.org/rel/
PKGNAMESUFFIX=	20.11

MAINTAINER=	bruce.richardson@intel.com
COMMENT=	DPDK: Software libraries for packet processing
WWW=		https://dpdk.org/

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only tested on 64-bit x86 hardware

BUILD_DEPENDS=	objdump:devel/binutils
LIB_DEPENDS=	libelf.so:devel/elfutils \
		libjansson.so:devel/jansson

USES=		kmod meson pkgconfig:both python shebangfix tar:xz
USE_LDCONFIG=	yes
SHEBANG_FILES=	examples/ipsec-secgw/test/pkttest.py \
		examples/ipsec-secgw/test/pkttest.sh \
		examples/ipsec-secgw/test/run_test.sh \
		examples/ipsec-secgw/test/trs_ipv6opts.py \
		examples/ipsec-secgw/test/tun_null_header_reconstruct.py \
		examples/performance-thread/l3fwd-thread/test.sh \
		examples/pipeline/examples/vxlan_table.py \
		usertools/dpdk-devbind.py usertools/dpdk-hugepages.py \
		usertools/dpdk-pmdinfo.py usertools/dpdk-telemetry-client.py \
		usertools/dpdk-telemetry.py
MESON_ARGS=	-Ddefault_library=shared \
		-Denable_kmods=true \
		-Dmachine=default

WRKSRC=		${WRKDIR}/${PORTNAME}-stable-${PORTVERSION}

OPTIONS_DEFINE=		DEBUG EXAMPLES TESTS TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes
DEBUG_DESC=		Debugging support (unoptimized build, impacts performance)
TESTS_DESC=		Build the automated unit test binary
TOOLS_DESC=		Install tool scripts

DEBUG_MESON_ON=		--buildtype=debug
DEBUG_MESON_OFF=	--buildtype=release
EXAMPLES_MESON_ON=	-Dexamples=all
TESTS_MESON_TRUE=	tests
TOOLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR}

.include <bsd.port.mk>
