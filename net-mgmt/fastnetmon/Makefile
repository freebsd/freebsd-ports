# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fastnetmon
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net-mgmt security

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Very fast DDoS analyzer with sflow/netflow/mirror support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		Does not build: invokes x86 assembler
BROKEN_armv7=		Does not build: invokes x86 assembler
BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libluajit-5.1.so:lang/luajit \
		libmongoc-1.0.so:devel/mongo-c-driver \
		libjson-c.so:devel/json-c \
		libbson-1.0.so:devel/libbson

USES=	cmake

USE_GITHUB=	yes
GH_ACCOUNT=	pavel-odintsov

USERS=	${PORTNAME}
GROUPS=	${PORTNAME}

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS REDIS

REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis

PORTDOCS=	*

CFLAGS_i386=	-march=i586
CMAKE_SOURCE_PATH=	${WRKSRC}/src
CMAKE_ARGS+=	-DDISABLE_PF_RING_SUPPORT=ON \
		-DENABLE_NETMAP_SUPPORT=OFF
CMAKE_INSTALL_PREFIX=	${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
		s|/var/run|&/fastnetmon|g; s|/var/log|&/fastnetmon|g; \
		s|"/etc/|"${PREFIX}/etc/|g; s|/root/fastnetmon|${DATADIR}|g' \
		${WRKSRC}/src/fastnetmon.conf ${WRKSRC}/src/fastnetmon.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/man/fastnetmon.1 ${WRKSRC}/src/fast_platform.h.template

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${MKDIR} ${STAGEDIR}/var/run/fastnetmon ${STAGEDIR}/var/log/fastnetmon
	${INSTALL_MAN} ${WRKSRC}/src/man/fastnetmon.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/man/fastnetmon_client.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "README.md docs" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
