PORTNAME=	sad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.33
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI search and replace (Space Age seD)
WWW=		https://github.com/ms-jpq/sad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo python:build
USE_GITHUB=	yes
GH_ACCOUNT=	ms-jpq

CARGO_CRATES=	aho-corasick-1.1.5 \
		ansi_term-0.12.1 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		bitflags-2.13.2 \
		bumpalo-3.20.3 \
		bytes-1.12.1 \
		cfg-if-1.0.5 \
		clap-4.6.7 \
		clap_builder-4.6.7 \
		clap_derive-4.6.7 \
		clap_lex-1.1.1 \
		colorchoice-1.0.5 \
		difflib-0.4.0 \
		errno-0.3.14 \
		futures-0.3.34 \
		futures-channel-0.3.34 \
		futures-core-0.3.34 \
		futures-executor-0.3.34 \
		futures-io-0.3.34 \
		futures-macro-0.3.34 \
		futures-sink-0.3.34 \
		futures-task-0.3.34 \
		futures-util-0.3.34 \
		getrandom-0.4.3 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.2 \
		js-sys-0.3.107 \
		libc-0.2.191 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.3 \
		mio-1.2.4 \
		once_cell_polyfill-1.70.2 \
		pin-project-lite-0.2.17 \
		proc-macro2-1.0.107 \
		quote-1.0.47 \
		r-efi-6.0.0 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rustix-1.1.6 \
		rustversion-1.0.23 \
		shlex-2.0.1 \
		signal-hook-registry-1.4.8 \
		slab-0.4.12 \
		socket2-0.6.5 \
		strsim-0.11.1 \
		syn-3.0.9 \
		terminal_size-0.4.4 \
		tokio-1.54.1 \
		unicode-ident-1.0.27 \
		utf8parse-0.2.2 \
		uuid-1.29.0 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.130 \
		wasm-bindgen-macro-0.2.130 \
		wasm-bindgen-macro-support-0.2.130 \
		wasm-bindgen-shared-0.2.130 \
		which-8.0.6 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		windows-sys-0.61.2

PLIST_FILES=	bin/${PORTNAME}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
