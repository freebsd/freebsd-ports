# $FreeBSD$

PORTNAME=	potnet
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Utility to help sysutils/pot to manage the internal network

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cargo

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig

PLIST_FILES=	bin/potnet

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		backtrace-0.3.9 \
		backtrace-sys-0.1.24 \
		bitflags-0.9.1 \
		bitflags-1.0.4 \
		bytecount-0.3.2 \
		cargo_metadata-0.5.8 \
		cc-1.0.25 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		env_logger-0.5.13 \
		error-chain-0.11.0 \
		failure-0.1.3 \
		failure_derive-0.1.3 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.2.11 \
		heck-0.3.0 \
		humantime-1.1.1 \
		itoa-0.4.3 \
		lazy_static-1.1.0 \
		libc-0.2.43 \
		log-0.4.6 \
		memchr-2.1.1 \
		proc-macro2-0.4.20 \
		pulldown-cmark-0.1.2 \
		quick-error-1.2.2 \
		quote-0.6.9 \
		rand-0.4.3 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.5 \
		regex-syntax-0.6.2 \
		remove_dir_all-0.5.1 \
		rustc-demangle-0.1.9 \
		ryu-0.2.6 \
		same-file-1.0.4 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.80 \
		serde_derive-1.0.80 \
		serde_json-1.0.32 \
		skeptic-0.13.3 \
		strsim-0.7.0 \
		structopt-0.2.13 \
		structopt-derive-0.2.13 \
		structopt-flags-0.2.1 \
		syn-0.15.17 \
		synstructure-0.10.1 \
		tempdir-0.3.7 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.2 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.6 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/potnet
.include <bsd.port.mk>

