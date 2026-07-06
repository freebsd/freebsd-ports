PORTNAME=	ucx
DISTVERSION=	1.20.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/openucx/ucx/releases/download/v${DISTVERSION}/

MAINTAINER=	rikka.goering@outlook.de
COMMENT=	Unified Communication X framework (UCX)
WWW=		https://openucx.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses arch-specific CPU backends; armv7 is not supported upstream and does not build on FreeBSD

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_c_float_words_bigendian.m4:devel/autoconf-archive

USES=		autoreconf dos2unix gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc \
		--enable-compiler-opt=0 \
		--enable-gtest \
		--enable-mt \
		--with-go=no
CONFIGURE_ENV=	GIT=/usr/bin/false
INSTALL_TARGET=	install-strip
TEST_ENV+=	LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib
CFLAGS+=	-Wno-error
CXXFLAGS+=	-Wno-error
LDFLAGS+=	-lexecinfo -lprocstat -lutil

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES FUSE IBVERBS IODEMO PERFTEST UMAD
OPTIONS_DEFAULT=	FUSE IODEMO PERFTEST
OPTIONS_SUB=		yes

IBVERBS_DESC=		Enable InfiniBand/RDMA (verbs) transport
IODEMO_DESC=		Install io_demo test application
PERFTEST_DESC=		Install ucx_perftest benchmarks
UMAD_DESC=		Build/install perftest MAD plugin (umad)

FUSE_LIB_DEPENDS=	libfuse3.so:filesystems/fusefs-libs3
FUSE_CONFIGURE_ON=	--with-fuse3=${LOCALBASE}
FUSE_CONFIGURE_OFF=	--with-fuse3=no

IBVERBS_CONFIGURE_ON=	--with-verbs=${LOCALBASE}
IBVERBS_CONFIGURE_OFF=	--with-verbs=no

UMAD_IMPLIES=		IBVERBS PERFTEST
UMAD_CONFIGURE_ON=	--with-mad=${LOCALBASE}
UMAD_CONFIGURE_OFF=	--with-mad=no

post-patch:
	${REINPLACE_CMD} 's|^examplesdir = $$(pkgdatadir)/examples$$|examplesdir = ${EXAMPLESDIR}|' \
		${WRKSRC}/examples/Makefile.am
	${REINPLACE_CMD} 's|/run/user|/var/run/user|' \
		${WRKSRC}/src/ucs/vfs/sock/vfs_sock.h

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/ucx.conf ${STAGEDIR}${ETCDIR}/ucx.conf.sample

do-test:
	cd ${WRKSRC}/test/gtest && \
		${SETENV} ${TEST_ENV} ${MAKE_CMD} && \
		${SETENV} ${TEST_ENV} ./gtest --gtest_filter=-malloc_hook*:sysv/*:test_rcache*:test_rcache_pfn*:test_vfs_sock*:test_datatype.hlist_for_each_extract_if:tcp/test_uct_pending.pending_fairness*:tcp/test_uct_peer_failure.purge_failed_peer*:tcp/test_uct_pending.pending_purge*:tcp/test_uct_iface.is_reachable*:tcp/test_uct_perf*:tcp/test_uct_loopback*:tcp/test_uct_tcp.listener_flood_connect_and_send_large*:tcp/test_uct_tcp.listener_flood_connect_and_send_small*:tcp/test_uct_tcp.check_addr_len*:shm*/*:mm_tcp/*:ib_shm/*:ud_tcp/*:all/*:*/test_ucp_loopback*:tcp/test_ucp_perf*:*/test_ucp_proto_mock_self.rkey_ptr*:test_config.test_config_file:test_config.test_config_file_parse_files:signal/*:*/test_async.many_timers*:*/test_ucp_peer_failure_keepalive*:self/test_ucp_wakeup.signal*:tcp/test_ucp_wakeup.signal*:tcp/test_proto_reset.am_eager_multi_bcopy*:tcp/test_uct_sockaddr.err_handle*:tcp/test_ucp_sockaddr_protocols_diff_net_devices*:tcp/test_ucp_sockaddr_iface_activate*:*/test_ucp_atomic*:*/test_ucp_mmap*:*/test_ucp_tag_match_rndv_align*:*/test_ucp_tag_probe*:tcp/test_ucp_sockaddr.*close_during_rndv*:tcp/test_ucp_sockaddr_protocols_err*::*test_ucp_wireup_1sided.stress_connect*

.include <bsd.port.mk>
