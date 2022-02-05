PORTNAME=	helvum
DISTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	multimedia

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	c17bc2674d4e.patch:-p1 # https://gitlab.freedesktop.org/ryuukyu/helvum/-/merge_requests/19

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK patchbay for PipeWire

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cargo gnome meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	cairo gtk40
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	ryuukyu
GL_COMMIT=	c1ec56e115b4992969514c5c5d0950ae4170913a
SHEBANG_FILES=	build-aux/cargo.sh build-aux/meson_post_install.py
bash_CMD=	${SH}
MAKE_ENV=	${CARGO_ENV}
PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		anyhow-1.0.44 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.59.1 \
		bitflags-1.3.2 \
		bitvec-0.19.5 \
		cairo-rs-0.14.7 \
		cairo-sys-rs-0.14.0 \
		cc-1.0.70 \
		cexpr-0.5.0 \
		cfg-expr-0.8.1 \
		cfg-expr-0.9.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-1.2.2 \
		clap-2.33.3 \
		cookie-factory-0.3.2 \
		either-1.6.1 \
		env_logger-0.8.4 \
		env_logger-0.9.0 \
		errno-0.2.7 \
		errno-dragonfly-0.1.2 \
		field-offset-0.3.4 \
		funty-1.1.0 \
		futures-channel-0.3.17 \
		futures-core-0.3.17 \
		futures-executor-0.3.17 \
		futures-io-0.3.17 \
		futures-task-0.3.17 \
		futures-util-0.3.17 \
		gdk-pixbuf-0.14.0 \
		gdk-pixbuf-sys-0.14.0 \
		gdk4-0.3.0 \
		gdk4-sys-0.3.0 \
		gio-0.14.6 \
		gio-sys-0.14.0 \
		glib-0.14.5 \
		glib-macros-0.14.1 \
		glib-sys-0.14.0 \
		glob-0.3.0 \
		gobject-sys-0.14.0 \
		graphene-rs-0.14.0 \
		graphene-sys-0.14.0 \
		gsk4-0.3.0 \
		gsk4-sys-0.3.0 \
		gtk4-0.3.0 \
		gtk4-macros-0.3.0 \
		gtk4-sys-0.3.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		itertools-0.10.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		lexical-core-0.7.6 \
		libc-0.2.103 \
		libloading-0.7.0 \
		libspa-0.4.1 \
		libspa-sys-0.4.1 \
		log-0.4.14 \
		memchr-2.3.4 \
		memoffset-0.6.4 \
		nix-0.14.1 \
		nom-6.2.1 \
		once_cell-1.8.0 \
		pango-0.14.3 \
		pango-sys-0.14.0 \
		peeking_take_while-0.1.2 \
		pest-2.1.3 \
		pin-project-lite-0.2.7 \
		pin-utils-0.1.0 \
		pipewire-0.4.1 \
		pipewire-sys-0.4.1 \
		pkg-config-0.3.20 \
		proc-macro-crate-1.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.29 \
		quote-1.0.9 \
		radium-0.5.3 \
		regex-1.4.6 \
		regex-syntax-0.6.25 \
		rustc-hash-1.1.0 \
		rustc_version-0.3.3 \
		ryu-1.0.5 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.130 \
		shlex-1.1.0 \
		signal-0.7.0 \
		slab-0.4.4 \
		smallvec-1.7.0 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		strum-0.21.0 \
		strum_macros-0.21.1 \
		syn-1.0.77 \
		system-deps-3.2.0 \
		system-deps-4.0.0 \
		tap-1.0.1 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thiserror-1.0.29 \
		thiserror-impl-1.0.29 \
		toml-0.5.8 \
		ucd-trie-0.1.3 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version-compare-0.0.11 \
		version_check-0.9.3 \
		void-1.0.2 \
		which-3.1.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1300134
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
LDFLAGS+=	-lepoll-shim
.endif

.include <bsd.port.mk>
