PORTNAME=	xcp
DISTVERSIONPREFIX=	xcp-
DISTVERSION=	0.3.1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended 'cp' command
WWW=		https://github.com/tarka/xcp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tarka

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.13 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		byteorder-1.3.1 \
		cc-1.0.29 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		clap-2.32.0 \
		clicolors-control-1.0.0 \
		cloudabi-0.0.3 \
		console-0.7.5 \
		crossbeam-channel-0.3.8 \
		crossbeam-utils-0.6.5 \
		encode_unicode-0.3.5 \
		escargot-0.4.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		globset-0.4.2 \
		heck-0.3.1 \
		ignore-0.4.6 \
		indicatif-0.11.0 \
		itoa-0.4.3 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		lock_api-0.1.5 \
		log-0.4.6 \
		memchr-2.2.0 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		number_prefix-0.2.8 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		proc-macro2-0.4.27 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.2 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		regex-1.1.0 \
		regex-syntax-0.6.5 \
		remove_dir_all-0.5.1 \
		rustc-demangle-0.1.13 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.87 \
		serde_derive-1.0.87 \
		serde_json-1.0.38 \
		simplelog-0.5.3 \
		smallvec-0.6.8 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		structopt-0.2.14 \
		structopt-derive-0.2.14 \
		syn-0.15.26 \
		synstructure-0.10.1 \
		tempfile-3.0.6 \
		term-0.5.1 \
		termion-1.5.1 \
		termios-0.3.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.2 \
		uuid-0.7.2 \
		vec_map-0.8.1 \
		void-1.0.2 \
		walkdir-2.2.7 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
