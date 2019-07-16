# $FreeBSD$

PORTNAME=	cargo-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
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

CARGO_CRATES=	assert_cmd-0.11.1 \
		autocfg-0.1.4 \
		backtrace-0.3.32 \
		backtrace-sys-0.1.30 \
		bitflags-1.1.0 \
		c2-chacha-0.2.2 \
		cc-1.0.37 \
		cfg-if-0.1.9 \
		chrono-0.4.7 \
		curl-sys-0.4.20 \
		difference-2.0.0 \
		directories-1.0.2 \
		escargot-0.4.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		getrandom-0.1.6 \
		git2-0.8.0 \
		gumdrop-0.6.0 \
		gumdrop_derive-0.6.0 \
		idna-0.1.5 \
		itoa-0.4.4 \
		lazy_static-1.3.0 \
		libc-0.2.60 \
		libgit2-sys-0.7.11 \
		libssh2-sys-0.2.11 \
		libz-sys-1.0.25 \
		log-0.4.7 \
		matches-0.1.8 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.47 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		platforms-0.2.0 \
		ppv-lite86-0.2.5 \
		predicates-1.0.1 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rand-0.7.0 \
		rand_chacha-0.2.0 \
		rand_core-0.5.0 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.15 \
		rustsec-0.12.0 \
		ryu-1.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.94 \
		serde_derive-1.0.94 \
		serde_json-1.0.40 \
		serial_test-0.2.0 \
		serial_test_derive-0.2.0 \
		smallvec-0.6.10 \
		spin-0.5.0 \
		syn-0.15.39 \
		synstructure-0.10.2 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		time-0.1.42 \
		toml-0.5.1 \
		treeline-0.1.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-xid-0.1.0 \
		url-1.7.2 \
		vcpkg-0.2.7 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

PLIST_FILES=	bin/cargo-audit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo-audit

.include <bsd.port.mk>
