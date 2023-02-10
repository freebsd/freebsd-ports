PORTNAME=	jaq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	jq clone focussed on correctness, speed, and simplicity
WWW=		https://github.com/01mf02/jaq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	01mf02

WRKSRC_SUBDIR=	jaq

CARGO_CRATES=	ahash-0.3.8 \
		ansi_term-0.12.1 \
		ariadne-0.1.5 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		cc-1.0.76 \
		cfg-if-1.0.0 \
		chumsky-0.8.0 \
		clap-4.0.22 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		colored_json-2.1.0 \
		const-random-0.1.15 \
		const-random-macro-0.1.15 \
		crunchy-0.2.2 \
		dyn-clone-1.0.9 \
		either-1.8.0 \
		env_logger-0.9.3 \
		fastrand-1.8.0 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.1 \
		instant-0.1.12 \
		itertools-0.10.5 \
		itoa-1.0.4 \
		libc-0.2.137 \
		libmimalloc-sys-0.1.27 \
		log-0.4.17 \
		memmap-0.7.0 \
		mimalloc-0.1.31 \
		once_cell-1.16.0 \
		os_str_bytes-6.3.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		redox_syscall-0.2.16 \
		remove_dir_all-0.5.3 \
		ryu-1.0.11 \
		serde-1.0.147 \
		serde_derive-1.0.147 \
		serde_json-1.0.87 \
		strsim-0.10.0 \
		syn-1.0.103 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		tiny-keccak-2.0.2 \
		unicode-ident-1.0.5 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
