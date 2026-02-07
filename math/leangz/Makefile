PORTNAME=	leangz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.14
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lean 4 .olean file (de)compressor
WWW=		https://github.com/digama0/leangz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rust-nightly>0:lang/rust-nightly
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	digama0

CARGO_BUILDDEP=	no # because: error[E0658]: use of unstable library feature 'is_none_or'
CARGO_CRATES=	adler2-2.0.0 \
		allocator-api2-0.2.18 \
		byteorder-1.5.0 \
		cc-1.1.31 \
		cfg-if-1.0.0 \
		crc32fast-1.4.2 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		either-1.13.0 \
		equivalent-1.0.1 \
		flate2-1.0.34 \
		foldhash-0.1.3 \
		hashbrown-0.15.0 \
		itoa-1.0.11 \
		jobserver-0.1.32 \
		libc-0.2.161 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		miniz_oxide-0.8.0 \
		pkg-config-0.3.31 \
		proc-macro2-1.0.89 \
		quote-1.0.37 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		ryu-1.0.18 \
		serde-1.0.214 \
		serde_derive-1.0.214 \
		serde_json-1.0.132 \
		shlex-1.3.0 \
		syn-2.0.86 \
		unicode-ident-1.0.13 \
		zerocopy-0.8.8 \
		zerocopy-derive-0.8.8 \
		zstd-0.13.2 \
		zstd-safe-7.2.1 \
		zstd-sys-2.0.13+zstd.1.5.6

BIN_FILES=	bin/${PORTNAME} \
		bin/leantar
PLIST_FILES=	${BIN_FILES}

.include <bsd.port.mk>
