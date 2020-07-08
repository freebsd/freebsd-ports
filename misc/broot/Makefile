# $FreeBSD$

PORTNAME=	broot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.5
CATEGORIES=	misc

MAINTAINER=	vulcan@wired.sh
COMMENT=	Quick and easy new way to see and navigate directory trees

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS=	git:devel/git

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	canop

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		arc-swap-0.4.7 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bet-0.3.4 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		bstr-0.2.13 \
		bumpalo-3.4.0 \
		byteorder-1.3.4 \
		cast-0.2.3 \
		cc-1.0.54 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		clap-2.33.1 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.5 \
		criterion-0.3.2 \
		criterion-plot-0.4.2 \
		crossbeam-0.7.3 \
		crossbeam-channel-0.4.2 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.7.2 \
		crossterm-0.17.5 \
		crossterm_winapi-0.6.1 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		custom_error-1.7.1 \
		directories-2.0.2 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		either-1.5.3 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		getrandom-0.1.14 \
		git2-0.11.0 \
		glob-0.3.0 \
		hermit-abi-0.1.14 \
		id-arena-2.2.1 \
		idna-0.2.0 \
		iovec-0.1.4 \
		is_executable-0.1.2 \
		itertools-0.9.0 \
		itoa-0.4.6 \
		jobserver-0.1.21 \
		js-sys-0.3.40 \
		kernel32-sys-0.2.2 \
		lazy-regex-0.1.3 \
		lazy_static-1.4.0 \
		libc-0.2.71 \
		libgit2-sys-0.10.0 \
		libz-sys-1.0.25 \
		lock_api-0.3.4 \
		log-0.4.8 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memmap-0.7.0 \
		memoffset-0.5.4 \
		minimad-0.6.4 \
		mio-0.6.22 \
		miow-0.2.1 \
		net2-0.2.34 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
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
		pkg-config-0.3.17 \
		plotters-0.2.15 \
		ppv-lite86-0.2.8 \
		proc-macro-hack-0.5.16 \
		proc-macro2-1.0.18 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		rayon-1.3.1 \
		rayon-core-1.7.1 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		regex-1.3.9 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.18 \
		rust-argon2-0.7.0 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		secular-0.2.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.112 \
		serde_derive-1.0.112 \
		serde_json-1.0.55 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.0 \
		simplelog-0.7.6 \
		siphasher-0.3.3 \
		slab-0.4.2 \
		smallvec-1.4.0 \
		strict-0.1.3 \
		strsim-0.8.0 \
		syn-1.0.31 \
		term-0.6.1 \
		termimad-0.8.24 \
		textwrap-0.11.0 \
		thiserror-1.0.20 \
		thiserror-impl-1.0.20 \
		thread_local-1.0.1 \
		time-0.1.43 \
		tinytemplate-1.1.0 \
		tinyvec-0.3.3 \
		toml-0.5.6 \
		umask-1.0.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		url-2.1.1 \
		users-0.9.1 \
		vcpkg-0.2.10 \
		vec_map-0.8.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.63 \
		wasm-bindgen-backend-0.2.63 \
		wasm-bindgen-macro-0.2.63 \
		wasm-bindgen-macro-support-0.2.63 \
		wasm-bindgen-shared-0.2.63 \
		web-sys-0.3.40 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

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
