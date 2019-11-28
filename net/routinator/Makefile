# $FreeBSD$

PORTNAME=	routinator
PORTVERSION=	0.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI signed route collector and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	ring crate not ported to other architectures

RUN_DEPENDS=	rsync:net/rsync

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

USE_RC_SUBR=	routinator

SUB_FILES=	pkg-message
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

SUB_LIST+=	USERS=${USERS} \
		GROUPS=${GROUPS}

OPTIONS_SUB=	yes

CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		arc-swap-0.4.4 \
		arrayref-0.3.5 \
		arrayvec-0.5.1 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		base64-0.10.1 \
		bcder-0.4.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.9 \
		boxfnonce-0.1.1 \
		byteorder-1.3.2 \
		bytes-0.4.12 \
		c2-chacha-0.2.3 \
		cc-1.0.47 \
		cfg-if-0.1.10 \
		chrono-0.4.9 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.4 \
		cookie-0.12.0 \
		cookie_store-0.7.0 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.2 \
		crossbeam-epoch-0.8.0 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.0 \
		ct-logs-0.5.1 \
		daemonize-0.4.1 \
		derive_more-0.15.0 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		dtoa-0.4.4 \
		either-1.5.3 \
		encoding_rs-0.8.20 \
		error-chain-0.11.0 \
		error-chain-0.12.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fern-0.5.9 \
		flate2-1.0.13 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.29 \
		futures-cpupool-0.1.8 \
		getrandom-0.1.13 \
		h2-0.1.26 \
		hermit-abi-0.1.3 \
		http-0.1.19 \
		http-body-0.1.0 \
		httparse-1.3.4 \
		hyper-0.12.35 \
		hyper-rustls-0.16.1 \
		idna-0.1.5 \
		idna-0.2.0 \
		indexmap-1.3.0 \
		iovec-0.1.4 \
		itoa-0.4.4 \
		json-0.11.15 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.65 \
		listenfd-0.3.3 \
		lock_api-0.3.1 \
		log-0.4.8 \
		log-reroute-0.1.4 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.2.1 \
		memoffset-0.5.3 \
		mime-0.3.14 \
		mime_guess-2.0.1 \
		miniz_oxide-0.3.5 \
		mio-0.6.19 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		net2-0.2.33 \
		num-integer-0.1.41 \
		num-traits-0.2.9 \
		num_cpus-1.11.1 \
		once_cell-1.2.0 \
		parking_lot-0.9.0 \
		parking_lot_core-0.6.2 \
		percent-encoding-1.0.1 \
		percent-encoding-2.1.0 \
		ppv-lite86-0.2.6 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.6 \
		publicsuffix-1.5.4 \
		quick-xml-0.16.1 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.6.5 \
		rand-0.7.2 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.1 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		reqwest-0.9.19 \
		ring-0.14.6 \
		rpki-0.8.1 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		rustls-0.15.2 \
		ryu-1.0.2 \
		scopeguard-1.0.0 \
		sct-0.5.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.102 \
		serde_derive-1.0.102 \
		serde_json-1.0.41 \
		serde_urlencoded-0.5.5 \
		slab-0.4.2 \
		smallvec-0.6.13 \
		socks-0.3.2 \
		spin-0.5.2 \
		string-0.2.1 \
		strsim-0.8.0 \
		syn-0.15.44 \
		syn-1.0.8 \
		synstructure-0.12.3 \
		syslog-4.0.1 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		tokio-0.1.22 \
		tokio-buf-0.1.1 \
		tokio-codec-0.1.1 \
		tokio-current-thread-0.1.6 \
		tokio-executor-0.1.8 \
		tokio-fs-0.1.6 \
		tokio-io-0.1.12 \
		tokio-reactor-0.1.10 \
		tokio-rustls-0.9.4 \
		tokio-sync-0.1.7 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.16 \
		tokio-timer-0.2.11 \
		tokio-udp-0.1.5 \
		tokio-uds-0.2.5 \
		toml-0.5.5 \
		try-lock-0.2.2 \
		try_from-0.3.2 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.9 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		untrusted-0.6.2 \
		unwrap-1.2.1 \
		url-1.7.2 \
		url-2.1.0 \
		uuid-0.6.5 \
		uuid-0.7.4 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		version_check-0.9.1 \
		want-0.2.0 \
		wasi-0.7.0 \
		webpki-0.19.1 \
		webpki-roots-0.16.0 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		ws2_32-sys-0.2.1

PLIST_FILES=	bin/routinator \
		${ETCDIR_REL}/routinator.conf.example \
		${ETCDIR_REL}/routinator.conf.system-service \
		man/man1/routinator.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/routinator
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 ${STAGEDIR}${PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/routinator
	${INSTALL_DATA} ${WRKSRC}/etc/routinator.conf.system-service \
		${STAGEDIR}${PREFIX}/etc/routinator/routinator.conf.system-service
	${INSTALL_DATA} ${WRKSRC}/etc/routinator.conf.example \
		${STAGEDIR}${PREFIX}/etc/routinator/routinator.conf.example

.include <bsd.port.mk>
