PORTNAME=	leangz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lean 4 .olean file (de)compressor
WWW=		https://github.com/digama0/leangz

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	digama0

CARGO_CRATES=	adler-1.0.2 \
		ahash-0.8.3 \
		allocator-api2-0.2.15 \
		autocfg-1.1.0 \
		byteorder-1.4.3 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		either-1.8.1 \
		flate2-1.0.26 \
		hashbrown-0.14.0 \
		hermit-abi-0.2.6 \
		itoa-1.0.8 \
		jobserver-0.1.26 \
		libc-0.2.146 \
		memmap2-0.9.0 \
		memoffset-0.9.0 \
		miniz_oxide-0.7.1 \
		num_cpus-1.15.0 \
		once_cell-1.18.0 \
		pkg-config-0.3.27 \
		proc-macro2-1.0.70 \
		quote-1.0.28 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		ryu-1.0.14 \
		scopeguard-1.1.0 \
		serde-1.0.166 \
		serde_json-1.0.99 \
		syn-2.0.39 \
		unicode-ident-1.0.9 \
		version_check-0.9.4 \
		zerocopy-0.7.29 \
		zerocopy-derive-0.7.29 \
		zstd-0.13.0 \
		zstd-safe-7.0.0 \
		zstd-sys-2.0.8+zstd.1.5.5

BIN_FILES=	bin/${PORTNAME} \
		bin/leantar
PLIST_FILES=	${BIN_FILES}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${BIN_FILES}

.include <bsd.port.mk>
