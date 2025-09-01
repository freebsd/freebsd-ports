PORTNAME=	sad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.32
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI search and replace (Space Age seD)
WWW=		https://github.com/ms-jpq/sad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo python:build
USE_GITHUB=	yes
GH_ACCOUNT=	ms-jpq

CARGO_CRATES=	addr2line-0.22.0 \
		adler-1.0.2 \
		aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		anstream-0.6.14 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.4 \
		anstyle-query-1.1.0 \
		anstyle-wincon-3.0.3 \
		autocfg-1.3.0 \
		backtrace-0.3.73 \
		bitflags-2.6.0 \
		bytes-1.6.1 \
		cc-1.1.2 \
		cfg-if-1.0.0 \
		clap-4.5.27 \
		clap_builder-4.5.27 \
		clap_derive-4.5.24 \
		clap_lex-0.7.4 \
		colorchoice-1.0.1 \
		difflib-0.4.0 \
		either-1.13.0 \
		env_home-0.1.0 \
		errno-0.3.9 \
		futures-0.3.31 \
		futures-channel-0.3.31 \
		futures-core-0.3.31 \
		futures-executor-0.3.31 \
		futures-io-0.3.31 \
		futures-macro-0.3.31 \
		futures-sink-0.3.31 \
		futures-task-0.3.31 \
		futures-util-0.3.31 \
		getrandom-0.2.15 \
		gimli-0.29.0 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		is_terminal_polyfill-1.70.0 \
		libc-0.2.169 \
		linux-raw-sys-0.4.14 \
		memchr-2.7.4 \
		miniz_oxide-0.7.4 \
		mio-1.0.2 \
		object-0.36.1 \
		pin-project-lite-0.2.14 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustc-demangle-0.1.24 \
		rustix-0.38.34 \
		shlex-1.3.0 \
		signal-hook-registry-1.4.2 \
		slab-0.4.9 \
		socket2-0.5.7 \
		strsim-0.11.1 \
		syn-2.0.71 \
		terminal_size-0.4.1 \
		tokio-1.43.0 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.2 \
		uuid-1.12.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-7.0.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winsafe-0.0.19

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
