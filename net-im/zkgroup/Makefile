PORTNAME=	zkgroup
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Library for the Signal Private Group System

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	signalapp:curve25519-dalek:477356e017c7cc2aa168f956786b34690870768f:curvedalek \
		signalapp:poksho:v0.7.0:poksho
USE_JAVA=	yes
JAVA_VERSION=	11+
USE_LDCONFIG=	yes

CARGO_CRATES=	aead-0.2.0 \
		aes-0.3.2 \
		aes-gcm-siv-0.4.1 \
		aes-soft-0.3.3 \
		aesni-0.6.0 \
		ascii-0.9.3 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bincode-1.2.1 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-cipher-trait-0.6.2 \
		block-padding-0.1.5 \
		bstr-0.2.12 \
		bumpalo-3.2.1 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		cast-0.2.3 \
		cesu8-1.1.0 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		combine-3.8.1 \
		criterion-0.3.1 \
		criterion-plot-0.4.1 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		crypto-mac-0.7.0 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		digest-0.8.1 \
		either-1.5.3 \
		error-chain-0.12.2 \
		fake-simd-0.1.2 \
		generic-array-0.12.3 \
		getrandom-0.1.14 \
		hermit-abi-0.1.10 \
		hex-0.4.2 \
		hmac-0.7.1 \
		itertools-0.8.2 \
		itoa-0.4.5 \
		jni-0.16.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.37 \
		lazy_static-1.4.0 \
		libc-0.2.67 \
		log-0.4.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memoffset-0.5.4 \
		num-traits-0.2.11 \
		num_cpus-1.12.0 \
		oorandom-11.1.0 \
		opaque-debug-0.2.3 \
		packed_simd-0.3.3 \
		plotters-0.2.12 \
		polyval-0.3.3 \
		proc-macro2-1.0.9 \
		quote-1.0.3 \
		rand_core-0.5.1 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		regex-1.3.6 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.17 \
		rustc_version-0.2.3 \
		ryu-1.0.3 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.51 \
		sha2-0.8.1 \
		subtle-1.0.0 \
		subtle-2.2.2 \
		syn-1.0.16 \
		textwrap-0.11.0 \
		tinytemplate-1.0.3 \
		typenum-1.11.2 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		universal-hash-0.3.0 \
		unreachable-1.0.0 \
		version_check-0.9.1 \
		void-1.0.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.60 \
		wasm-bindgen-backend-0.2.60 \
		wasm-bindgen-macro-0.2.60 \
		wasm-bindgen-macro-support-0.2.60 \
		wasm-bindgen-shared-0.2.60 \
		web-sys-0.3.37 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zeroize-1.1.0
CARGO_USE_GITHUB=	yes

PLIST_FILES=	lib/lib${PORTNAME}.so

do-install:
	${INSTALL_LIB} ${WRKDIR}/target/release/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
