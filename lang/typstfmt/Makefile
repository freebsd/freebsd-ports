PORTNAME=	typstfmt
DISTVERSION=	0.2.7
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Basic formatter for the Typst language
WWW=		https://github.com/astrale-sharp/typstfmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	astrale-sharp

CARGO_CRATES=	aho-corasick-1.1.2 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		bstr-0.2.17 \
		bstr-1.8.0 \
		cfg-if-1.0.0 \
		comemo-0.3.1 \
		comemo-macros-0.3.1 \
		confy-0.5.1 \
		console-0.15.7 \
		directories-4.0.1 \
		dirs-sys-0.3.7 \
		ecow-0.1.2 \
		either-1.9.0 \
		encode_unicode-0.3.6 \
		equivalent-1.0.1 \
		getrandom-0.2.11 \
		globmatch-0.2.5 \
		globset-0.4.14 \
		hashbrown-0.14.3 \
		indexmap-2.1.0 \
		insta-1.34.0 \
		itertools-0.10.5 \
		lazy_static-1.4.0 \
		lexopt-0.3.0 \
		libc-0.2.150 \
		libredox-0.0.1 \
		linked-hash-map-0.5.6 \
		log-0.4.20 \
		memchr-2.6.4 \
		nu-ansi-term-0.46.0 \
		once_cell-1.18.0 \
		overload-0.1.1 \
		pin-project-lite-0.2.13 \
		proc-macro2-1.0.70 \
		quote-1.0.33 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.10.2 \
		regex-automata-0.1.10 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		same-file-1.0.6 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_spanned-0.6.4 \
		sharded-slab-0.1.7 \
		similar-2.3.0 \
		similar-asserts-1.5.0 \
		siphasher-1.0.0 \
		smallvec-1.11.2 \
		syn-2.0.39 \
		thiserror-1.0.50 \
		thiserror-impl-1.0.50 \
		thread_local-1.1.7 \
		toml-0.5.11 \
		toml-0.7.8 \
		toml_datetime-0.6.5 \
		toml_edit-0.19.15 \
		tracing-0.1.40 \
		tracing-attributes-0.1.27 \
		tracing-core-0.1.32 \
		tracing-log-0.2.0 \
		tracing-subscriber-0.3.18 \
		unicode-ident-1.0.12 \
		unicode-math-class-0.1.0 \
		unicode-segmentation-1.10.1 \
		unscanny-0.1.0 \
		valuable-0.1.0 \
		walkdir-2.4.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.2 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_msvc-0.42.2 \
		windows_i686_gnu-0.42.2 \
		windows_i686_msvc-0.42.2 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_msvc-0.42.2 \
		winnow-0.5.25 \
		yaml-rust-0.4.5 \
		typst-syntax@git+https://github.com/typst/typst.git?tag=v0.7.0\#da8367e189b02918a8fe1a98fd3059fd11a82cd9

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
