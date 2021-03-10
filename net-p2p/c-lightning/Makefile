# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	c-lightning
# To build from an arbitrary git commit comment PORTVERSION and PORTREVISION (if present)
PORTVERSION=	0.9.3
DISTVERSIONPREFIX=	v
# and uncomment the following two lines (use for example -git-HEAD or -git-f8d8348c)
#PORTVERSION=	0
#PKGNAMESUFFIX=	-git-f8d8348c
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Lightning Network implementation in C

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>=1.0.14:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp \
		libsodium.so:security/libsodium \
		libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	bitcoin-cli:net-p2p/bitcoin-utils

USES=		autoreconf:build compiler:c11 gettext gmake libtool \
		python:3.5+,build
BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}
ALL_TARGET=	default

OPTIONS_DEFINE=		COMPATIBILITY DEVELOPER EXPERIMENTAL
OPTIONS_RADIO=		TESTING
OPTIONS_RADIO_TESTING=	ASAN VALGRIND

COMPATIBILITY_CONFIGURE_ENABLE=	compat
COMPATIBILITY_DESC=		Compatibility mode, good to disable to see if your software breaks
DEVELOPER_CONFIGURE_ENABLE=	developer
DEVELOPER_DESC=			Developer mode, good for testing
EXPERIMENTAL_CONFIGURE_ENABLE=	experimental-features
EXPERIMENTAL_DESC=		Enable experimental features
ASAN_CONFIGURE_ENABLE=		address-sanitizer
ASAN_DESC=			Compile with address-sanitizer
VALGRIND_CONFIGURE_ENABLE=	valgrind
VALGRIND_DESC=			Run tests with Valgrind

OPTIONS_DEFAULT=COMPATIBILITY

HAS_CONFIGURE=	yes

USE_GITHUB=	yes
.if defined(PKGNAMESUFFIX)
GIT_COMMIT=	${PKGNAMESUFFIX:C/-git-//}
.else
GIT_COMMIT=	${DISTVERSIONPREFIX}${PORTVERSION}
.endif
GH_TUPLE=	ElementsProject:lightning:${GIT_COMMIT} \
		ElementsProject:libwally-core:bf81e8b170690:ext1/external/libwally-core \
		ElementsProject:secp256k1-zkp:6370bdd537492:ext2/external/libwally-core/src/secp256k1 \
		ianlancetaylor:libbacktrace:5a99ff7fed66b8e:ext3/external/libbacktrace \
		zserge:jsmn:18e9fe42cbfe21d65076f5c77ae2be3:ext4/external/jsmn \
		valyala:gheap:67fc83bc953324f4759e52951921d:ext5/external/gheap

USERS=		c-lightning
GROUPS=		c-lightning

USE_RC_SUBR=	lightningd

SUB_FILES=	lightningd-bitcoin.conf.sample pkg-message
SUB_LIST=	U="${USERS}" G="${GROUPS}" LIGHTNINGD_BASE_DIR="${DESTDIR}/var/db/c-lightning"
PLIST_SUB=	U="${USERS}" G="${GROUPS}"

post-install:
	${INSTALL_DATA} \
		${WRKDIR}/lightningd-bitcoin.conf.sample \
		${STAGEDIR}${PREFIX}/etc/lightningd-bitcoin.conf.sample

.include <bsd.port.mk>
