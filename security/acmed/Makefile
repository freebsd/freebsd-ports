# $FreeBSD$

PORTNAME=	acmed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	1
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
CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		arrayvec-0.4.12 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		backtrace-0.3.41 \
		backtrace-sys-0.1.34 \
		base64-0.11.0 \
		base64-0.12.0 \
		bitflags-1.2.1 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		boxfnonce-0.1.1 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		cc-1.0.50 \
		cfg-if-0.1.9 \
		clap-2.33.0 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		daemonize-0.4.1 \
		der-parser-3.0.4 \
		digest-0.8.1 \
		env_logger-0.7.1 \
		error-chain-0.11.0 \
		fake-simd-0.1.2 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		generic-array-0.12.3 \
		getrandom-0.1.14 \
		handlebars-3.0.1 \
		hermit-abi-0.1.8 \
		http_req-0.5.5 \
		humantime-1.3.0 \
		itoa-0.4.5 \
		lazy_static-1.4.0 \
		lexical-core-0.6.7 \
		libc-0.2.67 \
		log-0.4.8 \
		maplit-1.0.2 \
		memchr-2.3.3 \
		native-tls-0.2.4 \
		nix-0.17.0 \
		nodrop-0.1.14 \
		nom-5.1.1 \
		num-bigint-0.2.6 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		opaque-debug-0.2.3 \
		openssl-0.10.28 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.54 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.9 \
		punycode-0.4.1 \
		quick-error-1.2.3 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.5 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		rusticata-macros-2.0.4 \
		ryu-1.0.3 \
		schannel-0.1.17 \
		security-framework-0.4.1 \
		security-framework-sys-0.4.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.48 \
		sha-1-0.8.2 \
		static_assertions-0.3.4 \
		strsim-0.8.0 \
		syn-1.0.16 \
		syslog-4.0.1 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.42 \
		toml-0.5.6 \
		typenum-1.11.2 \
		ucd-trie-0.1.3 \
		unicase-2.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vcpkg-0.2.8 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		void-1.0.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x509-parser-0.6.5

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
