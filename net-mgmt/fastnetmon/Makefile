PORTNAME=	fastnetmon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	net-mgmt security

PATCH_SITES=	https://github.com/pavel-odintsov/${PORTNAME}/commit/
PATCHFILES=	fad8757b8986226024d549a6dfb40abbab01643e.patch:-p2

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Very fast DDoS analyzer with sflow/netflow/mirror support
WWW=		https://fastnetmon.com

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_armv6=	does not build: invokes x86 assembler
BROKEN_armv7=	does not build: invokes x86 assembler

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libmongoc-1.0.so:devel/mongo-c-driver \
		libbson-1.0.so:devel/libbson \
		libcapnp.so:devel/capnproto \
		libgrpc.so:devel/grpc \
		libprotobuf.so:devel/protobuf \
		libabsl_base.so:devel/abseil \
		libhiredis.so:databases/hiredis

USES=		cmake compiler:c++20-lang localbase:ldflags pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	pavel-odintsov

WRKSRC_SUBDIR=	src

USE_RC_SUBR=	${PORTNAME}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
PORTDOCS=	*

CFLAGS_i386=	-march=i586
CXXFLAGS+=	-D_GNU_SOURCE

CMAKE_OFF=	SET_ABSOLUTE_INSTALL_PATH
CMAKE_ON=	ENABLE_NETMAP_SUPPORT \
		LINK_WITH_ABSL

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|/var/run|&/fastnetmon|g; s|/var/log|&/fastnetmon|g; \
		s|"/etc/|"${PREFIX}/etc/|g; s|/root/fastnetmon|${DATADIR}|g' \
		${WRKSRC}/fastnetmon.conf ${WRKSRC}/fastnetmon.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/man/fastnetmon.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/fastnetmon.conf ${STAGEDIR}${PREFIX}/etc/fastnetmon.conf.sample
	${INSTALL_DATA} ${WRKSRC}/networks_list ${STAGEDIR}${PREFIX}/etc/networks_list.sample
	${INSTALL_DATA} ${WRKSRC}/networks_whitelist ${STAGEDIR}${PREFIX}/etc/networks_whitelist.sample
	${MKDIR} ${STAGEDIR}/var/run/fastnetmon ${STAGEDIR}/var/log/fastnetmon_attacks
	${INSTALL_SCRIPT} ${WRKSRC}/notify_about_attack.sh ${STAGEDIR}${PREFIX}/bin/notify_about_attack.sh.sample

post-install-DOCS-on:
	cd ${WRKSRC}/../ && ${COPYTREE_SHARE} "README.md docs" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
