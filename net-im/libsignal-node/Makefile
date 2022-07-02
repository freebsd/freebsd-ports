PORTNAME=	libsignal
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/mikael/signal-desktop/:yarn
PKGNAMESUFFIX=	-node
DISTFILES=	libsignal-node-${DISTVERSION}-yarn-cache.tar.gz:yarn

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Platform-agnostic APIs used by the official Signal clients and servers

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf \
		yarn:www/yarn-node16

USES=		cargo gmake python:3.7+,build
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		aead-0.4.3 \
		aes-0.7.5 \
		aes-gcm-0.9.4 \
		aes-gcm-siv-0.10.3 \
		aho-corasick-0.7.18 \
		anyhow-1.0.56 \
		arrayref-0.3.6 \
		async-trait-0.1.52 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.64 \
		base16ct-0.1.1 \
		base64-0.13.0 \
		base64ct-1.5.0 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		blake2-0.9.2 \
		block-buffer-0.9.0 \
		block-modes-0.8.1 \
		block-padding-0.2.1 \
		bstr-0.2.17 \
		bumpalo-3.7.1 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cast-0.2.7 \
		cc-1.0.73 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		chacha20-0.7.3 \
		chacha20poly1305-0.8.2 \
		chrono-0.4.19 \
		cipher-0.3.0 \
		clap-2.34.0 \
		combine-4.6.3 \
		const-oid-0.7.1 \
		cpufeatures-0.2.2 \
		criterion-0.3.5 \
		criterion-plot-0.4.4 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		crypto-bigint-0.3.2 \
		crypto-mac-0.8.0 \
		crypto-mac-0.11.1 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		ctr-0.8.0 \
		der-0.5.1 \
		digest-0.9.0 \
		displaydoc-0.2.3 \
		ecdsa-0.13.4 \
		either-1.6.1 \
		elliptic-curve-0.11.12 \
		fastrand-1.7.0 \
		ff-0.11.0 \
		fixedbitset-0.4.1 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-core-0.3.21 \
		futures-macro-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		generic-array-0.14.5 \
		getrandom-0.1.16 \
		getrandom-0.2.5 \
		ghash-0.4.4 \
		gimli-0.26.1 \
		group-0.11.0 \
		half-1.8.2 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		hex-literal-0.3.4 \
		hkdf-0.11.0 \
		hmac-0.11.0 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		jni-0.19.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.56 \
		keccak-0.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		libloading-0.6.7 \
		libm-0.2.2 \
		linkme-0.2.10 \
		linkme-impl-0.2.10 \
		log-0.4.14 \
		log-panics-2.0.0 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		miniz_oxide-0.4.4 \
		multimap-0.8.3 \
		neon-0.10.0 \
		neon-build-0.10.0 \
		neon-macros-0.10.0 \
		neon-runtime-0.10.0 \
		num-bigint-0.4.3 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		num_enum-0.5.7 \
		num_enum_derive-0.5.7 \
		object-0.27.1 \
		oid-0.2.1 \
		once_cell-1.10.0 \
		oorandom-11.1.3 \
		opaque-debug-0.3.0 \
		openssl-0.10.38 \
		openssl-sys-0.9.72 \
		p256-0.10.1 \
		paste-1.0.6 \
		pem-0.8.3 \
		pest-2.1.3 \
		petgraph-0.6.0 \
		picky-6.3.0 \
		picky-asn1-0.3.3 \
		picky-asn1-der-0.2.5 \
		picky-asn1-x509-0.6.1 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		pkcs8-0.8.0 \
		pkg-config-0.3.24 \
		plotters-0.3.1 \
		plotters-backend-0.3.2 \
		plotters-svg-0.3.1 \
		poly1305-0.7.2 \
		polyval-0.5.3 \
		ppv-lite86-0.2.16 \
		proc-macro-crate-1.1.3 \
		proc-macro2-1.0.29 \
		prost-0.9.0 \
		prost-build-0.9.0 \
		prost-derive-0.9.0 \
		prost-types-0.9.0 \
		quote-1.0.10 \
		rand-0.7.3 \
		rand-0.8.5 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.3 \
		rand_hc-0.2.0 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.11 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rfc6979-0.1.0 \
		rsa-0.4.1 \
		rustc-demangle-0.1.21 \
		rustc_version-0.3.3 \
		rustc_version-0.4.0 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		sec1-0.2.1 \
		semver-0.9.0 \
		semver-0.11.0 \
		semver-1.0.6 \
		semver-parser-0.7.0 \
		semver-parser-0.10.2 \
		serde-1.0.136 \
		serde_bytes-0.11.5 \
		serde_cbor-0.11.2 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		sha-1-0.9.8 \
		sha2-0.9.9 \
		sha3-0.9.1 \
		signature-1.4.0 \
		simple_asn1-0.5.4 \
		slab-0.4.5 \
		smallvec-1.8.0 \
		snow-0.8.0 \
		spin-0.5.2 \
		spki-0.5.4 \
		static_assertions-1.1.0 \
		subtle-2.4.1 \
		syn-1.0.80 \
		syn-mid-0.5.3 \
		synstructure-0.12.6 \
		tempfile-3.3.0 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.1.43 \
		tinytemplate-1.2.1 \
		toml-0.5.8 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		universal-hash-0.4.1 \
		unzip3-1.0.0 \
		uuid-0.8.2 \
		variant_count-1.1.0 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		which-4.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x25519-dalek-1.1.1 \
		zeroize-1.3.0 \
		zeroize_derive-1.3.2 \
		num-bigint-dig@git+https://github.com/dignifiedquire/num-bigint?rev=56576b592fea6341b7e1711a1629e4cc1bfc419c\#56576b592fea6341b7e1711a1629e4cc1bfc419c \
		curve25519-dalek@git+https://github.com/signalapp/curve25519-dalek?branch=lizard2\#4f0aa6653c51598daa0a2f53b8ba54ce0eedfbdd

