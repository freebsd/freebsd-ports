PORTNAME=	sad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.22
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI search and replace (Space Age seD)
WWW=		https://github.com/ms-jpq/sad

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ms-jpq

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		async-channel-1.6.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bytes-1.1.0 \
		cache-padded-1.2.0 \
		cfg-if-1.0.0 \
		clap-3.2.5 \
		clap_derive-3.2.5 \
		clap_lex-0.2.2 \
		concurrent-queue-1.2.2 \
		difflib-0.4.0 \
		either-1.6.1 \
		event-listener-2.5.2 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		getrandom-0.2.7 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.8.2 \
		lazy_static-1.4.0 \
		libc-0.2.126 \
		lock_api-0.4.7 \
		log-0.4.17 \
		memchr-2.5.0 \
		mio-0.8.3 \
		num_cpus-1.13.1 \
		once_cell-1.12.0 \
		os_str_bytes-6.1.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.39 \
		quote-1.0.18 \
		redox_syscall-0.2.13 \
		regex-1.5.6 \
		regex-syntax-0.6.26 \
		scopeguard-1.1.0 \
		shlex-1.1.0 \
		signal-hook-registry-1.4.0 \
		slab-0.4.6 \
		smallvec-1.8.0 \
		socket2-0.4.4 \
		strsim-0.10.0 \
		syn-1.0.96 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		textwrap-0.15.0 \
		tokio-1.19.2 \
		tokio-macros-1.8.0 \
		unicode-ident-1.0.1 \
		uuid-1.1.2 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-4.2.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
