PORTNAME=	fastnetmon
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net-mgmt security

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Very fast DDoS analyzer with sflow/netflow/mirror support
WWW=		https://fastnetmon.com

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		does not build: invokes x86 assembler
BROKEN_armv7=		does not build: invokes x86 assembler

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libmongoc-1.0.so:devel/mongo-c-driver \
		libjson-c.so:devel/json-c \
		libbson-1.0.so:devel/libbson \
		libcapnp.so:devel/capnproto \
		libgrpc.so:devel/grpc142 \
		libprotobuf.so:devel/protobuf \
		libabsl_base.so:devel/abseil \
		libhiredis.so:databases/hiredis

USES=	cmake compiler:c++17-lang pkgconfig localbase:ldflags ssl
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	pavel-odintsov
USE_RC_SUBR=	${PORTNAME}

CMAKE_ARGS+=	-DENABLE_NETMAP_SUPPORT=ON \
		-DLINK_WITH_ABSL=ON \
		-DSET_ABSOLUTE_INSTALL_PATH=OFF \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/man
CMAKE_INSTALL_PREFIX=	${PREFIX}
CMAKE_SOURCE_PATH=	${WRKSRC}/src

CFLAGS_i386=	-march=i586
CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED \
		-D_GNU_SOURCE
LDFLAGS+=	-labsl_log_internal_message -labsl_log_internal_nullguard

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|/var/run|&/fastnetmon|g; s|/var/log|&/fastnetmon|g; \
		s|"/etc/|"${PREFIX}/etc/|g; s|/root/fastnetmon|${DATADIR}|g' \
		${WRKSRC}/src/fastnetmon.conf ${WRKSRC}/src/fastnetmon.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/man/fastnetmon.8

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${MKDIR} ${STAGEDIR}/var/run/fastnetmon ${STAGEDIR}/var/log/fastnetmon_attacks
	${INSTALL_SCRIPT} ${WRKSRC}/src/notify_about_attack.sh ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "README.md docs" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
