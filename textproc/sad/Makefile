PORTNAME=	sad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.25
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI search and replace (Space Age seD)
WWW=		https://github.com/ms-jpq/sad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo python:build
USE_GITHUB=	yes
GH_ACCOUNT=	ms-jpq

CARGO_CRATES=	addr2line-0.21.0 \
		adler-1.0.2 \
		aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		anstream-0.6.13 \
		anstyle-1.0.6 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		autocfg-1.1.0 \
		backtrace-0.3.69 \
		bitflags-2.5.0 \
		bytes-1.5.0 \
		cc-1.0.90 \
		cfg-if-1.0.0 \
		clap-4.5.3 \
		clap_builder-4.5.2 \
		clap_derive-4.5.3 \
		clap_lex-0.7.0 \
		colorchoice-1.0.0 \
		difflib-0.4.0 \
		either-1.10.0 \
		errno-0.3.8 \
		futures-0.3.30 \
		futures-channel-0.3.30 \
		futures-core-0.3.30 \
		futures-executor-0.3.30 \
		futures-io-0.3.30 \
		futures-macro-0.3.30 \
		futures-sink-0.3.30 \
		futures-task-0.3.30 \
		futures-util-0.3.30 \
		getrandom-0.2.12 \
		gimli-0.28.1 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		home-0.5.9 \
		libc-0.2.153 \
		linux-raw-sys-0.4.13 \
		memchr-2.7.1 \
		miniz_oxide-0.7.2 \
		mio-0.8.11 \
		num_cpus-1.16.0 \
		object-0.32.2 \
		once_cell-1.19.0 \
		pin-project-lite-0.2.13 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		regex-1.10.3 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.2 \
		rustc-demangle-0.1.23 \
		rustix-0.38.32 \
		shlex-1.3.0 \
		signal-hook-registry-1.4.1 \
		slab-0.4.9 \
		socket2-0.5.6 \
		strsim-0.11.0 \
		syn-2.0.53 \
		terminal_size-0.3.0 \
		tokio-1.36.0 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		uuid-1.8.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-6.0.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.4

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
