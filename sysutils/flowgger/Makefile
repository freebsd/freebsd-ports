# $FreeBSD$

PORTNAME=	flowgger
DISTVERSION=	0.2.6-28
DISTVERSIONSUFFIX=	-gab572a0
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast data collector

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

# gmake for backtrace-sys
USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_TUPLE=	Manishearth:rust-clippy:387efd459c0ad3db7af15f1a573057b8587f9748:clippy \
		zonyitoo:coio-rs:f5f6f4044a7cceff387ace0f04ffeb3bc3ab979a:coio \
		spicavigo:kafka-rust:9a3b427bd702810bcd13cf60e58cb18d5f403c1a:kafka

# Bumped openssl crates to 0.9.21 manually to support LibreSSL 2.6.x
CARGO_CRATES=	ansi_term-0.9.0 \
		atty-0.2.2 \
		backtrace-0.3.3 \
		backtrace-sys-0.1.14 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		build_const-0.2.0 \
		byteorder-0.5.3 \
		byteorder-1.1.0 \
		capnp-0.8.11 \
		capnpc-0.8.7 \
		cargo_metadata-0.2.3 \
		cc-1.0.0 \
		cfg-if-0.1.2 \
		chrono-0.4.0 \
		clap-2.26.2 \
		context-2.0.0 \
		conv-0.3.3 \
		crc-1.5.0 \
		crc-core-0.1.0 \
		custom_derive-0.1.7 \
		dbghelp-sys-0.2.0 \
		deque-0.3.2 \
		dtoa-0.2.2 \
		dtoa-0.4.2 \
		either-1.1.0 \
		error-chain-0.10.0 \
		flate2-0.2.20 \
		fnv-1.0.5 \
		foreign-types-0.2.0 \
		gcc-0.3.54 \
		getopts-0.2.15 \
		idna-0.1.4 \
		iovec-0.1.0 \
		itertools-0.6.3 \
		itoa-0.1.1 \
		itoa-0.3.4 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		lazycell-0.5.1 \
		libc-0.2.31 \
		linked-hash-map-0.4.2 \
		log-0.3.8 \
		magenta-0.1.1 \
		magenta-sys-0.1.1 \
		matches-0.1.6 \
		miniz-sys-0.1.10 \
		mio-0.6.10 \
		miow-0.2.1 \
		net2-0.2.31 \
		num-0.1.40 \
		num-integer-0.1.35 \
		num-iter-0.1.34 \
		num-traits-0.1.40 \
		openssl-0.9.21 \
		openssl-sys-0.9.21 \
		percent-encoding-1.0.0 \
		pkg-config-0.3.9 \
		pulldown-cmark-0.0.15 \
		quine-mc_cluskey-0.2.4 \
		quote-0.3.15 \
		rand-0.3.16 \
		redis-0.8.0 \
		redox_syscall-0.1.31 \
		ref_slice-1.1.1 \
		regex-syntax-0.4.1 \
		rustc-demangle-0.1.5 \
		rustc-serialize-0.3.24 \
		semver-0.6.0 \
		semver-parser-0.7.0 \
		serde-0.8.23 \
		serde-1.0.15 \
		serde_derive-1.0.15 \
		serde_derive_internals-0.16.0 \
		serde_json-0.8.6 \
		serde_json-1.0.3 \
		sha1-0.2.0 \
		slab-0.3.0 \
		snap-0.2.2 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		term_size-0.3.0 \
		textwrap-0.8.0 \
		time-0.1.38 \
		toml-0.2.1 \
		toml-0.4.5 \
		twox-hash-1.1.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.5 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		url-1.5.1 \
		vcpkg-0.2.2 \
		vec_map-0.8.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		ws2_32-sys-0.2.1
CARGO_USE_GITHUB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/flowgger.toml ${STAGEDIR}${PREFIX}/etc/flowgger.toml.sample

.include <bsd.port.mk>
