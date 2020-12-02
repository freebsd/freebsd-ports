# $FreeBSD$

PORTNAME=	cast2gif
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-pre1
CATEGORIES=	textproc

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Tool to render Asciinema cast files to GIFs

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	katharostech
GH_TAGNAME=	4f76eeb
CARGO_CRATES=	adler32-1.0.4 \
		aho-corasick-0.7.10 \
		ansi_colours-1.0.1 \
		ansi_term-0.11.0 \
		anyhow-1.0.28 \
		approx-0.3.2 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		backtrace-0.3.46 \
		backtrace-sys-0.1.35 \
		base16-0.2.1 \
		base64-0.11.0 \
		better-panic-0.2.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		byteorder-1.3.4 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		clicolors-control-1.0.1 \
		cmake-0.1.42 \
		color_quant-1.0.1 \
		colored-1.9.3 \
		console-0.9.2 \
		console-0.10.0 \
		constant_time_eq-0.1.5 \
		core-foundation-0.6.4 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.6.2 \
		core-foundation-sys-0.7.0 \
		core-graphics-0.17.3 \
		core-graphics-0.19.0 \
		core-text-13.3.2 \
		core-text-15.0.0 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		data-url-0.1.0 \
		deflate-0.7.20 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		dwrote-0.10.0 \
		either-1.5.3 \
		encode_unicode-0.3.6 \
		enumset-0.4.5 \
		enumset_derive-0.4.4 \
		env_logger-0.7.1 \
		euclid-0.20.10 \
		expat-sys-2.1.6 \
		flame-0.2.2 \
		flate2-1.0.14 \
		float-cmp-0.5.3 \
		float-ord-0.2.0 \
		flume-0.5.1 \
		fnv-1.0.6 \
		font-kit-0.6.0 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		freetype-0.4.1 \
		getrandom-0.1.14 \
		gif-0.10.3 \
		gif-dispose-2.3.0 \
		gifski-0.10.4 \
		glob-0.3.0 \
		harfbuzz-sys-0.3.4 \
		harfbuzz_rs-1.0.1 \
		hermit-abi-0.1.11 \
		humantime-1.3.0 \
		ident_case-1.0.1 \
		imagequant-2.12.5 \
		imagequant-sys-2.12.5 \
		imgref-1.4.3 \
		indicatif-0.14.0 \
		inflate-0.4.5 \
		itoa-0.4.5 \
		jpeg-decoder-0.1.18 \
		kernel32-sys-0.2.2 \
		kurbo-0.5.11 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		lodepng-2.5.0 \
		log-0.4.8 \
		lyon_geom-0.15.2 \
		lzw-0.10.0 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memmap2-0.1.0 \
		memoffset-0.5.4 \
		miniz_oxide-0.3.6 \
		natord-1.0.9 \
		num-traits-0.2.11 \
		num_cpus-1.13.0 \
		number_prefix-0.3.0 \
		numtoa-0.1.0 \
		palette-0.5.0 \
		palette_derive-0.5.0 \
		pathfinder_geometry-0.5.1 \
		pathfinder_simd-0.5.0 \
		pbr-1.0.2 \
		phf-0.8.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_shared-0.8.0 \
		pkg-config-0.3.17 \
		png-0.15.3 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.10 \
		quick-error-1.2.3 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		raqote-0.7.14 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		rctree-0.3.3 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		redox_users-0.3.4 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		resize-0.4.0 \
		resvg-0.9.0 \
		rgb-0.8.16 \
		roxmltree-0.9.1 \
		rust-argon2-0.7.0 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		ryu-1.0.3 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.51 \
		servo-fontconfig-0.4.0 \
		servo-fontconfig-sys-4.0.9 \
		servo-freetype-sys-4.0.5 \
		simplecss-0.2.0 \
		siphasher-0.2.3 \
		siphasher-0.3.2 \
		spin-0.5.2 \
		strsim-0.8.0 \
		strsim-0.9.3 \
		svg-0.7.2 \
		svgfilters-0.1.0 \
		svgtypes-0.5.0 \
		sw-composite-0.7.7 \
		syn-1.0.17 \
		term_size-0.3.1 \
		termcolor-1.1.0 \
		termion-1.5.5 \
		termios-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.15 \
		thiserror-impl-1.0.15 \
		thread-id-3.3.0 \
		thread_local-1.0.1 \
		time-0.1.42 \
		ttf-parser-0.3.0 \
		typed-arena-2.0.1 \
		unicode-bidi-0.3.4 \
		unicode-script-0.5.0 \
		unicode-vo-0.1.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		usvg-0.9.0 \
		utf8parse-0.2.0 \
		vec_map-0.8.1 \
		vt100-0.8.1 \
		vte-0.6.0 \
		vte_generate_state_changes-0.1.1 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wild-2.0.2 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.4 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wio-0.2.2 \
		xmlparser-0.13.1 \
		xmlwriter-0.1.0

PLIST_FILES=	bin/cast2gif
EXAMPLES_PLIST_FILES=	\
	${EXAMPLESDIR}/example1.gif \
	${EXAMPLESDIR}/tutorial.gif

PORTDOCS=	README.md
PORTEXAMPLES=	doc/*.gif

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
