PORTNAME=	narrowlink
DISTVERSION=	0.2.6
PORTREVISION=	9
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Self-hosted solution for secure connectivity between devices
WWW=		https://narrowlink.com \
		https://github.com/narrowlink/narrowlink

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_powerpc64le=	build breaks due to panic in the ring crate: alled `Option::unwrap()` on a `None` value, see https://github.com/briansmith/ring/issues/1904

USES=		cargo
USE_RC_SUBR=	narrowlink-agent narrowlink-gateway
USE_GITHUB=	yes

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

CARGO_CRATES=	addr2line-0.22.0 \
		adler-1.0.2 \
		aead-0.5.2 \
		ahash-0.8.11 \
		aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anyhow-1.0.86 \
		arrayvec-0.7.4 \
		askama-0.12.1 \
		askama_derive-0.12.5 \
		askama_escape-0.10.3 \
		askama_parser-0.2.1 \
		asn1-rs-0.5.2 \
		asn1-rs-derive-0.4.0 \
		asn1-rs-impl-0.1.0 \
		async-recursion-1.1.1 \
		async-stream-0.3.5 \
		async-stream-impl-0.3.5 \
		async-trait-0.1.80 \
		autocfg-1.3.0 \
		backtrace-0.3.73 \
		base64-0.21.7 \
		base64-0.22.1 \
		bindgen-0.69.4 \
		bitflags-2.5.0 \
		block-buffer-0.10.4 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		bytes-1.6.0 \
		c2rust-bitfields-0.18.0 \
		c2rust-bitfields-derive-0.18.0 \
		cc-1.0.99 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chacha20-0.9.1 \
		chacha20poly1305-0.10.1 \
		chrono-0.4.38 \
		chunkio-0.0.1 \
		cipher-0.4.4 \
		clang-sys-1.8.1 \
		clap_lex-0.7.1 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.6 \
		cpufeatures-0.2.12 \
		crossbeam-channel-0.5.13 \
		crossbeam-utils-0.8.20 \
		crypto-common-0.1.6 \
		daemonize-0.5.0 \
		darling-0.20.9 \
		darling_core-0.20.9 \
		darling_macro-0.20.9 \
		data-encoding-2.6.0 \
		der-parser-8.2.0 \
		deranged-0.3.11 \
		digest-0.10.7 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		displaydoc-0.2.5 \
		either-1.12.0 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		etherparse-0.14.3 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		futures-0.3.30 \
		futures-channel-0.3.30 \
		futures-core-0.3.30 \
		futures-executor-0.3.30 \
		futures-io-0.3.30 \
		futures-macro-0.3.30 \
		futures-sink-0.3.30 \
		futures-task-0.3.30 \
		futures-timer-3.0.3 \
		futures-util-0.3.30 \
		generic-array-0.14.7 \
		getrandom-0.2.15 \
		gimli-0.29.0 \
		glob-0.3.1 \
		h2-0.3.26 \
		hashbrown-0.14.5 \
		hermit-abi-0.3.9 \
		hmac-0.12.1 \
		home-0.5.9 \
		http-0.2.12 \
		http-body-0.4.6 \
		httparse-1.9.4 \
		httpdate-1.0.3 \
		hyper-0.14.29 \
		hyper-rustls-0.24.2 \
		iana-time-zone-0.1.60 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		idna-0.4.0 \
		idna-0.5.0 \
		if_chain-1.0.2 \
		indexmap-2.2.6 \
		inout-0.1.3 \
		instant-acme-0.4.3 \
		ioctl-sys-0.8.0 \
		ipnet-2.9.0 \
		ipstack-0.0.10 \
		itertools-0.12.1 \
		itoa-1.0.11 \
		js-sys-0.3.69 \
		jsonwebtoken-9.3.0 \
		keccak-0.1.5 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.155 \
		libloading-0.8.3 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.12 \
		log-0.4.21 \
		memchr-2.7.4 \
		mime-0.3.17 \
		mime_guess-2.0.4 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.7.4 \
		mio-0.8.11 \
		net-route-0.4.4 \
		netlink-packet-core-0.7.0 \
		netlink-packet-route-0.19.0 \
		netlink-packet-utils-0.5.2 \
		netlink-proto-0.11.3 \
		netlink-sys-0.8.6 \
		nix-0.27.1 \
		nom-7.1.3 \
		ntapi-0.4.1 \
		nu-ansi-term-0.46.0 \
		num-bigint-0.4.5 \
		num-conv-0.1.0 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		num_cpus-1.16.0 \
		object-0.36.0 \
		oid-registry-0.6.1 \
		once_cell-1.19.0 \
		opaque-debug-0.3.1 \
		openssl-probe-0.1.5 \
		option-ext-0.2.0 \
		overload-0.1.1 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		paste-1.0.15 \
		pem-3.0.4 \
		percent-encoding-2.3.1 \
		pin-project-lite-0.2.14 \
		pin-utils-0.1.0 \
		poly1305-0.8.0 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.17 \
		prettyplease-0.2.20 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.86 \
		proxy-stream-0.0.2 \
		quinn-0.10.2 \
		quinn-proto-0.10.6 \
		quinn-udp-0.4.1 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rcgen-0.11.3 \
		redox_syscall-0.5.2 \
		redox_users-0.4.5 \
		regex-1.10.5 \
		regex-automata-0.4.7 \
		regex-lite-0.1.6 \
		regex-syntax-0.8.4 \
		ring-0.16.20 \
		ring-0.17.8 \
		rlimit-0.10.1 \
		rtnetlink-0.14.1 \
		rustc-demangle-0.1.24 \
		rustc-hash-1.1.0 \
		rusticata-macros-4.1.0 \
		rustix-0.38.34 \
		rustls-0.21.12 \
		rustls-native-certs-0.6.3 \
		rustls-pemfile-1.0.4 \
		rustls-pki-types-1.7.0 \
		rustls-webpki-0.101.7 \
		ryu-1.0.18 \
		schannel-0.1.23 \
		scopeguard-1.2.0 \
		sct-0.7.1 \
		security-framework-2.11.0 \
		security-framework-sys-2.11.0 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_json-1.0.117 \
		serde_yaml-0.9.34+deprecated \
		sha1-0.10.6 \
		sha3-0.10.8 \
		sharded-slab-0.1.7 \
		shlex-1.3.0 \
		signal-hook-registry-1.4.2 \
		slab-0.4.9 \
		smallvec-1.13.2 \
		socket2-0.5.7 \
		spin-0.5.2 \
		spin-0.9.8 \
		strsim-0.11.1 \
		subtle-2.6.0 \
		syn-1.0.109 \
		syn-2.0.67 \
		synstructure-0.12.6 \
		sysinfo-0.30.12 \
		thiserror-1.0.61 \
		thiserror-impl-1.0.61 \
		thread_local-1.1.8 \
		time-0.3.36 \
		time-core-0.1.2 \
		time-macros-0.2.18 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.38.0 \
		tokio-macros-2.3.0 \
		tokio-rustls-0.24.1 \
		tokio-tungstenite-0.20.1 \
		tokio-util-0.7.11 \
		tower-service-0.3.2 \
		tracing-0.1.40 \
		tracing-appender-0.2.3 \
		tracing-attributes-0.1.27 \
		tracing-core-0.1.32 \
		tracing-serde-0.1.3 \
		tracing-subscriber-0.3.18 \
		try-lock-0.2.5 \
		tun-0.6.1 \
		tungstenite-0.20.1 \
		typenum-1.17.0 \
		udp-stream-0.0.11 \
		unicase-2.7.0 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-xid-0.2.4 \
		universal-hash-0.5.1 \
		unsafe-libyaml-0.2.11 \
		untrusted-0.7.1 \
		untrusted-0.9.0 \
		url-2.5.2 \
		utf-8-0.7.6 \
		uuid-1.8.0 \
		validator-0.16.1 \
		validator-0.17.0 \
		validator_derive-0.16.0 \
		validator_derive-0.17.0 \
		validator_types-0.16.0 \
		valuable-0.1.0 \
		version_check-0.9.4 \
		want-0.3.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.92 \
		wasm-bindgen-backend-0.2.92 \
		wasm-bindgen-macro-0.2.92 \
		wasm-bindgen-macro-support-0.2.92 \
		wasm-bindgen-shared-0.2.92 \
		web-sys-0.3.69 \
		webpki-roots-0.25.4 \
		which-4.4.2 \
		wildmatch-2.3.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.51.1 \
		windows-0.52.0 \
		windows-core-0.51.1 \
		windows-core-0.52.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.5 \
		wintun-0.3.2 \
		wintun-0.4.0 \
		x509-parser-0.15.1 \
		yasna-0.5.2 \
		zerocopy-0.7.34 \
		zerocopy-derive-0.7.34 \
		zeroize-1.8.1

PROGRAMS=	narrowlink \
		narrowlink-agent \
		narrowlink-gateway \
		narrowlink-token-generator

PLIST_FILES=	${PROGRAMS:S/^/bin\//}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/gateway/src/config.rs
	@${CP} -r \
		${WRKSRC}/cargo-crates/tun-0.6.1/src/platform/linux \
		${WRKSRC}/cargo-crates/tun-0.6.1/src/platform/freebsd

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
.for prog in ${PROGRAMS}
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${prog} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	# install config files
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for what in agent client gateway
	${INSTALL_DATA} ${WRKSRC}/${what}/sample_${what}.yaml ${STAGEDIR}${ETCDIR}/${what}.yaml.sample
.endfor

.include <bsd.port.mk>
