PORTNAME=	hashcat
PORTVERSION=	7.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Advanced CPU-based password recovery utility
WWW=		https://hashcat.net/hashcat/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

NOT_FOR_ARCHS=	powerpc powerpc64 powerpcspe i386
NOT_FOR_ARCHS_REASON=	highly optimized for specific CPUs

BUILD_DEPENDS=	minizip:archivers/minizip \
		rustc:lang/${RUST_DEFAULT}
LIB_DEPENDS=	libiconv.so:converters/libiconv

USES=		cargo compiler:c++11-lang gmake iconv localbase \
		python:3.12+,build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup:opencl Cyan4973:xxhash
GH_PROJECT=	OpenCL-Headers:opencl xxHash:xxhash
GH_SUBDIR=	deps/git/OpenCL-Headers:opencl deps/git/xxHash:xxhash
GH_TAGNAME=	1d3dc4e:opencl c0e86bc:xxhash
PYTHON_NO_DEPENDS=	yes

SHEBANG_FILES=	extra/tab_completion/install tools/*.py

CARGO_CARGOLOCK=	${WRKSRC}/Rust/generic_hash/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/Rust/generic_hash/Cargo.toml
CARGO_INSTALL=		no

MAKE_ARGS=	SHARED=1

ALL_TARGET=		default
MAKE_ARGS+=		CFLAGS_PYTHON=-I${LOCALBASE}/include/${PYTHON_VERSION}
CFLAGS_aarch64+=	-march=armv8-a+crc+crypto

BINARY_ALIAS=	python3-config ${PYTHON_VERSION}-config

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		BRAIN DOCS
OPTIONS_DEFAULT=	BRAIN
BRAIN_DESC=		Build Hashcat Brain
BRAIN_MAKE_ARGS_OFF=	ENABLE_BRAIN=0
BRAIN_CFLAGS=		-DWITH_BRAIN -Ideps/git/xxHash

.include <bsd.port.mk>
