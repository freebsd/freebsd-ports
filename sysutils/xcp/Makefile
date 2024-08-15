PORTNAME=	xcp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended 'cp' command
WWW=		https://github.com/tarka/xcp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	tarka

CARGO_CRATES=	aho-corasick-1.1.3 \
		anstream-0.6.14 \
		anstyle-1.0.7 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.1.0 \
		anstyle-wincon-3.0.3 \
		anyhow-1.0.86 \
		autocfg-1.3.0 \
		bitflags-2.6.0 \
		blocking-threadpool-1.0.1 \
		bstr-1.9.1 \
		cfg-if-1.0.0 \
		clap-4.5.7 \
		clap_builder-4.5.7 \
		clap_derive-4.5.5 \
		clap_lex-0.7.1 \
		colorchoice-1.0.1 \
		console-0.15.8 \
		crossbeam-channel-0.5.13 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		deranged-0.3.11 \
		encode_unicode-0.3.6 \
		errno-0.3.9 \
		exacl-0.12.0 \
		fastrand-2.1.0 \
		fslock-0.2.1 \
		getrandom-0.2.15 \
		glob-0.3.1 \
		globset-0.4.14 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		ignore-0.4.22 \
		indicatif-0.17.8 \
		instant-0.1.13 \
		is_terminal_polyfill-1.70.0 \
		itoa-1.0.11 \
		lazy_static-0.2.11 \
		lazy_static-1.5.0 \
		libc-0.2.155 \
		libm-0.2.8 \
		linux-raw-sys-0.4.14 \
		linux-raw-sys-0.6.4 \
		log-0.4.21 \
		memchr-2.7.4 \
		num-conv-0.1.0 \
		num-traits-0.2.19 \
		num_cpus-1.16.0 \
		num_threads-0.1.7 \
		number_prefix-0.4.0 \
		portable-atomic-1.6.0 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_distr-0.4.3 \
		rand_xorshift-0.3.0 \
		regex-1.10.5 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		rustix-0.38.34 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		simplelog-0.12.2 \
		strsim-0.11.1 \
		syn-2.0.68 \
		tempfile-3.10.1 \
		termcolor-1.4.1 \
		test-case-3.3.1 \
		test-case-core-3.3.1 \
		test-case-macros-3.3.1 \
		thiserror-1.0.61 \
		thiserror-impl-1.0.61 \
		time-0.3.36 \
		time-core-0.1.2 \
		time-macros-0.2.18 \
		unbytify-0.2.0 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.13 \
		utf8parse-0.2.2 \
		uuid-1.9.1 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5 \
		xattr-1.3.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
