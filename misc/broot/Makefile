PORTNAME=	broot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
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

CARGO_CRATES=	adler-1.0.2 \
		adler32-1.2.0 \
		ahash-0.4.7 \
		ahash-0.7.6 \
		aho-corasick-0.7.18 \
		ansi_colours-1.0.4 \
		ansi_term-0.11.0 \
		anyhow-1.0.45 \
		argh-0.1.6 \
		argh_derive-0.1.6 \
		argh_shared-0.1.6 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bet-1.0.0 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bytemuck-1.7.2 \
		byteorder-1.4.3 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		char_reader-0.1.1 \
		chrono-0.4.19 \
		clap-2.33.3 \
		cli-log-0.1.0 \
		cli-log-2.0.0 \
		clipboard-win-4.2.2 \
		color_quant-1.1.0 \
		coolor-0.3.1 \
		crc32fast-1.2.1 \
		crossbeam-0.8.1 \
		crossbeam-channel-0.5.1 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.5 \
		crossbeam-queue-0.3.2 \
		crossbeam-utils-0.8.5 \
		crossterm-0.19.0 \
		crossterm-0.22.1 \
		crossterm_winapi-0.7.0 \
		crossterm_winapi-0.9.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		csv2svg-0.1.5 \
		custom_error-1.9.2 \
		deflate-0.8.6 \
		deser-hjson-1.0.2 \
		directories-3.0.2 \
		directories-next-2.0.0 \
		dirs-sys-0.3.6 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		error-code-2.3.0 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		file-size-1.0.3 \
		flate2-1.0.22 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		gif-0.11.3 \
		git2-0.13.24 \
		glassbench-0.3.0 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		hashbrown-0.11.2 \
		hashlink-0.6.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		id-arena-2.2.1 \
		idna-0.2.3 \
		image-0.23.14 \
		indexmap-1.7.0 \
		instant-0.1.12 \
		is_executable-1.0.1 \
		itoa-0.4.8 \
		jobserver-0.1.24 \
		jpeg-decoder-0.1.22 \
		lazy-regex-2.2.2 \
		lazy-regex-proc_macros-2.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		lfs-core-0.4.2 \
		libc-0.2.107 \
		libgit2-sys-0.12.25+1.3.0 \
		libsqlite3-sys-0.20.1 \
		libz-sys-1.1.3 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.5 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		memmap-0.7.0 \
		memoffset-0.6.4 \
		minimad-0.7.1 \
		minimad-0.9.0 \
		miniz_oxide-0.3.7 \
		miniz_oxide-0.4.4 \
		mio-0.7.14 \
		miow-0.3.7 \
		nix-0.22.0 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		once_cell-1.8.0 \
		onig-6.3.1 \
		onig_sys-69.7.1 \
		open-1.7.1 \
		open-2.0.1 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		pathdiff-0.2.1 \
		percent-encoding-2.1.0 \
		phf-0.9.0 \
		phf_generator-0.9.1 \
		phf_macros-0.9.0 \
		phf_shared-0.9.0 \
		pkg-config-0.3.22 \
		plist-1.3.1 \
		png-0.16.8 \
		ppv-lite86-0.2.15 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.32 \
		proc-status-0.1.1 \
		quick-xml-0.22.0 \
		quote-1.0.10 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rusqlite-0.24.2 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.1.0 \
		secular-1.0.1 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.71 \
		signal-hook-0.1.17 \
		signal-hook-0.3.10 \
		signal-hook-mio-0.2.1 \
		signal-hook-registry-1.4.0 \
		siphasher-0.3.7 \
		smallvec-1.7.0 \
		splitty-0.1.0 \
		str-buf-1.0.5 \
		strict-0.1.4 \
		strsim-0.8.0 \
		svg-0.8.2 \
		syn-1.0.81 \
		syntect-4.6.0 \
		tempfile-3.2.0 \
		termimad-0.10.3 \
		termimad-0.20.0 \
		terminal-clipboard-0.3.1 \
		termux-clipboard-0.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tiff-0.6.1 \
		time-0.1.43 \
		time-0.3.5 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		umask-1.0.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		users-0.11.0 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		weezl-0.1.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		x11-clipboard-0.5.3 \
		xcb-0.10.1 \
		xml-rs-0.8.4 \
		xterm-query-0.1.0 \
		yaml-rust-0.4.5
CARGO_FEATURES=	--no-default-features

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG.md README.md documentation.md features.md

OPTIONS_DEFINE=		CLIPBOARD DOCS
OPTIONS_DEFAULT=	CLIPBOARD

CLIPBOARD_DESC=	Enable terminal X11 clipboard support

CLIPBOARD_USES=		python:3.6+,build xorg
CLIPBOARD_USE=		XORG=xcb
CLIPBOARD_BINARY_ALIAS=	python3=${PYTHON_CMD}
CLIPBOARD_VARS=		CARGO_FEATURES+=clipboard

_BUILD_VERSION=	${DISTVERSION}
_BUILD_DATE=	$$(date +'%Y/%m/%d')

pre-build:
	@${MV} ${WRKSRC}/man/page \
		${WRKSRC}/man/${PORTNAME}.1
	@${REINPLACE_CMD} -e 's|#version|${_BUILD_VERSION}|g' \
		-e "s|#date|${_BUILD_DATE}|g" \
		${WRKSRC}/man/${PORTNAME}.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
