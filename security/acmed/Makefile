PORTNAME=	acmed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	greg@unrelenting.technology
COMMENT=	ACME (RFC 8555) client daemon written in Rust

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE-2.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	breard-r

CARGO_ENV=	VARLIBDIR="/var/db" SYSCONFDIR="$(PREFIX)/etc" RUNSTATEDIR="/var/run"
CARGO_FEATURES=	openssl_dyn
CARGO_INSTALL_PATH=	./acmed ./tacd
CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		attohttpc-0.17.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bincode-1.3.3 \
		bitflags-1.2.1 \
		boxfnonce-0.1.1 \
		bytes-1.1.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		core-foundation-0.9.2 \
		core-foundation-sys-0.8.3 \
		daemonize-0.4.1 \
		encoding_rs-0.8.29 \
		encoding_rs_io-0.1.7 \
		env_logger-0.8.4 \
		error-chain-0.12.4 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		glob-0.3.0 \
		hermit-abi-0.1.19 \
		http-0.2.5 \
		humantime-2.1.0 \
		idna-0.2.3 \
		itoa-0.4.8 \
		lazy_static-1.4.0 \
		libc-0.2.108 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.3.4 \
		memoffset-0.6.4 \
		native-tls-0.2.8 \
		nix-0.21.2 \
		nom-6.2.1 \
		once_cell-1.8.0 \
		openssl-0.10.38 \
		openssl-probe-0.1.4 \
		openssl-src-300.0.2+3.0.0 \
		openssl-sys-0.9.71 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.22 \
		ppv-lite86-0.2.15 \
		proc-macro2-1.0.32 \
		punycode-0.4.1 \
		quote-1.0.10 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.10 \
		regex-1.4.6 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		security-framework-2.3.1 \
		security-framework-sys-2.4.2 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.71 \
		strsim-0.8.0 \
		syn-1.0.81 \
		syslog-5.0.0 \
		tempfile-3.2.0 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		time-0.1.43 \
		tinytemplate-1.2.1 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wildmatch-1.1.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

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
