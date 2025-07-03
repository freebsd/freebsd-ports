PORTNAME=	c-lightning
# To build from an arbitrary git commit comment PORTVERSION and PORTREVISION (if present)
PORTVERSION=	25.02.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
# and uncomment the following two lines (use for example -git-HEAD or -git-f8d8348c)
#PORTVERSION=	0
#PKGNAMESUFFIX=	-git-f8d8348c
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Lightning Network implementation in C
WWW=		https://github.com/ElementsProject/lightning

LICENSE=	MIT

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed \
		lowdown:textproc/lowdown \
		jq:textproc/jq \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.14:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mrkd>=0.2.0_1:devel/py-mrkd@${PY_FLAVOR}
LIB_DEPENDS=	libsodium.so:security/libsodium
RUN_DEPENDS=	bitcoin-cli:net-p2p/bitcoin-utils

USES=		autoreconf:build \
		compiler:c11 \
		cpe \
		gettext-tools:build \
		gmake \
		libtool \
		shebangfix
CPE_VENDOR=	elementsproject
BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD} sed=${LOCALBASE}/bin/gsed
ALL_TARGET=	default
SHEBANG_FILES=	plugins/wss-proxy/wss-proxy.py \
		tools/reckless

OPTIONS_DEFINE=		COMPATIBILITY DEBUG RUST WSSPROXYDEPS
OPTIONS_MULTI=		STORAGE
OPTIONS_MULTI_STORAGE=	POSTGRESQL SQLITE
OPTIONS_RADIO=		TESTING
OPTIONS_RADIO_TESTING=	ASAN VALGRIND
OPTIONS_SUB=		yes

COMPATIBILITY_CONFIGURE_ENABLE=	compat
COMPATIBILITY_DESC=		Compatibility mode, good to disable to see if your software breaks
DEBUG_CONFIGURE_ENABLE=		debugbuild
DEBUG_DESC=			Extra debug checks in the build, good for testing
POSTGRESQL_DESC=		Use PostgreSQL for storage
POSTGRESQL_USES=		pgsql
WANT_PGSQL=			client
RUST_CONFIGURE_ENABLE=		rust
RUST_DESC=			Install cln-grpc and clnrest plugins (Rust dependent)
RUST_USES=			cargo
RUST_BUILD_DEPENDS=		protobuf>=29:devel/protobuf
CARGO_INSTALL=			no
SQLITE_DESC=			Use SQLite for storage
SQLITE_USES=			sqlite:3
ASAN_CONFIGURE_ENABLE=		address-sanitizer
ASAN_DESC=			Compile with address-sanitizer
VALGRIND_CONFIGURE_ENABLE=	valgrind
VALGRIND_DESC=			Run tests with Valgrind
WSSPROXYDEPS_DESC=		Install and depend on packages required by the wss-proxy plugin
# run files/check_python_plugins_deps.sh to verify the list below
WSSPROXYDEPS_RUN_DEPENDS=\
	${PYTHON_PKGNAMEPREFIX}asn1crypto>0:devel/py-asn1crypto@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}base58>0:security/py-base58@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}bitarray>0:devel/py-bitarray@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}bitstring>0:devel/py-bitstring@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}coincurve>0:security/py-coincurve@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pycparser>0:devel/py-pycparser@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pyln-bolt7>0:net-p2p/pyln-bolt7@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pyln-client>0:net-p2p/pyln-client@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pyln-proto>0:net-p2p/pyln-proto@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}websockets>0:devel/py-websockets@${PY_FLAVOR}

OPTIONS_DEFAULT=COMPATIBILITY RUST SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWSSPROXYDEPS}
USES+=		python:3.9+
USE_PYTHON+=	cryptography
.else
USES+=		python:build
.endif

HAS_CONFIGURE=	yes

# Print the compilation commands (verbose).
MAKE_ARGS=	V=1 mandir=${PREFIX}/share/man

USE_GITHUB=	yes
.if defined(PKGNAMESUFFIX)
GIT_COMMIT=	${PKGNAMESUFFIX:C/-git-//}
.else
GIT_COMMIT=	${DISTVERSIONPREFIX}${PORTVERSION}
.endif
GH_TUPLE=	ElementsProject:lightning:${GIT_COMMIT} \
		ElementsProject:libwally-core:11e1bf6d60a13:ext1/external/libwally-core \
		BlockstreamResearch:secp256k1-zkp:1e04d3244:ext2/external/libwally-core/src/secp256k1 \
		ianlancetaylor:libbacktrace:2446c66076480ce:ext3/external/libbacktrace \
		zserge:jsmn:18e9fe42cbfe21d65076f5c77ae2be3:ext4/external/jsmn \
		valyala:gheap:67fc83bc953324f4759e52951921d:ext5/external/gheap

USERS=		c-lightning
GROUPS=		c-lightning

USE_RC_SUBR=	lightningd

SUB_FILES=	lightningd-bitcoin.conf.sample pkg-message
SUB_LIST=	U="${USERS}" G="${GROUPS}" LIGHTNINGD_BASE_DIR="${DESTDIR}/var/db/c-lightning"
PLIST_SUB+=	U="${USERS}" G="${GROUPS}"

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s|python3|${PYTHON_CMD}|" \
		${WRKSRC}/plugins/wss-proxy/wss-proxy

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lightning-cli
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lightning-hsmtool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lightningd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_channeld
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_closingd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_connectd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_dualopend
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_gossipd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_hsmd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_onchaind
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_openingd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/lightning_websocketd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/autoclean
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/bcli
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/bookkeeper
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/chanbackup
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/cln-askrene
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/cln-renepay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/cln-xpay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/commando
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/exposesecret
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/funder
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/keysend
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/offers
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/pay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/recklessrpc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/recover
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/spenderp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/sql
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/topology
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/txprepare
.if ${PORT_OPTIONS:MRUST}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/cln-grpc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/clnrest
.endif
	${INSTALL_DATA} \
		${WRKDIR}/lightningd-bitcoin.conf.sample \
		${STAGEDIR}${PREFIX}/etc/lightningd-bitcoin.conf.sample

.include <bsd.port.post.mk>
