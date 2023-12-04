PORTNAME=	c-lightning
# To build from an arbitrary git commit comment PORTVERSION and PORTREVISION (if present)
PORTVERSION=	23.11
DISTVERSIONPREFIX=	v
# and uncomment the following two lines (use for example -git-HEAD or -git-f8d8348c)
#PORTVERSION=	0
#PKGNAMESUFFIX=	-git-f8d8348c
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Lightning Network implementation in C
WWW=		https://github.com/ElementsProject/lightning

LICENSE=	MIT

BROKEN_i386=	channeld/channeld.c:5153:8: error: format specifies type 'unsigned long' but the argument has type 'unsigned int' [-Werror,-Wformat]

BUILD_DEPENDS=	bash:shells/bash \
		lowdown:textproc/lowdown \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.14:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mrkd>=0.2.0_1:devel/py-mrkd@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp \
		libsodium.so:security/libsodium
RUN_DEPENDS=	bitcoin-cli:net-p2p/bitcoin-utils

USES=		autoreconf:build \
		compiler:c11 \
		cpe \
		gettext \
		gmake \
		libtool \
		python:build \
		shebangfix
CPE_VENDOR=	elementsproject
BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}
ALL_TARGET=	default
SHEBANG_FILES=	plugins/clnrest/clnrest.py \
		tools/reckless

EXTRA_PATCHES_aarch64=	${FILESDIR}/extra-patch-external_libwally-core_src_ccan_ccan_base64_base64.c
EXTRA_PATCHES=	${EXTRA_PATCHES_${ARCH}}

OPTIONS_DEFINE=		COMPATIBILITY DEBUG
OPTIONS_MULTI=		STORAGE
OPTIONS_MULTI_STORAGE=	POSTGRESQL SQLITE
OPTIONS_RADIO=		TESTING
OPTIONS_RADIO_TESTING=	ASAN VALGRIND

COMPATIBILITY_CONFIGURE_ENABLE=	compat
COMPATIBILITY_DESC=		Compatibility mode, good to disable to see if your software breaks
DEBUG_CONFIGURE_ENABLE=		debugbuild
DEBUG_DESC=			Extra debug checks in the build, good for testing
POSTGRESQL_DESC=		Use PostgreSQL for storage
POSTGRESQL_USES=		pgsql
WANT_PGSQL=			client
SQLITE_DESC=			Use SQLite for storage
SQLITE_USES=			sqlite:3
ASAN_CONFIGURE_ENABLE=		address-sanitizer
ASAN_DESC=			Compile with address-sanitizer
VALGRIND_CONFIGURE_ENABLE=	valgrind
VALGRIND_DESC=			Run tests with Valgrind

OPTIONS_DEFAULT=COMPATIBILITY SQLITE

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-rust

USE_GITHUB=	yes
.if defined(PKGNAMESUFFIX)
GIT_COMMIT=	${PKGNAMESUFFIX:C/-git-//}
.else
GIT_COMMIT=	${DISTVERSIONPREFIX}${PORTVERSION}
.endif
GH_TUPLE=	ElementsProject:lightning:${GIT_COMMIT} \
		ElementsProject:libwally-core:bb4cd3ac802c7:ext1/external/libwally-core \
		ElementsProject:secp256k1-zkp:ff33018fe765d:ext2/external/libwally-core/src/secp256k1 \
		ianlancetaylor:libbacktrace:2446c66076480ce:ext3/external/libbacktrace \
		zserge:jsmn:18e9fe42cbfe21d65076f5c77ae2be3:ext4/external/jsmn \
		valyala:gheap:67fc83bc953324f4759e52951921d:ext5/external/gheap

USERS=		c-lightning
GROUPS=		c-lightning

USE_RC_SUBR=	lightningd

SUB_FILES=	lightningd-bitcoin.conf.sample pkg-message
SUB_LIST=	U="${USERS}" G="${GROUPS}" LIGHTNINGD_BASE_DIR="${DESTDIR}/var/db/c-lightning"
PLIST_SUB=	U="${USERS}" G="${GROUPS}"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CPPFLAGS+=       -Wno-error=unused-but-set-variable
.endif

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/cln-renepay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/commando
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/fetchinvoice
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/funder
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/keysend
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/offers
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/pay
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/spenderp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/sql
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/topology
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/c-lightning/plugins/txprepare
	${INSTALL_DATA} \
		${WRKDIR}/lightningd-bitcoin.conf.sample \
		${STAGEDIR}${PREFIX}/etc/lightningd-bitcoin.conf.sample

.include <bsd.port.post.mk>
