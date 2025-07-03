PORTNAME=	zkgroup
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.4
PORTREVISION=	35
PORTEPOCH=	1
CATEGORIES=	net-im

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Library for the Signal Private Group System
WWW=		https://github.com/signalapp/zkgroup

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo java
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
JAVA_VERSION=	11+
USE_LDCONFIG=	yes

CARGO_CRATES=	aead-0.4.1 \
		aes-0.7.4 \
		aes-gcm-siv-0.10.0 \
		ascii-0.9.3 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bincode-1.3.3 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bstr-0.2.16 \
		bumpalo-3.7.0 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		cast-0.2.6 \
		cesu8-1.1.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		cipher-0.3.0 \
		clap-2.33.3 \
		combine-3.8.1 \
		cpufeatures-0.1.4 \
		criterion-0.3.4 \
		criterion-plot-0.4.3 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.5 \
		crossbeam-utils-0.8.5 \
		crypto-mac-0.7.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		ctr-0.7.0 \
		digest-0.8.1 \
		either-1.6.1 \
		error-chain-0.12.4 \
		fake-simd-0.1.2 \
		generic-array-0.12.4 \
		generic-array-0.14.4 \
		getrandom-0.1.16 \
		half-1.7.1 \
		hermit-abi-0.1.18 \
		hex-0.4.3 \
		hmac-0.7.1 \
		itertools-0.9.0 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		jni-0.16.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.51 \
		lazy_static-1.4.0 \
		libc-0.2.95 \
		log-0.4.14 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		oorandom-11.1.3 \
		opaque-debug-0.2.3 \
		opaque-debug-0.3.0 \
		packed_simd-0.3.3 \
		pest-2.1.3 \
		plotters-0.3.1 \
		plotters-backend-0.3.0 \
		plotters-svg-0.3.0 \
		polyval-0.5.1 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		rand_core-0.5.1 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rustc_version-0.3.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.126 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		sha2-0.8.2 \
		subtle-1.0.0 \
		subtle-2.4.0 \
		syn-1.0.72 \
		textwrap-0.11.0 \
		tinytemplate-1.2.1 \
		typenum-1.13.0 \
		ucd-trie-0.1.3 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		universal-hash-0.4.0 \
		unreachable-1.0.0 \
		version_check-0.9.3 \
		void-1.0.2 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.74 \
		wasm-bindgen-backend-0.2.74 \
		wasm-bindgen-macro-0.2.74 \
		wasm-bindgen-macro-support-0.2.74 \
		wasm-bindgen-shared-0.2.74 \
		web-sys-0.3.51 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zeroize-1.3.0 \
		poksho@git+https://github.com/signalapp/poksho.git\#8bb8c61c18e7bbe93c094ed91be52b9f96c1c5cd \
		curve25519-dalek@git+https://github.com/signalapp/curve25519-dalek.git?branch=lizard2\#477356e017c7cc2aa168f956786b34690870768f

PLIST_FILES=	lib/lib${PORTNAME}.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