MAKE_ENV=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron18 \
		ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		HOME=${WRKDIR} \
		PYTHON=${PYTHON_CMD} \
		XDG_CACHE_HOME=${WRKDIR}/.cache

MAKE_ENV+=	RUSTC_BOOTSTRAP=aes,polyval

USE_LDCONFIG=		yes

PLIST_FILES=	lib/libsignal_node.so

NODE_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/:C/powerpc64.*/ppc64/}
RUST_ARCH=	${ARCH:S/amd64/x86_64/:S/i386/i686/}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
EXTRA_PATCHES=	${FILESDIR}/${ARCH}-patch-node_binding.gyp
.endif

post-patch:
	${REINPLACE_CMD} "s#python3#${PYTHON_CMD}#" \
		${WRKSRC}/node/binding.gyp

do-build:
	${ECHO_CMD} 'yarn-offline-mirror "../yarn-cache"' > ${WRKSRC}/.yarnrc
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile --ignore-optional --offline
	cd ${WRKSRC}/node && \
		${SETENV} ${MAKE_ENV} yarn tsc

do-install:
	${INSTALL_DATA} ${WRKSRC}/node/build/Release/obj.target/libsignal_client_freebsd_${NODE_ARCH}.node/geni/rust/${RUST_ARCH}-unknown-freebsd/release/libsignal_node.so \
		${STAGEDIR}${PREFIX}/lib/

create-caches-tarball:
	# do some cleanup first
	${RM} -r  ${WRKDIR}/.cache/yarn/v6/.tmp
	${FIND} ${WRKDIR}/.cache -type f -perm 755 -exec file {} \; | ${EGREP} "ELF|PE32+|Mach-O" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}

	cd ${WRKDIR} && \
		${TAR} czf libsignal-node-${DISTVERSION}-yarn-cache.tar.gz .cache yarn-cache

.include <bsd.port.mk>
