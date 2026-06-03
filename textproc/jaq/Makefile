PORTNAME=	jaq
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	jq clone focused on correctness, speed, and simplicity
WWW=		https://github.com/01mf02/jaq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	compilation fails: undefined symbol: __atomic_load_8

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	01mf02

CARGO_BUILD_ARGS=	--package=jaq
CARGO_INSTALL_PATH=	jaq
CARGO_CRATES=	aho-corasick-1.1.4 \
		arbitrary-1.4.2 \
		arraydeque-0.5.1 \
		autocfg-1.5.0 \
		base64-0.22.1 \
		bitflags-2.11.0 \
		bstr-1.10.0 \
		bumpalo-3.14.0 \
		bytes-1.11.1 \
		cc-1.2.56 \
		cfg-if-1.0.4 \
		ciborium-io-0.2.2 \
		ciborium-ll-0.2.2 \
		clipboard-win-5.4.1 \
		codesnake-0.3.0 \
		console_log-1.0.0 \
		crunchy-0.2.4 \
		dirs-6.0.0 \
		dirs-sys-0.5.0 \
		dyn-clone-1.0.20 \
		env_logger-0.10.2 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		error-code-3.3.2 \
		fastrand-2.3.0 \
		fd-lock-4.0.4 \
		find-msvc-tools-0.1.9 \
		foldhash-0.1.5 \
		getrandom-0.2.16 \
		getrandom-0.3.3 \
		half-2.4.1 \
		hashbrown-0.15.5 \
		hashlink-0.10.0 \
		hifijson-0.5.0 \
		indexmap-2.10.0 \
		itoa-1.0.17 \
		jiff-0.2.23 \
		jiff-static-0.2.23 \
		jiff-tzdb-0.1.6 \
		jiff-tzdb-platform-0.1.3 \
		js-sys-0.3.82 \
		libc-0.2.183 \
		libm-0.2.16 \
		libmimalloc-sys-0.1.44 \
		libredox-0.1.14 \
		linux-raw-sys-0.12.1 \
		log-0.4.29 \
		memchr-2.8.0 \
		memmap2-0.9.10 \
		mimalloc-0.1.48 \
		nix-0.27.1 \
		num-bigint-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		option-ext-0.2.0 \
		portable-atomic-1.13.1 \
		portable-atomic-util-0.2.5 \
		proc-macro2-1.0.106 \
		quote-1.0.41 \
		r-efi-5.3.0 \
		redox_users-0.5.2 \
		regex-automata-0.4.14 \
		regex-bites-0.1.6 \
		rustix-1.1.4 \
		rustversion-1.0.22 \
		rustyline-13.0.0 \
		ryu-1.0.20 \
		saphyr-parser-0.0.6 \
		self_cell-1.2.2 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		shlex-1.3.0 \
		smallvec-1.15.1 \
		syn-2.0.108 \
		tempfile-3.20.0 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		toml-span-0.7.1 \
		typed-arena-2.0.2 \
		unicode-ident-1.0.18 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.1.14 \
		urlencoding-2.1.3 \
		utf8parse-0.2.2 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasi-0.14.2+wasi-0.2.4 \
		wasm-bindgen-0.2.105 \
		wasm-bindgen-macro-0.2.105 \
		wasm-bindgen-macro-support-0.2.105 \
		wasm-bindgen-shared-0.2.105 \
		web-sys-0.3.82 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
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
		wit-bindgen-rt-0.39.0 \
		xmlparser-0.13.6 \
		zmij-1.0.21

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

.include <bsd.port.mk>
