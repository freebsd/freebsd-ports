PORTNAME=	monero-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.3.1
PORTREVISION=	5
CATEGORIES=	net-p2p finance

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Private, secure, untraceable, decentralised digital currency (CLI)
WWW=		https://getmonero.org/

LICENSE=	BSD3CLAUSE

BROKEN_SSL=	libressl
BROKEN_aarch64=	fails to compile: uses unavailable HWCAP_AES and getauxval

LIB_DEPENDS=	\
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libminiupnpc.so:net/miniupnpc \
		libnorm.so:net/norm \
		libpgm.so:net/openpgm \
		libsodium.so:security/libsodium \
		libunbound.so:dns/unbound \
		libzmq.so:net/libzmq4
BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/document.h:devel/rapidjson \
		${LOCALBASE}/include/zmq.hpp:net/cppzmq

USES=		cmake compiler:c++11-lib pkgconfig readline ssl
USE_GITHUB=	yes
.if defined(PKGNAMESUFFIX)
GIT_COMMIT=	${PKGNAMESUFFIX:C/-git-//}
.else
GIT_COMMIT=	${DISTVERSIONPREFIX}${PORTVERSION}
.endif
GH_TUPLE=	monero-project:monero:${GIT_COMMIT} \
		monero-project:supercop:633500ad8c875999:ext1/external/supercop \
		tevador:RandomX:85c527a62301b7b8be89d941:ext2/external/randomx \
		trezor:trezor-common:bff7fdfe436c727982c:ext3/external/trezor-common

CFLAGS+=	-D_WANT_SEMUN

OPTIONS_DEFINE=		DOXYGEN NATIVE
DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	BUILD_DOCUMENTATION
NATIVE_CMAKE_ON=	-DARCH=native
NATIVE_CMAKE_OFF=	-DARCH=default

.include <bsd.port.pre.mk>

# On FreeBSD 12.x the default ld(1) is LLVM's ld which needs an explicit -m option
# when linking without any input .o on the command line, like:
# /usr/bin/ld -melf_amd64 -r -b binary -o blocksdat.o blocks.dat
# See Bug 226996 - net-p2p/monero-cli: fails to link with lld as the system linker
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226996
.if ${ARCH} == aarch64
LD_EMULATION=	aarch64elf
.elif ${ARCH} == amd64
LD_EMULATION=	elf_amd64
.elif ${ARCH} == i386
LD_EMULATION=	elf_i386_fbsd
.elif ${ARCH} == powerpc
LD_EMULATION=	elf32ppc
.elif ${ARCH} == powerpc64
LD_EMULATION=	elf64ppc
.elif ${ARCH} == powerpc64le
LD_EMULATION=	elf64lppc
.endif

CMAKE_ARGS+=	-DLD_RAW_FLAGS:STRING=-m${LD_EMULATION}

# keep in sync with all platforms where libunwind is available
.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.else
CMAKE_ARGS+=	-DSTACK_TRACE:BOOL=OFF
.endif

CMAKE_ARGS+=	-DMANUAL_SUBMODULES:BOOL=ON

USE_RC_SUBR=	monerod

USERS=		monero
GROUPS=		monero

PLIST_FILES=	\
		bin/monero-blockchain-ancestry \
		bin/monero-blockchain-depth \
		bin/monero-blockchain-export \
		bin/monero-blockchain-import \
		bin/monero-blockchain-mark-spent-outputs \
		bin/monero-blockchain-prune \
		bin/monero-blockchain-prune-known-spent-data \
		bin/monero-blockchain-stats \
		bin/monero-blockchain-usage \
		bin/monero-gen-ssl-cert \
		bin/monero-gen-trusted-multisig \
		bin/monero-wallet-cli \
		bin/monero-wallet-rpc \
		bin/monerod

.include <bsd.port.post.mk>
