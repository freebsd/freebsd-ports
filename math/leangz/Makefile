PORTNAME=	leangz
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.13
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
		ahash-0.8.11 \
		allocator-api2-0.2.18 \
		byteorder-1.5.0 \
		cc-1.0.98 \
		cfg-if-1.0.0 \
		crc32fast-1.4.2 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		either-1.12.0 \
		flate2-1.0.30 \
		hashbrown-0.14.5 \
		itoa-1.0.11 \
		jobserver-0.1.31 \
		libc-0.2.155 \
		memmap2-0.9.4 \
		miniz_oxide-0.7.3 \
		once_cell-1.19.0 \
		pkg-config-0.3.30 \
		proc-macro2-1.0.83 \
		quote-1.0.36 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		ryu-1.0.18 \
		serde-1.0.202 \
		serde_derive-1.0.202 \
		serde_json-1.0.117 \
		syn-2.0.65 \
		unicode-ident-1.0.12 \
		version_check-0.9.4 \
		zerocopy-0.7.34 \
		zerocopy-derive-0.7.34 \
		zstd-0.13.1 \
		zstd-safe-7.1.0 \
		zstd-sys-2.0.10+zstd.1.5.6

BIN_FILES=	bin/${PORTNAME} \
		bin/leantar
PLIST_FILES=	${BIN_FILES}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${BIN_FILES}

.include <bsd.port.mk>
