# $FreeBSD$

PORTNAME=	broot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	misc

MAINTAINER=	vulcan@wired.sh
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
		aho-corasick-0.7.13 \
		ansi_colours-1.0.1 \
		ansi_term-0.11.0 \
		arc-swap-0.4.7 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bet-0.3.4 \
		bincode-1.3.1 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		bstr-0.2.13 \
		bumpalo-3.4.0 \
		bytemuck-1.4.0 \
		byteorder-1.3.4 \
		cast-0.2.3 \
		cc-1.0.59 \
		cfg-if-0.1.10 \
		chrono-0.4.15 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		color_quant-1.0.1 \
		constant_time_eq-0.1.5 \
		crc32fast-1.2.0 \
		criterion-0.3.3 \
		criterion-plot-0.4.3 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.3 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		crossterm-0.17.7 \
		crossterm_winapi-0.6.1 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		custom_error-1.7.1 \
		deflate-0.8.6 \
		directories-2.0.2 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		either-1.6.0 \
		file-size-1.0.2 \
		flate2-1.0.17 \
		fnv-1.0.7 \
		getrandom-0.1.14 \
		gif-0.10.3 \
		git2-0.11.0 \
		glob-0.3.0 \
		half-1.6.0 \
		hashbrown-0.8.2 \
		hermit-abi-0.1.15 \
		id-arena-2.2.1 \
		idna-0.2.0 \
		image-0.23.9 \
		indexmap-1.5.1 \
		is_executable-0.1.2 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		jobserver-0.1.21 \
		jpeg-decoder-0.1.20 \
		js-sys-0.3.44 \
		lazy-regex-0.1.4 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.76 \
		libgit2-sys-0.10.0 \
		libz-sys-1.1.1 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.3 \
		lock_api-0.3.4 \
		log-0.4.11 \
		lzw-0.10.0 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memmap-0.7.0 \
		memoffset-0.5.5 \
		minimad-0.6.5 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.1 \
		mio-0.7.0 \
		miow-0.3.5 \
		ntapi-0.3.4 \
		num-integer-0.1.43 \
		num-iter-0.1.41 \
		num-rational-0.3.0 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		onig-6.0.0 \
		onig_sys-69.5.0 \
		oorandom-11.1.2 \
		open-1.4.0 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		pathdiff-0.1.0 \
		percent-encoding-2.1.0 \
		phf-0.8.0 \
		phf_generator-0.8.0 \
		phf_macros-0.8.0 \
		phf_shared-0.8.0 \
		pkg-config-0.3.18 \
		plist-1.0.0 \
		plotters-0.2.15 \
		png-0.16.7 \
		ppv-lite86-0.2.9 \
		proc-macro-hack-0.5.18 \
		proc-macro2-1.0.19 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		rayon-1.4.0 \
		rayon-core-1.8.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.3.9 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.18 \
		rust-argon2-0.8.2 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		secular-0.2.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.115 \
		serde_cbor-0.11.1 \
		serde_derive-1.0.115 \
		serde_json-1.0.57 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.1 \
		simplelog-0.7.6 \
		siphasher-0.3.3 \
		smallvec-1.4.2 \
		socket2-0.3.12 \
		strict-0.1.4 \
		strsim-0.8.0 \
		syn-1.0.39 \
		syntect-4.4.0 \
		term-0.6.1 \
		termimad-0.8.26 \
		textwrap-0.11.0 \
		thiserror-1.0.20 \
		thiserror-impl-1.0.20 \
		thread_local-1.0.1 \
		tiff-0.5.0 \
		time-0.1.44 \
		tinytemplate-1.1.0 \
		tinyvec-0.3.4 \
		toml-0.5.6 \
		umask-1.0.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		users-0.9.1 \
		vcpkg-0.2.10 \
		vec_map-0.8.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.67 \
		wasm-bindgen-backend-0.2.67 \
		wasm-bindgen-macro-0.2.67 \
		wasm-bindgen-macro-support-0.2.67 \
		wasm-bindgen-shared-0.2.67 \
		web-sys-0.3.44 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.8.3 \
		yaml-rust-0.4.4
CARGO_FEATURES=	--no-default-features

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG.md README.md client-server.md

OPTIONS_DEFINE=	CLIENT_SERVER DOCS

CLIENT_SERVER_DESC=	Enable client/server support
CLIENT_SERVER_VARS=	CARGO_FEATURES+=client-server

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
