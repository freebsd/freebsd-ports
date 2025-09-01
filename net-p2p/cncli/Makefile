PORTNAME=		cncli
DISTVERSIONPREFIX=	v
DISTVERSION=		6.0.1
PORTREVISION=	14
CATEGORIES=		net-p2p

MAINTAINER=		boris@zfs.ninja
COMMENT=		A community-based cardano-node CLI tool
WWW=			https://cardano-community.github.io/guild-operators/

LICENSE=		APACHE20

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	cryptoxide Rust crate uses AVX2 instructions

USES=		autoreconf:build cargo gmake libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	cardano-community input-output-hk:sodium
GH_PROJECT=	${PORTNAME} libsodium:sodium
GH_TAGNAME=	${LIBSODIUM_HASH}:sodium

LIBSODIUM_HASH=	dbb48cce5429cb6585c9034f002568964f1ce567
LIBS_PREFIX=	${WRKDIR}/libs_install

CARGO_ENV=	SODIUM_LIB_DIR=${LIBS_PREFIX}${PREFIX}/lib SODIUM_INCLUDE_DIR=${LIBS_PREFIX}${PREFIX}/include

PLIST_FILES=	bin/cncli

CARGO_BUILD_TARGET=	${_CARGO_RUST_ARCH_${ARCH}:U${ARCH}}-unknown-${OPSYS:tl}
CARGO_ENV+= \
		CARGO_BUILD_TARGET=${CARGO_BUILD_TARGET} \
		CARGO_TARGET_${CARGO_BUILD_TARGET:S/-/_/g:tu}_LINKER="${CC}"

pre-build:
		cd ${WRKSRC_sodium} && ./autogen.sh
		cd ${WRKSRC_sodium} && ./configure --prefix=${PREFIX} --with-pthreads --disable-shared
		cd ${WRKSRC_sodium} && gmake -j${MAKE_JOBS_NUMBER} && gmake DESTDIR=${LIBS_PREFIX} install
		${MKDIR} ${LIBS_PREFIX}${PREFIX}/libdata/pkgconfig
		${MV} ${LIBS_PREFIX}${PREFIX}/lib/pkgconfig/libsodium.pc ${LIBS_PREFIX}${PREFIX}/libdata/pkgconfig/libsodium.pc

.include <bsd.port.mk>
