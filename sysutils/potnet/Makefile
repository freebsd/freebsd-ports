# $FreeBSD$

PORTNAME=	potnet
DISTVERSION=	0.2.0
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Utility to help sysutils/pot to manage the internal network

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cargo

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig

PLIST_FILES=	bin/potnet

CARGO_CRATES=	ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		backtrace-0.3.32 \
		backtrace-sys-0.1.30 \
		bitflags-1.1.0 \
		blake2-rfc-0.2.18 \
		bytecount-0.4.0 \
		byteorder-1.3.2 \
		cargo_metadata-0.6.4 \
		cc-1.0.37 \
		cfg-if-0.1.9 \
		chrono-0.4.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		dirs-1.0.5 \
		error-chain-0.12.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		heck-0.3.1 \
		ipnet-2.0.0 \
		itoa-0.4.4 \
		libc-0.2.59 \
		log-0.4.6 \
		nodrop-0.1.13 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		numtoa-0.1.0 \
		proc-macro2-0.4.30 \
		pulldown-cmark-0.2.0 \
		quote-0.6.12 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.15 \
		ryu-1.0.0 \
		same-file-1.0.4 \
		scoped_threadpool-0.1.9 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.94 \
		serde_derive-1.0.94 \
		serde_json-1.0.40 \
		simplelog-0.5.3 \
		skeptic-0.13.4 \
		strsim-0.8.0 \
		structopt-0.2.18 \
		structopt-derive-0.2.18 \
		structopt-flags-0.3.2 \
		syn-0.15.39 \
		synstructure-0.10.2 \
		tempdir-0.3.7 \
		term-0.5.2 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		time-0.1.42 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.8 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/potnet
.include <bsd.port.mk>
