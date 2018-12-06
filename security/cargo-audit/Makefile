# $FreeBSD$

PORTNAME=	cargo-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	3
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

CARGO_CRATES=	backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		bitflags-1.0.4 \
		byteorder-1.2.6 \
		cc-1.0.25 \
		cfg-if-0.1.5 \
		chrono-0.4.6 \
		curl-sys-0.4.12 \
		failure-0.1.2 \
		failure_derive-0.1.2 \
		git2-0.7.5 \
		gumdrop-0.4.0 \
		gumdrop_derive-0.4.1 \
		idna-0.1.5 \
		isatty-0.1.9 \
		lazy_static-1.1.0 \
		libc-0.2.43 \
		libgit2-sys-0.7.10 \
		libssh2-sys-0.2.11 \
		libz-sys-1.0.23 \
		log-0.4.5 \
		matches-0.1.8 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.36 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		platforms-0.1.4 \
		proc-macro2-0.3.8 \
		proc-macro2-0.4.20 \
		quote-0.5.2 \
		quote-0.6.8 \
		redox_syscall-0.1.40 \
		rustc-demangle-0.1.9 \
		rustsec-0.9.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.79 \
		serde_derive-1.0.79 \
		syn-0.13.11 \
		syn-0.14.9 \
		syn-0.15.8 \
		synstructure-0.9.0 \
		term-0.5.1 \
		time-0.1.40 \
		toml-0.4.8 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-xid-0.1.0 \
		url-1.7.1 \
		vcpkg-0.2.6 \
		version_check-0.1.5 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/cargo-audit

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo-audit

.include <bsd.port.mk>
