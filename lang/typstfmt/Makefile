PORTNAME=	typstfmt
DISTVERSION=	0.2.10
PORTREVISION=	10
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Basic formatter for the Typst language
WWW=		https://github.com/astrale-sharp/typstfmt

LICENSE=	APACHE20 MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_COMB=	dual

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	astrale-sharp

CARGO_CRATES=	aho-corasick-1.1.2 \
		bitflags-1.3.2 \
		bitflags-2.4.2 \
		bstr-0.2.17 \
		bstr-1.9.1 \
		cfg-if-1.0.0 \
		comemo-0.3.1 \
		comemo-macros-0.3.1 \
		confy-0.5.1 \
		console-0.15.8 \
		directories-4.0.1 \
		dirs-sys-0.3.7 \
		ecow-0.2.0 \
		either-1.10.0 \
		encode_unicode-0.3.6 \
		equivalent-1.0.1 \
		getrandom-0.2.12 \
		globmatch-0.2.5 \
		globset-0.4.14 \
		hashbrown-0.14.3 \
		indexmap-2.2.3 \
		insta-1.35.1 \
		itertools-0.10.5 \
		lazy_static-1.4.0 \
		lexopt-0.3.0 \
		libc-0.2.153 \
		libredox-0.0.1 \
		linked-hash-map-0.5.6 \
		log-0.4.20 \
		memchr-2.7.1 \
		nu-ansi-term-0.46.0 \
		once_cell-1.19.0 \
		overload-0.1.1 \
		pin-project-lite-0.2.13 \
		proc-macro2-1.0.78 \
		quote-1.0.35 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.10.3 \
		regex-automata-0.1.10 \
		regex-automata-0.4.5 \
		regex-syntax-0.8.2 \
		same-file-1.0.6 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_spanned-0.6.5 \
		sharded-slab-0.1.7 \
		similar-2.4.0 \
		similar-asserts-1.5.0 \
		siphasher-1.0.0 \
		smallvec-1.13.1 \
		syn-2.0.52 \
		thiserror-1.0.57 \
		thiserror-impl-1.0.57 \
		thread_local-1.1.8 \
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
		unicode-script-0.5.6 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.11 \
		unscanny-0.1.0 \
		valuable-0.1.0 \
		walkdir-2.4.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.52.4 \
		winnow-0.5.40 \
		yaml-rust-0.4.5 \
		typst-syntax@git+https://github.com/typst/typst.git?tag=v0.10.0\#70ca0d257bb4ba927f63260e20443f244e0bb58c

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
