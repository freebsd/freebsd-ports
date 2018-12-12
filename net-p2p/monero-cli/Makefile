# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	monero-cli
# To build from an arbitrary git commit comment PORTVERSION and PORTREVISION (if present)
PORTVERSION=	0.13.0.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
# and uncomment the following two lines
#PORTVERSION=	0
#PKGNAMESUFFIX=	-git-HEAD
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Private, secure, untraceable, decentralised digital currency (CLI)

LICENSE=	BSD3CLAUSE

BROKEN_aarch64=		fails to compile: the clang compiler does not support -march=native
BROKEN_armv6=		fails to compile: the clang compiler does not support -march=native
BROKEN_armv7=		fails to compile: the clang compiler does not support -march=native
BROKEN_powerpc64=	fails to compile: the clang compiler does not support -march=native

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
		libunwind.so:devel/libunwind \
		libzmq.so:net/libzmq4
BUILD_DEPENDS=	${LOCALBASE}/include/rapidjson/document.h:devel/rapidjson \
		${LOCALBASE}/include/zmq.hpp:net/cppzmq

USES=		cmake compiler:c++11-lib pkgconfig readline ssl
USE_GITHUB=	yes

GH_ACCOUNT=	monero-project
GH_PROJECT=	monero
.if defined(PKGNAMESUFFIX)
GH_TAGNAME=	${PKGNAMESUFFIX:C/-git-//}
.endif
CFLAGS+=	-D_WANT_SEMUN

OPTIONS_DEFINE=		DOXYGEN
DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	BUILD_DOCUMENTATION

.include <bsd.port.pre.mk>

# On FreeBSD 12.x the default ld(1) is LLVM's ld which needs an explicit -m option
# when linking without any input .o on the command line, like:
# /usr/bin/ld -melf_amd64 -r -b binary -o blocksdat.o blocks.dat
# See Bug 226996 - net-p2p/monero-cli: fails to link with lld as the system linker
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226996
.if ${OSVERSION} >= 1200000

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
.endif

CMAKE_ARGS+=	-DLD_RAW_FLAGS:STRING=-m${LD_EMULATION}

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
		bin/monero-blockchain-usage \
		bin/monero-gen-trusted-multisig \
		bin/monero-wallet-cli \
		bin/monero-wallet-rpc \
		bin/monerod

.include <bsd.port.post.mk>
