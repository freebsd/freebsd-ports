# $FreeBSD$

PORTNAME=	cargo-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Audit Cargo.lock for crates with security vulnerabilities

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	RustSec

CARGO_CRATES=	abscissa_core-0.4.0 \
		abscissa_derive-0.4.0 \
		aho-corasick-0.7.6 \
		arc-swap-0.4.3 \
		autocfg-0.1.6 \
		backtrace-0.3.38 \
		backtrace-sys-0.1.31 \
		bitflags-1.2.0 \
		c2-chacha-0.2.2 \
		canonical-path-2.0.2 \
		cargo-lock-3.0.0 \
		cc-1.0.45 \
		cfg-if-0.1.10 \
		chrono-0.4.9 \
		cvss-1.0.0 \
		darling-0.10.1 \
		darling_core-0.10.1 \
		darling_macro-0.10.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fixedbitset-0.1.9 \
		fnv-1.0.6 \
		generational-arena-0.2.3 \
		getrandom-0.1.12 \
		git2-0.10.1 \
		gumdrop-0.7.0 \
		gumdrop_derive-0.7.0 \
		home-0.5.1 \
		ident_case-1.0.1 \
		idna-0.2.0 \
		itoa-0.4.4 \
		jobserver-0.1.17 \
		lazy_static-1.4.0 \
		libc-0.2.62 \
		libgit2-sys-0.9.1 \
		libssh2-sys-0.2.12 \
		libz-sys-1.0.25 \
		log-0.4.8 \
		matches-0.1.8 \
		memchr-2.2.1 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.51 \
		ordermap-0.3.5 \
		percent-encoding-2.1.0 \
		petgraph-0.4.13 \
		pkg-config-0.3.16 \
		platforms-0.2.1 \
		ppv-lite86-0.2.5 \
		proc-macro2-1.0.5 \
		quote-1.0.2 \
		rand-0.7.2 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.16 \
		rustsec-0.16.0 \
		ryu-1.0.1 \
		scopeguard-1.0.0 \
		secrecy-0.4.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_json-1.0.41 \
		signal-hook-0.1.10 \
		signal-hook-registry-1.1.1 \
		smallvec-0.6.10 \
		strsim-0.9.2 \
		syn-1.0.5 \
		synstructure-0.12.1 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		thread_local-0.3.6 \
		time-0.1.42 \
		toml-0.5.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-xid-0.2.0 \
		url-2.1.0 \
		vcpkg-0.2.7 \
		wait-timeout-0.2.0 \
		wasi-0.7.0 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2 \
		zeroize-1.0.0-pre

NO_TEST=	yes

PLIST_FILES=	bin/cargo-audit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo-audit

.include <bsd.port.mk>
