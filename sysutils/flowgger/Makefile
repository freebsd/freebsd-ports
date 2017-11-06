# $FreeBSD$

PORTNAME=	flowgger
PORTVERSION=	g20170616
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast data collector

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_PROJECT=	flowgger
GH_TAGNAME=	fbb8313
GH_TUPLE=	Manishearth:rust-clippy:dfc7d2afd40bad878a145e783b4abce3dc30c0eb:clippy \
		zonyitoo:coio-rs:269eda9d9b67ca465ab2a1d790364654a90746fd:coio \
		spicavigo:kafka-rust:38e046cf56877510e2a944e1a6cc36859b664ff5:kafka

PLIST_FILES=	bin/flowgger

CARGO_CRATES=	ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.9.1 \
		byteorder-0.5.3 \
		byteorder-1.0.0 \
		capnp-0.8.10 \
		capnpc-0.8.5 \
		cargo_metadata-0.2.1 \
		cfg-if-0.1.0 \
		chrono-0.3.1 \
		clap-2.26.0 \
		context-1.0.1 \
		crc-1.4.0 \
		deque-0.3.2 \
		dtoa-0.2.2 \
		dtoa-0.4.1 \
		flate2-0.2.19 \
		fnv-1.0.5 \
		foreign-types-0.2.0 \
		gcc-0.3.46 \
		gdi32-sys-0.2.0 \
		idna-0.1.1 \
		iovec-0.1.0 \
		itoa-0.1.1 \
		itoa-0.3.1 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		lazycell-0.4.0 \
		libc-0.2.22 \
		linked-hash-map-0.3.0 \
		log-0.3.7 \
		matches-0.1.4 \
		miniz-sys-0.1.9 \
		mio-0.6.7 \
		miow-0.2.1 \
		net2-0.2.29 \
		num-0.1.37 \
		num-integer-0.1.34 \
		num-iter-0.1.33 \
		num-traits-0.1.37 \
		openssl-0.9.15 \
		openssl-sys-0.9.15 \
		pkg-config-0.3.9 \
		quine-mc_cluskey-0.2.4 \
		quote-0.3.15 \
		rand-0.3.15 \
		redis-0.8.0 \
		redox_syscall-0.1.17 \
		ref_slice-1.1.1 \
		regex-syntax-0.4.0 \
		rustc-serialize-0.3.24 \
		semver-0.6.0 \
		semver-parser-0.7.0 \
		serde-0.8.23 \
		serde-1.0.4 \
		serde_derive-1.0.4 \
		serde_derive_internals-0.15.0 \
		serde_json-0.8.6 \
		serde_json-1.0.2 \
		sha1-0.2.0 \
		slab-0.3.0 \
		snap-0.2.1 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		term_size-0.3.0 \
		textwrap-0.7.0 \
		time-0.1.37 \
		toml-0.2.1 \
		toml-0.4.1 \
		twox-hash-1.1.0 \
		unicode-bidi-0.2.5 \
		unicode-normalization-0.1.4 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		url-1.4.0 \
		user32-sys-0.2.0 \
		vec_map-0.8.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		ws2_32-sys-0.2.1
CARGO_USE_GITHUB=	yes

.include <bsd.port.mk>
