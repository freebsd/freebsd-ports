PORTNAME=	routinator
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${ROUTINATOR_UI_URL}/v${ROUTINATOR_UI_VERSION}/:0
DISTFILES+=	routinator-ui-build.tar.gz:0

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	RPKI signed route collector and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	ring crate not ported to other architectures

RUN_DEPENDS=	rsync:net/rsync

USES=		cargo cpe
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs
CPE_VENDOR=	nlnetlabs

USE_RC_SUBR=	routinator

SUB_FILES=	pkg-message
SUB_LIST+=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

ROUTINATOR_UI_VERSION=	0.3.4
ROUTINATOR_UI_URL=	https://github.com/NLnetLabs/routinator-ui/releases/download/

OPTIONS_SUB=	yes

CARGO_CRATES=	addr2line-0.15.2 \
		adler-1.0.2 \
		ansi_term-0.11.0 \
		arc-swap-1.3.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.60 \
		base64-0.13.0 \
		bcder-0.6.0 \
		bitflags-1.2.1 \
		bumpalo-3.7.0 \
		bytes-1.0.1 \
		cc-1.0.69 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		crc32fast-1.2.1 \
		crossbeam-queue-0.3.2 \
		crossbeam-utils-0.8.5 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		either-1.6.1 \
		encoding_rs-0.8.28 \
		error-chain-0.12.4 \
		fern-0.6.0 \
		filetime-0.2.14 \
		flate2-1.0.20 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		futures-0.3.15 \
		futures-channel-0.3.15 \
		futures-core-0.3.15 \
		futures-executor-0.3.15 \
		futures-io-0.3.15 \
		futures-macro-0.3.15 \
		futures-sink-0.3.15 \
		futures-task-0.3.15 \
		futures-util-0.3.15 \
		getrandom-0.2.3 \
		gimli-0.24.0 \
		h2-0.3.3 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		http-0.2.4 \
		http-body-0.4.2 \
		httparse-1.4.1 \
		httpdate-1.0.1 \
		hyper-0.14.11 \
		hyper-rustls-0.22.1 \
		hyper-tls-0.5.0 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		ipnet-2.3.1 \
		itoa-0.4.7 \
		js-sys-0.3.51 \
		lazy_static-1.4.0 \
		libc-0.2.98 \
		log-0.4.14 \
		log-reroute-0.1.7 \
		matches-0.1.8 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		mime-0.3.16 \
		miniz_oxide-0.4.4 \
		mio-0.7.13 \
		miow-0.3.7 \
		native-tls-0.2.7 \
		nix-0.22.0 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		object-0.25.3 \
		once_cell-1.8.0 \
		openssl-0.10.35 \
		openssl-probe-0.1.4 \
		openssl-sys-0.9.65 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.7 \
		proc-macro2-1.0.28 \
		quick-xml-0.22.0 \
		quote-1.0.9 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.9 \
		redox_users-0.4.0 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.4 \
		ring-0.16.20 \
		routinator-ui-0.3.4 \
		rpki-0.12.2 \
		rustc-demangle-0.1.20 \
		rustc_version-0.4.0 \
		rustls-0.19.1 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		sct-0.6.1 \
		security-framework-2.3.1 \
		security-framework-sys-2.3.0 \
		semver-1.0.3 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		serde_urlencoded-0.7.0 \
		signal-hook-registry-1.4.0 \
		slab-0.4.3 \
		smallvec-1.6.1 \
		socket2-0.4.0 \
		spin-0.5.2 \
		strsim-0.8.0 \
		syn-1.0.74 \
		syslog-5.0.0 \
		tar-0.4.35 \
		tempfile-3.2.0 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.26 \
		thiserror-impl-1.0.26 \
		time-0.1.43 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.9.0 \
		tokio-macros-1.3.0 \
		tokio-native-tls-0.3.0 \
		tokio-rustls-0.22.0 \
		tokio-socks-0.5.1 \
		tokio-stream-0.1.7 \
		tokio-util-0.6.7 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.26 \
		tracing-core-0.1.18 \
		try-lock-0.2.3 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		url-2.2.2 \
		uuid-0.8.2 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		want-0.3.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.74 \
		wasm-bindgen-backend-0.2.74 \
		wasm-bindgen-futures-0.4.24 \
		wasm-bindgen-macro-0.2.74 \
		wasm-bindgen-macro-support-0.2.74 \
		wasm-bindgen-shared-0.2.74 \
		web-sys-0.3.51 \
		webpki-0.21.4 \
		webpki-roots-0.21.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		xattr-0.2.2

post-patch:
	${REINPLACE_CMD} \
		-e "s|DISTDIR|${DISTDIR}|" \
			${WRKSRC}/cargo-crates/routinator-ui-${ROUTINATOR_UI_VERSION}/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/routinator
	${INSTALL_MAN} ${WRKSRC}/doc/routinator.1 ${STAGEDIR}${PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}/${PREFIX}/etc/routinator
	${INSTALL_DATA} ${WRKSRC}/etc/routinator.conf.example \
		${STAGEDIR}${PREFIX}/etc/routinator/routinator.conf.example

.include <bsd.port.mk>
