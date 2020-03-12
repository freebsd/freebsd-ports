# $FreeBSD$

PORTNAME=	acmed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	7
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
CARGO_CRATES=		aho-corasick-0.7.6 \
			ansi_term-0.11.0 \
			atty-0.2.13 \
			autocfg-0.1.5 \
			backtrace-0.3.34 \
			backtrace-sys-0.1.31 \
			base64-0.10.1 \
			bitflags-1.1.0 \
			block-buffer-0.7.3 \
			block-padding-0.1.4 \
			boxfnonce-0.1.1 \
			byte-tools-0.3.1 \
			byteorder-1.3.2 \
			c2-chacha-0.2.2 \
			cc-1.0.40 \
			cfg-if-0.1.9 \
			clap-2.33.0 \
			core-foundation-0.6.4 \
			core-foundation-sys-0.6.2 \
			daemonize-0.4.1 \
			digest-0.8.1 \
			env_logger-0.6.2 \
			error-chain-0.11.0 \
			fake-simd-0.1.2 \
			foreign-types-0.3.2 \
			foreign-types-shared-0.1.1 \
			generic-array-0.12.3 \
			getrandom-0.1.10 \
			handlebars-2.0.1 \
			hashbrown-0.5.0 \
			http_req-0.5.3 \
			humantime-1.2.0 \
			itoa-0.4.4 \
			lazy_static-1.3.0 \
			lexical-core-0.4.3 \
			libc-0.2.62 \
			log-0.4.8 \
			maplit-1.0.1 \
			memchr-2.2.1 \
			native-tls-0.2.3 \
			nix-0.14.1 \
			nom-5.0.0 \
			opaque-debug-0.2.3 \
			openssl-0.10.24 \
			openssl-probe-0.1.2 \
			openssl-sys-0.9.49 \
			pest-2.1.1 \
			pest_derive-2.1.0 \
			pest_generator-2.1.0 \
			pest_meta-2.1.1 \
			pkg-config-0.3.15 \
			ppv-lite86-0.2.5 \
			proc-macro2-0.4.30 \
			proc-macro2-1.0.1 \
			quick-error-1.2.2 \
			quote-0.6.13 \
			quote-1.0.2 \
			rand-0.7.0 \
			rand_chacha-0.2.1 \
			rand_core-0.5.0 \
			rand_hc-0.2.0 \
			redox_syscall-0.1.56 \
			regex-1.2.1 \
			regex-syntax-0.6.11 \
			remove_dir_all-0.5.2 \
			rustc-demangle-0.1.16 \
			rustc_version-0.2.3 \
			ryu-1.0.0 \
			same-file-1.0.5 \
			schannel-0.1.15 \
			security-framework-0.3.1 \
			security-framework-sys-0.3.1 \
			semver-0.9.0 \
			semver-parser-0.7.0 \
			serde-1.0.99 \
			serde_derive-1.0.99 \
			serde_json-1.0.40 \
			sha-1-0.8.1 \
			stackvector-1.0.6 \
			static_assertions-0.3.4 \
			strsim-0.8.0 \
			syn-0.15.44 \
			syn-1.0.3 \
			syslog-4.0.1 \
			tempfile-3.1.0 \
			termcolor-1.0.5 \
			textwrap-0.11.0 \
			thread_local-0.3.6 \
			time-0.1.42 \
			toml-0.5.3 \
			typenum-1.10.0 \
			ucd-trie-0.1.2 \
			unicase-2.4.0 \
			unicode-width-0.1.5 \
			unicode-xid-0.1.0 \
			unicode-xid-0.2.0 \
			unreachable-1.0.0 \
			vcpkg-0.2.7 \
			vec_map-0.8.1 \
			version_check-0.1.5 \
			void-1.0.2 \
			walkdir-2.2.9 \
			wasi-0.5.0 \
			winapi-0.3.7 \
			winapi-i686-pc-windows-gnu-0.4.0 \
			winapi-util-0.1.2 \
			winapi-x86_64-pc-windows-gnu-0.4.0 \
			wincolor-1.0.2

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
