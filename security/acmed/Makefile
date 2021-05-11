PORTNAME=	acmed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
PORTREVISION=	5
CATEGORIES=	security

MAINTAINER=	greg@unrelenting.technology
COMMENT=	ACME (RFC 8555) client daemon written in Rust

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		cargo gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	breard-r

CARGO_INSTALL_PATH=	./acmed ./tacd
CARGO_CRATES=	aho-corasick-0.7.14 \
		ansi_term-0.11.0 \
		arrayvec-0.5.1 \
		attohttpc-0.15.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bincode-1.3.1 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		boxfnonce-0.1.1 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		bytes-0.5.6 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		daemonize-0.4.1 \
		digest-0.8.1 \
		encoding_rs-0.8.24 \
		encoding_rs_io-0.1.7 \
		env_logger-0.7.1 \
		error-chain-0.12.4 \
		fake-simd-0.1.2 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		generic-array-0.12.3 \
		getrandom-0.1.15 \
		glob-0.3.0 \
		handlebars-3.5.0 \
		hermit-abi-0.1.17 \
		http-0.2.1 \
		humantime-1.3.0 \
		idna-0.2.0 \
		itoa-0.4.6 \
		lazy_static-1.4.0 \
		lexical-core-0.7.4 \
		libc-0.2.79 \
		log-0.4.11 \
		maplit-1.0.2 \
		matches-0.1.8 \
		memchr-2.3.3 \
		native-tls-0.2.4 \
		nix-0.18.0 \
		nom-5.1.2 \
		opaque-debug-0.2.3 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-src-111.12.0+1.1.1h \
		openssl-sys-0.9.58 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.9 \
		proc-macro2-1.0.24 \
		punycode-0.4.1 \
		quick-error-1.2.3 \
		quick-error-2.0.0 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.4.1 \
		regex-syntax-0.6.20 \
		remove_dir_all-0.5.3 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		serde-1.0.117 \
		serde_derive-1.0.117 \
		serde_json-1.0.59 \
		sha-1-0.8.2 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		syn-1.0.44 \
		syslog-5.0.0 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tinyvec-0.3.4 \
		toml-0.5.7 \
		typenum-1.12.0 \
		ucd-trie-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		vcpkg-0.2.10 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-patch:
	${REINPLACE_CMD} -e 's|"/etc/acmed/acmed.toml"|"${PREFIX}/etc/acmed/acmed.toml"|' \
		-e 's|"/etc/acmed/accounts"|"${PREFIX}/etc/acmed/accounts"|' \
		-e 's|"/etc/acmed/certs"|"${PREFIX}/etc/acmed/certs"|' \
		${WRKSRC}/acmed/src/main.rs

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/en/acmed.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/en/acmed.toml.5 ${STAGEDIR}${MAN5PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/en/tacd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed
	${INSTALL_DATA} ${WRKSRC}/acmed/config/acmed.toml ${STAGEDIR}${PREFIX}/etc/acmed/acmed.toml.sample
	${INSTALL_DATA} ${WRKSRC}/acmed/config/default_hooks.toml ${STAGEDIR}${PREFIX}/etc/acmed/default_hooks.toml.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed/accounts
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acmed/certs

.include <bsd.port.mk>
