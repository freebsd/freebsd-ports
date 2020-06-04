# $FreeBSD$

PORTNAME=	ion
DISTVERSION=	1.0.5-1355
PORTREVISION=	10
CATEGORIES=	shells
PKGNAMESUFFIX=	-shell

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modern system shell written in Rust

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	nodefault
GH_TUPLE=	alkis:decimal:972c8547a0a76c7ad9a314e28a335aa57d46a543:decimal
USE_GITLAB=	yes
GL_SITE=	https://gitlab.redox-os.org
GL_ACCOUNT=	redox-os
GL_COMMIT=	a8872014dbce730ccd00aaa722397dc394a52bf4
GL_TUPLE=	redox-os:calc:afba9c5d184ddb9db5e4e71dc357da0499e212cf:calculate \
		redox-os:liner:3f3d1d4e6058067e9d03a9b1510d8f2edac073c7:liner \
		redox-os:small:022635fcb0b0b631b3a06c79c45fa8ebaf4f64f5:small \
		redox-os:termion:c27678efc2ed14576361c7ce6d806a6bb576f1a9:termion

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.7.4 \
		andrew-0.2.1 \
		android_glue-0.2.3 \
		ansi_term-0.11.0 \
		approx-0.3.2 \
		arrayvec-0.4.11 \
		atty-0.2.13 \
		auto_enums-0.5.9 \
		auto_enums_core-0.5.9 \
		auto_enums_derive-0.5.9 \
		autocfg-0.1.5 \
		backtrace-0.3.33 \
		backtrace-sys-0.1.31 \
		bitflags-1.1.0 \
		block-0.1.6 \
		bstr-0.2.4 \
		bytecount-0.1.7 \
		bytecount-0.3.2 \
		byteorder-1.3.2 \
		c2-chacha-0.2.2 \
		cast-0.2.2 \
		cc-1.0.37 \
		cfg-if-0.1.9 \
		cgl-0.2.3 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		cocoa-0.18.4 \
		color_quant-1.0.1 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		core-graphics-0.17.3 \
		criterion-0.2.11 \
		criterion-plot-0.3.1 \
		crossbeam-deque-0.6.3 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		csv-1.1.1 \
		csv-core-0.1.6 \
		darling-0.9.0 \
		darling_core-0.9.0 \
		darling_macro-0.9.0 \
		deflate-0.7.20 \
		derivative-1.0.2 \
		derive_utils-0.7.2 \
		dlib-0.4.1 \
		downcast-rs-1.0.4 \
		draw_state-0.8.0 \
		either-1.5.2 \
		err-derive-0.1.5 \
		errno-dragonfly-0.1.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-cprng-0.1.1 \
		gcc-0.3.55 \
		getrandom-0.1.6 \
		gfx-0.17.1 \
		gfx_core-0.8.3 \
		gfx_device_gl-0.15.5 \
		gfx_gl-0.5.0 \
		gif-0.10.2 \
		gl-0.11.0 \
		gl_generator-0.10.0 \
		gl_generator-0.11.0 \
		gl_generator-0.9.0 \
		gleam-0.6.18 \
		glob-0.3.0 \
		glutin-0.21.0 \
		glutin_egl_sys-0.1.3 \
		glutin_emscripten_sys-0.1.0 \
		glutin_gles2_sys-0.1.3 \
		glutin_glx_sys-0.1.5 \
		glutin_wgl_sys-0.1.3 \
		hashbrown-0.5.0 \
		heck-0.3.1 \
		ident_case-1.0.1 \
		image-0.21.2 \
		inflate-0.4.5 \
		interpolation-0.2.0 \
		itertools-0.8.0 \
		itoa-0.4.4 \
		jpeg-decoder-0.1.15 \
		khronos_api-2.2.0 \
		khronos_api-3.1.0 \
		lazy_static-1.3.0 \
		lexical-2.2.1 \
		lexical-core-0.4.2 \
		libc-0.2.60 \
		libloading-0.5.2 \
		line_drawing-0.7.0 \
		lock_api-0.1.5 \
		log-0.4.7 \
		lzw-0.10.0 \
		malloc_buf-0.0.6 \
		memchr-2.2.1 \
		memmap-0.7.0 \
		memoffset-0.2.1 \
		nix-0.14.1 \
		nodrop-0.1.13 \
		num-0.2.0 \
		num-bigint-0.2.2 \
		num-complex-0.2.3 \
		num-derive-0.2.5 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.2.2 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		numtoa-0.1.0 \
		objc-0.2.6 \
		object-pool-0.3.1 \
		ordered-float-1.0.2 \
		osmesa-sys-0.1.2 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		percent-encoding-1.0.1 \
		permutate-0.3.2 \
		piston-0.49.0 \
		piston-ai_behavior-0.31.0 \
		piston-float-1.0.0 \
		piston-gfx_texture-0.36.0 \
		piston-graphics_api_version-0.2.0 \
		piston-shaders_graphics2d-0.3.1 \
		piston-texture-0.6.0 \
		piston-viewport-1.0.0 \
		piston2d-gfx_graphics-0.61.0 \
		piston2d-graphics-0.32.0 \
		piston2d-sprite-0.55.0 \
		piston_window-0.100.0 \
		pistoncore-event_loop-0.49.0 \
		pistoncore-glutin_window-0.63.0 \
		pistoncore-input-0.28.0 \
		pistoncore-window-0.44.0 \
		pkg-config-0.3.14 \
		png-0.14.1 \
		ppv-lite86-0.2.5 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rand-0.4.6 \
		rand-0.6.5 \
		rand-0.7.0 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.0 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_core-0.5.0 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rand_xoshiro-0.1.0 \
		rayon-1.1.0 \
		rayon-core-1.5.0 \
		rdrand-0.4.0 \
		read_color-1.0.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		regex-1.2.0 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.10 \
		rustc-demangle-0.1.15 \
		rustc_version-0.2.3 \
		rusttype-0.7.7 \
		ryu-0.2.8 \
		ryu-1.0.0 \
		same-file-1.0.5 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.97 \
		serde_derive-1.0.97 \
		serde_json-1.0.40 \
		serial_test-0.2.0 \
		serial_test_derive-0.2.0 \
		shader_version-0.6.0 \
		shared_library-0.1.9 \
		smallvec-0.6.10 \
		smithay-client-toolkit-0.4.6 \
		spin-0.5.0 \
		stable_deref_trait-1.1.1 \
		stackvector-1.0.6 \
		static_assertions-0.2.5 \
		stb_truetype-0.2.6 \
		strsim-0.7.0 \
		strsim-0.8.0 \
		structopt-0.2.18 \
		structopt-derive-0.2.18 \
		syn-0.15.40 \
		synstructure-0.10.2 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		tiff-0.2.2 \
		tinytemplate-1.0.2 \
		ucd-util-0.1.5 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		users-0.9.1 \
		utf8-ranges-1.0.3 \
		uuid-0.6.5 \
		vec_map-0.8.1 \
		vecmath-1.0.0 \
		version_check-0.9.1 \
		void-1.0.2 \
		walkdir-2.2.9 \
		wayland-client-0.21.13 \
		wayland-commons-0.21.13 \
		wayland-protocols-0.21.13 \
		wayland-scanner-0.21.13 \
		wayland-sys-0.21.13 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winit-0.19.1 \
		x11-dl-2.18.3 \
		xdg-2.2.0 \
		xml-rs-0.7.0 \
		xml-rs-0.8.0
CARGO_USE_GITHUB=	yes
CARGO_USE_GITLAB=	yes

CONFLICTS_INSTALL=	ion

OPTIONS_DEFINE=	DOCS EXAMPLES

# liner-0.4.4 does not build with Rust 1.40.0.  Use the newer copy
# that is also already available.
post-patch:
	@${REINPLACE_CMD} 's,^liner = .*,liner = \{ path = "${WRKSRC_liner}" \},' \
		${WRKSRC_calculate}/Cargo.toml

post-configure:
	${ECHO_CMD} ${GL_COMMIT} > ${WRKSRC}/git_revision.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ion

post-install-DOCS-on:
	@cd ${WRKSRC}/manual/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/tests && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
