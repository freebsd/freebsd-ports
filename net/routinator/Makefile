# $FreeBSD$

PORTNAME=	routinator
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
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

CARGO_CRATES=	ansi_term-0.11.0 \
		arc-swap-0.4.6 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		backtrace-0.3.46 \
		backtrace-sys-0.1.36 \
		base64-0.11.0 \
		base64-0.12.0 \
		bcder-0.5.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		boxfnonce-0.1.1 \
		bumpalo-3.2.1 \
		byteorder-1.3.4 \
		bytes-0.4.12 \
		bytes-0.5.4 \
		cc-1.0.52 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		clap-2.33.0 \
		constant_time_eq-0.1.5 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		ct-logs-0.6.0 \
		daemonize-0.4.1 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		dtoa-0.4.5 \
		either-1.5.3 \
		encoding_rs-0.8.22 \
		error-chain-0.12.2 \
		fern-0.6.0 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.3.4 \
		futures-channel-0.3.4 \
		futures-core-0.3.4 \
		futures-executor-0.3.4 \
		futures-io-0.3.4 \
		futures-macro-0.3.4 \
		futures-sink-0.3.4 \
		futures-task-0.3.4 \
		futures-util-0.3.4 \
		getrandom-0.1.14 \
		h2-0.2.4 \
		hermit-abi-0.1.12 \
		http-0.2.1 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		hyper-0.13.5 \
		hyper-rustls-0.20.0 \
		hyper-tls-0.4.1 \
		idna-0.2.0 \
		indexmap-1.3.2 \
		iovec-0.1.4 \
		itoa-0.4.5 \
		js-sys-0.3.37 \
		json-0.12.4 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		listenfd-0.3.3 \
		log-0.4.8 \
		log-reroute-0.1.5 \
		matches-0.1.8 \
		memchr-2.3.3 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		mio-0.6.21 \
		mio-uds-0.6.7 \
		miow-0.2.1 \
		native-tls-0.2.4 \
		net2-0.2.33 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		num_cpus-1.13.0 \
		once_cell-1.3.1 \
		openssl-0.10.29 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.55 \
		percent-encoding-2.1.0 \
		pin-project-0.4.9 \
		pin-project-internal-0.4.9 \
		pin-project-lite-0.1.4 \
		pin-utils-0.1.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		proc-macro-hack-0.5.15 \
		proc-macro-nested-0.1.4 \
		proc-macro2-1.0.10 \
		quick-xml-0.18.1 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		remove_dir_all-0.5.2 \
		reqwest-0.10.4 \
		ring-0.16.12 \
		rpki-0.9.1 \
		rpki-rtr-0.1.1 \
		rust-argon2-0.7.0 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		rustls-0.17.0 \
		rustls-native-certs-0.3.0 \
		ryu-1.0.4 \
		schannel-0.1.18 \
		sct-0.6.0 \
		security-framework-0.4.3 \
		security-framework-sys-0.4.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.52 \
		serde_urlencoded-0.6.1 \
		signal-hook-registry-1.2.0 \
		slab-0.4.2 \
		smallvec-1.4.0 \
		spin-0.5.2 \
		strsim-0.8.0 \
		syn-1.0.18 \
		syslog-5.0.0 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.16 \
		thiserror-impl-1.0.16 \
		time-0.1.43 \
		tokio-0.2.13 \
		tokio-macros-0.2.5 \
		tokio-rustls-0.13.0 \
		tokio-socks-0.2.2 \
		tokio-tls-0.3.0 \
		tokio-util-0.3.1 \
		toml-0.5.6 \
		tower-service-0.3.0 \
		try-lock-0.2.2 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.12 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		untrusted-0.7.1 \
		unwrap-1.2.1 \
		url-2.1.1 \
		uuid-0.6.5 \
		uuid-0.8.1 \
		vcpkg-0.2.8 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.60 \
		wasm-bindgen-backend-0.2.60 \
		wasm-bindgen-futures-0.4.10 \
		wasm-bindgen-macro-0.2.60 \
		wasm-bindgen-macro-support-0.2.60 \
		wasm-bindgen-shared-0.2.60 \
		web-sys-0.3.37 \
		webpki-0.21.2 \
		webpki-roots-0.18.0 \
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
