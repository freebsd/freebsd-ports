PORTNAME=	ipfixcol2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	net-mgmt

MAINTAINER=	zarychtam@plan-b.pwste.edu.pl
COMMENT=	NetFlow v5/v9 and IPFIX flow (RFC 7011) data collector
WWW=		https://github.com/CESNET/ipfixcol2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Requires 64bit time_t: static_assert(sizeof(uint64_t) == sizeof(time_t), "Assumed that time_t is uint64_t, but it's not")

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libfds.so:net-mgmt/libfds \
		liblz4.so:archivers/liblz4 \
		librdkafka.so:net/librdkafka

USES=		cmake:testing localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	CESNET
USE_RC_SUBR=	${PORTNAME}

CXXFLAGS+=	-D_GNU_SOURCE
LDFLAGS+=	-rdynamic

SUB_LIST=	USER=${USERS:[0]}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

# XXX Drop after FreeBSD 13 EOL around 2026-04-30
.if !exists(/usr/include/sys/timerfd.h)
CFLAGS+=	`pkg-config --cflags epoll-shim`
LDFLAGS+=	`pkg-config --libs epoll-shim`
.endif

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/run/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/doc/data/configs/udp2json.xml \
		${STAGEDIR}${ETCDIR}/startup.xml.sample

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/doc/data && ${COPYTREE_SHARE} "configs" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
