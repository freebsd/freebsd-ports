# $FreeBSD$

PORTNAME=	cargo-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Audit Cargo.lock for crates with security vulnerabilities

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	RustSec

CARGO_CRATES=	atty-0.2.11 \
		autocfg-0.1.1 \
		backtrace-0.3.13 \
		backtrace-sys-0.1.26 \
		bitflags-1.0.4 \
		byteorder-1.2.7 \
		cc-1.0.26 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		curl-sys-0.4.15 \
		directories-1.0.2 \
		failure-0.1.3 \
		failure_derive-0.1.3 \
		git2-0.8.0 \
		gumdrop-0.5.0 \
		gumdrop_derive-0.5.0 \
		idna-0.1.5 \
		itoa-0.4.3 \
		lazy_static-1.2.0 \
		libc-0.2.45 \
		libgit2-sys-0.7.11 \
		libssh2-sys-0.2.11 \
		libz-sys-1.0.25 \
		log-0.4.6 \
		matches-0.1.8 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.39 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		platforms-0.1.4 \
		proc-macro2-0.4.24 \
		quote-0.6.10 \
		redox_syscall-0.1.44 \
		redox_termios-0.1.1 \
		rustc-demangle-0.1.11 \
		rustsec-0.10.0 \
		ryu-0.2.7 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.82 \
		serde_derive-1.0.82 \
		serde_json-1.0.33 \
		syn-0.14.9 \
		syn-0.15.23 \
		synstructure-0.10.1 \
		term-0.5.1 \
		termion-1.5.1 \
		time-0.1.41 \
		toml-0.4.10 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-xid-0.1.0 \
		url-1.7.2 \
		vcpkg-0.2.6 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/cargo-audit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo-audit

.include <bsd.port.mk>
