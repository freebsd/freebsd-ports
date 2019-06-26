# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	zetacoin
PORTVERSION=	0.11.2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	27
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency with quick transactions

LICENSE=	MIT

BROKEN=		fails to build with boost 1.70, see bug 237017

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs

USES+=		autoreconf compiler:c++11-lang gmake libtool pkgconfig:build ssl
USE_CXXSTD=	c++11
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

BROKEN_armv6=		AtomicPointer not implemented
BROKEN_powerpc64=	fails to configure: No working boost sleep implementation found

USE_GITHUB=	yes

OPTIONS_DEFINE=	UPNP WALLET CLI TEST
OPTIONS_SUB=	yes

WALLET_DESC=	Build wallet or P2P server node only
CLI_DESC=		Build command line RPC client

OPTIONS_DEFAULT=	WALLET

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=		-L${LOCALBASE}/lib

WALLET_CONFIGURE_ENABLE=wallet
WALLET_CXXFLAGS=	-I${BDB_INCLUDE_DIR}
WALLET_LIBS=		-L${BDB_LIB_DIR}
WALLET_USES=		bdb:48

CLI_CONFIGURE_WITH=	cli

TEST_CONFIGURE_ENABLE=	tests
TEST_ALL_TARGET=	check

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-daemon
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl" \
		OBJC="${CC}" OBJCFLAGS="${CFLAGS}" OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"

QT_BINARY=	${PORTNAME}-qt
CLI_BINARY=	${PORTNAME}-cli
DAEMON=		${PORTNAME}d

PLIST_SUB+=	EXECUTABLE_QT=bin/${QT_BINARY} \
		EXECUTABLE_CLI=bin/${CLI_BINARY} \
		EXECUTABLE_DAEMON=bin/${DAEMON} \
		PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

# tests will currently fail
.if ${PORT_OPTIONS:MTEST}
BROKEN=	automated testing fails
.endif

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	checking for RAND_egd in -lcrypto... no
BROKEN_FreeBSD_13=	checking for RAND_egd in -lcrypto... no
.endif

.if ${SSL_DEFAULT:Mlibressl*}
# The configure script will output this message, so save the user the trouble
IGNORE=	detected LibreSSL: This is NOT supported, and may break consensus compatibility!
.endif

post-patch:
	${MKDIR} ${WRKSRC}/src/build-aux

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${DAEMON} ${STAGEDIR}${PREFIX}/bin/${DAEMON}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

do-install-CLI-on:
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${CLI_BINARY} ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}

.include <bsd.port.post.mk>
