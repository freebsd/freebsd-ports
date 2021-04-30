PORTNAME=	scte35dump
DISTVERSION=	0.1.6
CATEGORIES=	multimedia

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Dump SCTE-35 data from a Transport Stream

LICENSE=	MIT

USES=		cargo ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	m2amedia

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		arrayvec-0.4.12 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		base64-0.10.1 \
		bitflags-1.2.1 \
		bitreader-0.3.3 \
		byteorder-1.4.3 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		env_logger-0.6.2 \
		fixedbitset-0.4.0 \
		form_urlencoded-1.0.1 \
		four-cc-0.1.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		hermit-abi-0.1.18 \
		hex-0.3.2 \
		hex-slice-0.1.4 \
		hexdump-0.1.1 \
		humantime-1.3.0 \
		idna-0.2.2 \
		iovec-0.1.4 \
		itertools-0.4.19 \
		kernel32-sys-0.2.2 \
		libc-0.2.93 \
		log-0.4.14 \
		matches-0.1.8 \
		memchr-2.3.4 \
		mio-0.6.23 \
		miow-0.2.2 \
		mpeg2ts-reader-0.14.0 \
		net2-0.2.37 \
		nodrop-0.1.14 \
		percent-encoding-2.1.0 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.26 \
		quick-error-1.2.3 \
		quote-0.6.13 \
		quote-1.0.9 \
		regex-1.4.5 \
		regex-syntax-0.6.23 \
		rtp-rs-0.3.0 \
		rtp-rs-0.5.0 \
		rustc_version-0.2.3 \
		scte35-reader-0.13.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.125 \
		serde_derive-1.0.125 \
		serdebug-1.0.5 \
		serdebug_derive-1.0.0 \
		slab-0.4.2 \
		smpte2022-1-fec-0.2.0 \
		smpte2022-1-packet-0.4.0 \
		smptera-format-identifiers-rust-0.3.0 \
		strsim-0.8.0 \
		syn-0.14.9 \
		syn-1.0.69 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.17 \
		unicode-width-0.1.8 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.1 \
		url-2.2.1 \
		vec_map-0.8.2 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/scte35dump

.include <bsd.port.mk>
