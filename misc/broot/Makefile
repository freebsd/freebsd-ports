# $FreeBSD$

PORTNAME=	broot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.8
CATEGORIES=	misc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Quick and easy new way to see and navigate directory trees

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma
RUN_DEPENDS=	git:devel/git

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	canop

CARGO_CRATES=	adler-0.2.3 \
		adler32-1.2.0 \
		ahash-0.7.0 \
		aho-corasick-0.7.15 \
		ansi_colours-1.0.2 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bet-0.4.0 \
		bincode-1.3.1 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		bstr-0.2.15 \
		bumpalo-3.6.0 \
		bytemuck-1.5.0 \
		byteorder-1.4.2 \
		cast-0.2.3 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		char_reader-0.1.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		cli-log-1.1.0 \
		clipboard-win-4.0.3 \
		color_quant-1.1.0 \
		const_fn-0.4.5 \
		constant_time_eq-0.1.5 \
		crc32fast-1.2.1 \
		criterion-0.3.4 \
		criterion-plot-0.4.3 \
		crossbeam-0.8.0 \
		crossbeam-channel-0.5.0 \
		crossbeam-deque-0.8.0 \
		crossbeam-epoch-0.9.1 \
		crossbeam-queue-0.3.1 \
		crossbeam-utils-0.8.1 \
		crossterm-0.19.0 \
		crossterm_winapi-0.7.0 \
		csv-1.1.5 \
		csv-core-0.1.10 \
		custom_error-1.8.0 \
		deflate-0.8.6 \
		deser-hjson-0.1.12 \
		directories-2.0.2 \
		dirs-sys-0.3.5 \
		either-1.6.1 \
		error-code-2.0.2 \
		file-size-1.0.3 \
		flate2-1.0.20 \
		fnv-1.0.7 \
		form_urlencoded-1.0.0 \
		getrandom-0.1.16 \
		getrandom-0.2.2 \
		gif-0.11.1 \
		git2-0.13.17 \
		glob-0.3.0 \
		half-1.7.1 \
		hashbrown-0.9.1 \
		hermit-abi-0.1.18 \
		id-arena-2.2.1 \
		idna-0.2.1 \
		image-0.23.13 \
		indexmap-1.6.1 \
		instant-0.1.9 \
		is_executable-0.1.2 \
		itertools-0.9.0 \
		itertools-0.10.0 \
		itoa-0.4.7 \
		jobserver-0.1.21 \
		jpeg-decoder-0.1.22 \
		js-sys-0.3.47 \
		lazy-regex-0.1.4 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		lfs-core-0.3.1 \
		libc-0.2.86 \
		libgit2-sys-0.12.18+1.1.0 \
		libz-sys-1.1.2 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.2 \
		log-0.4.14 \
		matches-0.1.8 \
		memchr-2.3.4 \
		memmap-0.7.0 \
		memoffset-0.6.1 \
		minimad-0.7.0 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.3 \
		mio-0.7.7 \
		miow-0.3.6 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		once_cell-1.5.2 \
		onig-6.1.1 \
		onig_sys-69.6.0 \
		oorandom-11.1.3 \
		open-1.4.0 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.3 \
		pathdiff-0.1.0 \
		percent-encoding-2.1.0 \
		phf-0.8.0 \
		phf_generator-0.8.0 \
		phf_macros-0.8.0 \
		phf_shared-0.8.0 \
		pkg-config-0.3.19 \
		plist-1.1.0 \
		plotters-0.3.0 \
		plotters-backend-0.3.0 \
		plotters-svg-0.3.0 \
		png-0.16.8 \
		ppv-lite86-0.2.10 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.24 \
		quote-1.0.9 \
		rand-0.7.3 \
		rand-0.8.3 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.0 \
		rand_core-0.5.1 \
		rand_core-0.6.2 \
		rand_hc-0.2.0 \
		rand_hc-0.3.0 \
		rand_pcg-0.2.1 \
		rayon-1.5.0 \
		rayon-core-1.9.0 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.5 \
		redox_users-0.3.5 \
		regex-1.4.3 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.22 \
		remove_dir_all-0.5.3 \
		rust-argon2-0.8.3 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		secular-0.2.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.123 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.123 \
		serde_json-1.0.62 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.3.0 \
		siphasher-0.3.3 \
		smallvec-1.6.1 \
		socket2-0.3.19 \
		splitty-0.1.0 \
		str-buf-1.0.5 \
		strict-0.1.4 \
		strsim-0.8.0 \
		syn-1.0.60 \
		syntect-4.5.0 \
		tempfile-3.2.0 \
		termimad-0.10.0 \
		terminal-clipboard-0.2.1 \
		termux-clipboard-0.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.23 \
		thiserror-impl-1.0.23 \
		thread_local-1.1.3 \
		tiff-0.6.1 \
		time-0.1.43 \
		tinytemplate-1.2.0 \
		tinyvec-1.1.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		umask-1.0.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.17 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.2.0 \
		users-0.10.0 \
		vcpkg-0.2.11 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.70 \
		wasm-bindgen-backend-0.2.70 \
		wasm-bindgen-macro-0.2.70 \
		wasm-bindgen-macro-support-0.2.70 \
		wasm-bindgen-shared-0.2.70 \
		web-sys-0.3.47 \
		weezl-0.1.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-clipboard-0.5.1 \
		xcb-0.9.0 \
		xml-rs-0.8.3 \
		yaml-rust-0.4.5
CARGO_FEATURES=	--no-default-features

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG.md README.md client-server.md documentation.md \
		features.md

OPTIONS_DEFINE=		CLIENT_SERVER CLIPBOARD DOCS
OPTIONS_DEFAULT=	CLIENT_SERVER CLIPBOARD

CLIENT_SERVER_DESC=	Enable client/server support
CLIPBOARD_DESC=		Enable terminal X11 clipboard support

CLIENT_SERVER_VARS=	CARGO_FEATURES+=client-server

CLIPBOARD_USES=		python:3.6+,build xorg
CLIPBOARD_USE=		XORG=xcb
CLIPBOARD_BINARY_ALIAS=	python3=${PYTHON_CMD}
CLIPBOARD_VARS=		CARGO_FEATURES+=clipboard

_BUILD_VERSION=	${DISTVERSION}
_BUILD_DATE=	$$(date +'%Y/%m/%d')

pre-build:
	@${MV} ${WRKSRC}/man/page ${WRKSRC}/man/${PORTNAME}.1
	@${REINPLACE_CMD} -e 's|#version|${_BUILD_VERSION}|g' \
		-e "s|#date|${_BUILD_DATE}|g" ${WRKSRC}/man/${PORTNAME}.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
