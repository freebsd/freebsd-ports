PORTNAME=	libpcap
DISTVERSION=	1.10.7
CATEGORIES=	net
MASTER_SITES=	https://www.tcpdump.org/release/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library
WWW=		https://www.tcpdump.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		cmake cpe localbase:ldflags pathfix
CPE_VENDOR=	tcpdump
USE_LDCONFIG=	yes

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

CMAKE_ON=	DISABLE_AIRPCAP \
		DISABLE_DAG \
		DISABLE_DBUS \
		DISABLE_RDMA \
		DISABLE_SNF \
		DISABLE_TC
CMAKE_ARGS=	-DPCAP_TYPE=bpf

OPTIONS_DEFINE=	IPV6 REMOTE
OPTIONS_SUB=	yes

REMOTE_DESC=	Remote packet capture

IPV6_CMAKE_BOOL=	INET6

REMOTE_USES=		ssl
REMOTE_CMAKE_BOOL=	ENABLE_REMOTE

post-patch:
	@${REINPLACE_CMD} -e "/^        install_manpage_symlink/d" \
	    ${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	@${ECHO_MSG} "====> Fixing file extensions for manpages"
	@cd ${STAGEDIR}${PREFIX}/share/man/man3 && for f in *.3pcap; do \
	    ${MV} "$$f" `${ECHO_CMD} "$$f" | ${SED} -e 's|3pcap|3|g'`; \
	done

.include <bsd.port.mk>
