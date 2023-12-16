PORTNAME=	sad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.23
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI search and replace (Space Age seD)
WWW=		https://github.com/ms-jpq/sad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo python:build
USE_GITHUB=	yes
GH_ACCOUNT=	ms-jpq

CARGO_CRATES=	aho-corasick-1.0.2 \
		ansi_term-0.12.1 \
		anstream-0.3.2 \
		anstyle-1.0.0 \
		anstyle-parse-0.2.0 \
		anstyle-query-1.0.0 \
		anstyle-wincon-1.0.1 \
		async-channel-1.8.0 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bytes-1.4.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		clap-4.3.2 \
		clap_builder-4.3.1 \
		clap_derive-4.3.2 \
		clap_lex-0.5.0 \
		colorchoice-1.0.0 \
		concurrent-queue-2.2.0 \
		crossbeam-utils-0.8.15 \
		difflib-0.4.0 \
		either-1.8.1 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		event-listener-2.5.3 \
		futures-0.3.28 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-executor-0.3.28 \
		futures-io-0.3.28 \
		futures-macro-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-util-0.3.28 \
		getrandom-0.2.10 \
		heck-0.4.1 \
		hermit-abi-0.2.6 \
		hermit-abi-0.3.1 \
		io-lifetimes-1.0.11 \
		is-terminal-0.4.7 \
		libc-0.2.146 \
		linux-raw-sys-0.3.8 \
		lock_api-0.4.10 \
		memchr-2.5.0 \
		mio-0.8.8 \
		num_cpus-1.15.0 \
		once_cell-1.18.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.60 \
		quote-1.0.28 \
		redox_syscall-0.3.5 \
		regex-1.8.4 \
		regex-syntax-0.7.2 \
		rustix-0.37.19 \
		scopeguard-1.1.0 \
		shlex-1.1.0 \
		signal-hook-registry-1.4.1 \
		slab-0.4.8 \
		smallvec-1.10.0 \
		socket2-0.4.9 \
		strsim-0.10.0 \
		syn-2.0.18 \
		terminal_size-0.2.6 \
		tokio-1.28.2 \
		tokio-macros-2.1.0 \
		unicode-ident-1.0.9 \
		utf8parse-0.2.1 \
		uuid-1.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.48.0

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
