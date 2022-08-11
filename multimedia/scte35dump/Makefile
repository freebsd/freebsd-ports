PORTNAME=	scte35dump
DISTVERSION=	0.1.6
PORTREVISION=	12
CATEGORIES=	multimedia

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Dump SCTE-35 data from a Transport Stream

LICENSE=	MIT

USES=		cargo ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	m2amedia

CARGO_CRATES=	aho-corasick-0.7.4 \
		ansi_term-0.11.0 \
		arrayvec-0.3.25 \
		arrayvec-0.4.11 \
		atty-0.2.13 \
		base64-0.10.1 \
		bitflags-1.1.0 \
		bitreader-0.3.1 \
		byteorder-1.3.2 \
		cfg-if-0.1.9 \
		clap-2.33.0 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		env_logger-0.6.2 \
		fixedbitset-0.1.9 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		hex-0.3.2 \
		hexdump-0.1.0 \
		humantime-1.2.0 \
		iovec-0.1.2 \
		itertools-0.4.19 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.60 \
		log-0.4.7 \
		memchr-2.2.1 \
		mio-0.6.19 \
		miow-0.2.1 \
		mpeg2ts-reader-0.13.0 \
		net2-0.2.33 \
		nodrop-0.1.13 \
		odds-0.2.26 \
		proc-macro2-0.4.30 \
		quick-error-1.2.2 \
		quote-0.6.13 \
		regex-1.1.9 \
		regex-syntax-0.6.8 \
		rtp-rs-0.3.0 \
		rustc_version-0.2.3 \
		scte35-reader-0.11.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.97 \
		serde_derive-1.0.97 \
		serdebug-1.0.5 \
		serdebug_derive-1.0.0 \
		slab-0.4.2 \
		smpte2022-1-fec-0.2.0 \
		smpte2022-1-packet-0.4.0 \
		strsim-0.8.0 \
		syn-0.14.9 \
		syn-0.15.39 \
		termcolor-1.0.5 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.3 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/scte35dump

.include <bsd.port.mk>
