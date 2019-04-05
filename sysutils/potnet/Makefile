# $FreeBSD$

PORTNAME=	potnet
DISTVERSION=	0.1.3
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

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		bytecount-0.4.0 \
		cargo_metadata-0.6.4 \
		cc-1.0.34 \
		cfg-if-0.1.7 \
		clap-2.32.0 \
		env_logger-0.5.13 \
		error-chain-0.12.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		heck-0.3.1 \
		humantime-1.2.0 \
		itoa-0.4.3 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		log-0.4.6 \
		memchr-2.2.0 \
		proc-macro2-0.4.27 \
		pulldown-cmark-0.2.0 \
		quick-error-1.2.2 \
		quote-0.6.11 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.52 \
		redox_termios-0.1.1 \
		regex-1.1.5 \
		regex-syntax-0.6.6 \
		remove_dir_all-0.5.1 \
		rustc-demangle-0.1.13 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		serde_json-1.0.39 \
		skeptic-0.13.4 \
		strsim-0.7.0 \
		structopt-0.2.15 \
		structopt-derive-0.2.15 \
		structopt-flags-0.2.1 \
		syn-0.15.30 \
		synstructure-0.10.1 \
		tempdir-0.3.7 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		walkdir-2.2.7 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/potnet
.include <bsd.port.mk>
