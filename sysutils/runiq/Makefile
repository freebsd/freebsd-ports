PORTNAME=	runiq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient way to filter duplicate lines from input, a la uniq
WWW=		https://github.com/whitfin/runiq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	whitfin

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bytelines-2.4.0 \
		bytes-1.3.0 \
		cfg-if-1.0.0 \
		clap-3.2.23 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		fnv-1.0.7 \
		futures-0.3.25 \
		futures-channel-0.3.25 \
		futures-core-0.3.25 \
		futures-executor-0.3.25 \
		futures-io-0.3.25 \
		futures-macro-0.3.25 \
		futures-sink-0.3.25 \
		futures-task-0.3.25 \
		futures-util-0.3.25 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.2 \
		libc-0.2.139 \
		memchr-2.5.0 \
		once_cell-1.17.0 \
		os_str_bytes-6.4.1 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.17 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		scalable_bloom_filter-0.1.1 \
		siphasher-0.2.3 \
		slab-0.4.7 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.107 \
		termcolor-1.1.3 \
		textwrap-0.16.0 \
		tokio-1.23.0 \
		twox-hash-1.6.3 \
		unicode-ident-1.0.6 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
