PORTNAME=	dpdk
DISTVERSION=	19.11.12
CATEGORIES=	net
MASTER_SITES=	http://fast.dpdk.org/rel/

MAINTAINER=	bruce.richardson@intel.com
COMMENT=	DPDK: Software libraries for packet processing
WWW=		https://dpdk.org/

LICENSE=	BSD3CLAUSE

DEPRECATED=	End of life since December 2022 upstream, consider migrating to net/dpdk-22.11
EXPIRATION_DATE=2023-12-31

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only works on 64-bit x86 hardware

LIB_DEPENDS=	libjansson.so:devel/jansson
BUILD_DEPENDS=	objdump:devel/binutils

USES=		meson kmod pkgconfig:both shebangfix tar:xz python
WRKSRC=	${WRKDIR}/${PORTNAME}-stable-${PORTVERSION}
MESON_ARGS=	-Dmachine=default -Ddefault_library=shared -Denable_kmods=true
USE_LDCONFIG=	yes
SHEBANG_FILES=	usertools/dpdk-pmdinfo.py \
	usertools/dpdk-telemetry-client.py \
	usertools/dpdk-devbind.py \
	usertools/dpdk-pmdinfo.py \
	examples/ipsec-secgw/test/pkttest.py \
	examples/ipsec-secgw/test/pkttest.sh \
	examples/ipsec-secgw/test/run_test.sh \
	examples/ipsec-secgw/test/trs_ipv6opts.py \
	examples/ipsec-secgw/test/tun_null_header_reconstruct.py \
	examples/performance-thread/l3fwd-thread/test.sh \

OPTIONS_DEFINE=		EXAMPLES DEBUG TOOLS TESTS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes
DEBUG_DESC=		Debugging support (unoptimized build, impacts performance)
TOOLS_DESC=		Install tool scripts
TESTS_DESC=		Build the automated unit test binary

EXAMPLES_MESON_ON=	-Dexamples=all
DEBUG_MESON_ON=		--buildtype=debug
DEBUG_MESON_OFF=	--buildtype=release
TESTS_MESON_TRUE=	tests
TOOLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR}

.include <bsd.port.mk>
