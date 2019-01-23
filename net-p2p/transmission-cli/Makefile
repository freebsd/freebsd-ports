# $FreeBSD$

PORTNAME=	transmission
DISTVERSION=	2.94
PORTREVISION?=	3
CATEGORIES+=	net-p2p
SLAVEPORT?=	cli
PKGNAMESUFFIX?=	-cli

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Meta-port for Transmission BitTorrent client

LICENSE+=	MIT

.if ${SLAVEPORT:Ncli}
LICENSE+=	GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING
.endif

.if ${SLAVEPORT:Nweb}
LIB_DEPENDS+=	libcurl.so:ftp/curl \
		libdht.so:devel/jech-dht \
		libb64.so:converters/libb64 \
		libevent.so:devel/libevent \
		libnatpmp.so:net/libnatpmp \
		libutp.so:net/libutp \
		libminiupnpc.so:net/miniupnpc

USES+=		cmake cpe iconv libtool localbase pkgconfig

.  if ${SLAVEPORT:Mcli}
USES+=		ssl
NLS_USES=	gettext-runtime:run
.  endif

CPE_VENDOR=	transmissionbt
.endif

USE_GITHUB=	yes

.if ${SLAVEPORT} != web
SLAVES=		cli daemon gtk qt
CMAKE_ON+=	ENABLE_${SLAVEPORT:tu}
CMAKE_OFF+=	${SLAVES:N${SLAVEPORT}:tu:S/^/ENABLE_/}

.  if ${SLAVEPORT:Nweb:Ncli}
CMAKE_OFF+=	ENABLE_UTILS
.  endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${SLAVEPORT}
CMAKE_ARGS+=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR}

OPTIONS_DEFINE+=	DOCS LITE NLS
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	OPENSSL

NLS_CMAKE_BOOL=		ENABLE_NLS

OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL WOLFSSL

OPENSSL_USES=		ssl
OPENSSL_CMAKE_ARGS=	-DWITH_CRYPTO="openssl"

WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
WOLFSSL_CMAKE_ARGS=	-DWITH_CRYPTO="cyassl"

LITE_CONFIGURE_ENABLE=	lightweight
LITE_CMAKE_BOOL=	ENABLE_LIGHTWEIGHT
.endif

post-extract:
	@${FIND} ${WRKSRC}/web -name .git* -delete

.if ${SLAVEPORT:Mweb}
	@${FIND} ${WRKSRC}/web \( -name '*.am' -o -name '*.in' \
		-o -name '*.scss' \) -delete

do-install:
	( cd ${WRKSRC} && ${COPYTREE_SHARE} web ${STAGEDIR}${DATADIR} )
.endif

.if ${SLAVEPORT:Mdaemon}
post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/home
.endif

.include <bsd.port.mk>
