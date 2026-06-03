PORTNAME=		ucx
DISTVERSION=		1.20.0
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		https://github.com/openucx/ucx/releases/download/v${DISTVERSION}/

MAINTAINER=		rikka.goering@outlook.de
COMMENT=		Unified Communication X framework (UCX)
WWW=			https://openucx.org/

LICENSE=		BSD3CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses arch-specific CPU backends; armv7 is not supported upstream and does not build on FreeBSD

BUILD_DEPENDS=		${LOCALBASE}/share/aclocal/ax_c_float_words_bigendian.m4:devel/autoconf-archive

USES=			autoreconf gmake libtool pkgconfig
USE_LDCONFIG=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-mt \
			--with-go=no \
			--enable-compiler-opt=0 \
			--disable-doxygen-doc
CONFIGURE_ENV+=		GIT=/usr/bin/false

INSTALL_TARGET=		install-strip

TEST_ENV+=		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib

CFLAGS+=		-Wno-error
CXXFLAGS+=		-Wno-error
LDFLAGS+=		-lexecinfo

PORTDOCS=		*
PORTEXAMPLES=		*

OPTIONS_DEFINE=		DOCS EXAMPLES FUSE IBVERBS IODEMO UMAD PERFTEST
OPTIONS_DEFAULT=	IODEMO PERFTEST FUSE
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

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/ucx.conf ${STAGEDIR}${ETCDIR}/ucx.conf.sample

do-test:
	@${ECHO_MSG} "===> Running UCX smoke tests (ucx_info)"
	${SETENVI} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/ucx_info -v >/dev/null
	${SETENVI} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/ucx_info -d >/dev/null

.include <bsd.port.mk>
