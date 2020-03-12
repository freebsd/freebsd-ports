# $FreeBSD$

PORTNAME=	potnet
DISTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Utility to help sysutils/pot to manage the internal network

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cargo

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig

PLIST_FILES=	bin/potcpu bin/potnet

CARGO_CRATES=	ansi_term-0.11.0 \
		arrayref-0.3.5 \
		arrayvec-0.4.11 \
		atty-0.2.13 \
		autocfg-0.1.6 \
		backtrace-0.3.38 \
		backtrace-sys-0.1.31 \
		base64-0.10.1 \
		bitflags-1.1.0 \
		blake2b_simd-0.5.8 \
		bytecount-0.4.0 \
		byteorder-1.3.2 \
		cargo_metadata-0.6.4 \
		cc-1.0.45 \
		cfg-if-0.1.9 \
		chrono-0.4.9 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.4 \
		crossbeam-utils-0.6.6 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		either-1.5.3 \
		error-chain-0.12.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		heck-0.3.1 \
		ipnet-2.0.0 \
		itertools-0.8.0 \
		itoa-0.4.4 \
		lazy_static-1.4.0 \
		libc-0.2.62 \
		log-0.4.8 \
		nodrop-0.1.13 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		proc-macro-error-0.2.6 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.4 \
		pulldown-cmark-0.2.0 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.1 \
		remove_dir_all-0.5.2 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		ryu-1.0.0 \
		same-file-1.0.5 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_json-1.0.40 \
		simplelog-0.7.3 \
		skeptic-0.13.4 \
		strsim-0.8.0 \
		structopt-0.3.2 \
		structopt-derive-0.3.2 \
		structopt-flags-0.3.5 \
		syn-0.15.44 \
		syn-1.0.5 \
		synstructure-0.10.2 \
		tempdir-0.3.7 \
		term-0.6.1 \
		textwrap-0.11.0 \
		time-0.1.42 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.9 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/potnet
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/potcpu
.include <bsd.port.mk>
