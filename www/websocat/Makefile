# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	websocat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	WebSockets tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	vi

CARGO_FEATURES=		--no-default-features
CARGO_CARGOLOCK=	${WRKSRC}/Cargo.lock.freebsd

OPTIONS_DEFINE=		CRYPTO_PEER PROMETHEUS_PEER SEQPACKET SSL \
			TOKIO_PROCESS UNIX_STDIO
OPTIONS_DEFAULT=	SEQPACKET SSL TOKIO_PROCESS UNIX_STDIO

CRYPTO_PEER=		CARGO_FEATURES+=crypto_peer
PROMETHEUS_PEER=	CARGO_FEATURES+=prometheus_peer
SEQPACKET_VARS=		CARGO_FEATURES+=seqpacket
SSL_VARS=		CARGO_FEATURES+=ssl
TOKIO_PROCESS_VARS=	CARGO_FEATURES+=tokio-process
UNIX_STDIO_VARS=	CARGO_FEATURES+=unix_stdio

CRYPTO_PEER_DESC=	Crypto peer
PROMETHEUS_PEER_DESC=	Prometheus peer
SEQPACKET_DESC=		Seqpacket
SSL_DESC=		SSL
TOKIO_PROCESS_DESC=	Tokio process
UNIX_STDIO_DESC=	UNIX stdio

CARGO_CRATES=	aead-0.4.3 \
		anymap-0.12.1 \
		argon2-0.4.0 \
		atty-0.2.14 \
		autocfg-0.1.8 \
		autocfg-1.1.0 \
		base64-0.9.3 \
		base64-0.10.1 \
		base64ct-1.5.0 \
		bitflags-1.3.2 \
		blake2-0.10.4 \
		block-buffer-0.7.3 \
		block-buffer-0.10.2 \
		block-padding-0.1.5 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		bytes-0.4.12 \
		cc-1.0.73 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chacha20-0.8.1 \
		chacha20poly1305-0.9.0 \
		cipher-0.3.0 \
		clap-2.34.0 \
		cloudabi-0.0.3 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.3 \
		cpufeatures-0.2.2 \
		crossbeam-deque-0.7.4 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.1.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.2 \
		crypto-common-0.1.3 \
		derivative-1.0.4 \
		digest-0.8.1 \
		digest-0.10.3 \
		env_logger-0.6.2 \
		fake-simd-0.1.2 \
		fastrand-1.7.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.31 \
		generic-array-0.12.4 \
		generic-array-0.14.5 \
		getrandom-0.2.6 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		http-0.1.21 \
		http-bytes-0.1.0 \
		httparse-1.7.1 \
		hyper-0.10.16 \
		idna-0.1.5 \
		instant-0.1.12 \
		iovec-0.1.4 \
		itoa-0.4.8 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		lock_api-0.3.4 \
		lock_api-0.4.7 \
		log-0.3.9 \
		log-0.4.17 \
		matches-0.1.9 \
		maybe-uninit-2.0.0 \
		memchr-2.5.0 \
		memoffset-0.5.6 \
		mime-0.2.6 \
		mio-0.6.23 \
		mio-named-pipes-0.1.7 \
		mio-uds-0.6.8 \
		miow-0.2.2 \
		miow-0.3.7 \
		native-tls-0.2.10 \
		net2-0.2.37 \
		num_cpus-1.13.1 \
		once_cell-1.10.0 \
		opaque-debug-0.2.3 \
		opaque-debug-0.3.0 \
		openssl-0.10.40 \
		openssl-macros-0.1.0 \
		openssl-probe-0.1.5 \
		openssl-src-111.18.0+1.1.1n \
		openssl-sys-0.9.73 \
		parking_lot-0.9.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.6.2 \
		parking_lot_core-0.8.5 \
		password-hash-0.4.1 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.25 \
		poly1305-0.7.2 \
		ppv-lite86-0.2.16 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.39 \
		prometheus-0.13.0 \
		prometheus-metric-storage-0.5.0 \
		prometheus-metric-storage-derive-0.5.0 \
		quote-0.6.13 \
		quote-1.0.18 \
		rand-0.6.5 \
		rand-0.8.5 \
		rand_chacha-0.1.1 \
		rand_chacha-0.3.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.6.3 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		readwrite-0.1.2 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.13 \
		remove_dir_all-0.5.3 \
		rustc_version-0.2.3 \
		safemem-0.3.3 \
		schannel-0.1.19 \
		scopeguard-1.1.0 \
		security-framework-2.6.1 \
		security-framework-sys-2.6.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		sha-1-0.8.2 \
		signal-hook-registry-1.4.0 \
		slab-0.4.6 \
		slab_typesafe-0.1.3 \
		smallvec-0.6.14 \
		smallvec-1.8.0 \
		smart-default-0.3.0 \
		structopt-0.2.16 \
		structopt-derive-0.2.16 \
		subtle-2.4.1 \
		syn-0.15.44 \
		syn-1.0.95 \
		tempfile-3.3.0 \
		textwrap-0.11.0 \
		thiserror-1.0.31 \
		thiserror-impl-1.0.31 \
		time-0.1.43 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		tk-listen-0.2.1 \
		tokio-0.1.22 \
		tokio-codec-0.1.2 \
		tokio-current-thread-0.1.7 \
		tokio-executor-0.1.10 \
		tokio-file-unix-0.5.1 \
		tokio-fs-0.1.7 \
		tokio-io-0.1.13 \
		tokio-named-pipes-0.1.0 \
		tokio-process-0.2.5 \
		tokio-reactor-0.1.12 \
		tokio-signal-0.2.9 \
		tokio-stdin-stdout-0.1.5 \
		tokio-sync-0.1.8 \
		tokio-tcp-0.1.4 \
		tokio-threadpool-0.1.18 \
		tokio-timer-0.2.13 \
		tokio-tls-0.2.1 \
		tokio-udp-0.1.6 \
		tokio-uds-0.2.7 \
		traitobject-0.1.0 \
		typeable-0.1.2 \
		typenum-1.15.0 \
		unicase-1.4.2 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.0 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.1.0 \
		universal-hash-0.4.1 \
		url-1.7.2 \
		vcpkg-0.2.15 \
		version_check-0.1.5 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		websocket-0.26.4 \
		websocket-base-0.26.2 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1 \
		zeroize-1.4.3

PLIST_FILES=	bin/websocat

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/websocat

.include <bsd.port.mk>
