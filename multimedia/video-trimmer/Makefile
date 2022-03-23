PORTNAME=	video-trimmer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	multimedia

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	2faf4bb13d44.patch:-p1 # https://gitlab.gnome.org/YaLTeR/video-trimmer/-/merge_requests/12

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Trim videos quickly
WWW=		https://gitlab.gnome.org/YaLTeR/video-trimmer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	blueprint-compiler:devel/blueprint-compiler
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cargo desktop-file-utils gettext gnome gstreamer meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	good libav
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	YaLTeR
GL_COMMIT=	fe64a108f1bf7b57d4bc7d7dc456034c30b0fdea
MAKE_ENV=	${CARGO_ENV}
GLIB_SCHEMAS=	org.gnome.gitlab.YaLTeR.VideoTrimmer.gschema.xml

CARGO_CRATES=	aho-corasick-0.7.18 \
		anyhow-1.0.56 \
		ashpd-0.3.0 \
		async-broadcast-0.3.4 \
		async-channel-1.6.1 \
		async-executor-1.4.1 \
		async-io-1.6.0 \
		async-lock-2.5.0 \
		async-recursion-0.3.2 \
		async-task-4.2.0 \
		async-trait-0.1.52 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		block-0.1.6 \
		byteorder-1.4.3 \
		cache-padded-1.2.0 \
		cairo-rs-0.15.10 \
		cairo-sys-rs-0.15.1 \
		cc-1.0.73 \
		cfg-expr-0.10.2 \
		cfg-if-1.0.0 \
		concurrent-queue-1.2.2 \
		derivative-2.2.0 \
		easy-parallel-3.2.0 \
		enumflags2-0.7.3 \
		enumflags2_derive-0.7.3 \
		event-listener-2.5.2 \
		fastrand-1.7.0 \
		field-offset-0.3.4 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-lite-1.12.0 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		gdk-pixbuf-0.15.10 \
		gdk-pixbuf-sys-0.15.10 \
		gdk4-0.4.7 \
		gdk4-sys-0.4.2 \
		gdk4-wayland-0.4.7 \
		gdk4-wayland-sys-0.4.2 \
		gdk4-x11-0.4.2 \
		gdk4-x11-sys-0.4.2 \
		getrandom-0.2.5 \
		gettext-rs-0.7.0 \
		gettext-sys-0.21.3 \
		gio-0.15.10 \
		gio-sys-0.15.10 \
		glib-0.15.10 \
		glib-macros-0.15.10 \
		glib-sys-0.15.10 \
		gobject-sys-0.15.10 \
		graphene-rs-0.15.1 \
		graphene-sys-0.15.10 \
		gsk4-0.4.7 \
		gsk4-sys-0.4.2 \
		gtk4-0.4.7 \
		gtk4-macros-0.4.7 \
		gtk4-sys-0.4.5 \
		heck-0.4.0 \
		hex-0.4.3 \
		instant-0.1.12 \
		json-0.12.4 \
		lazy_static-1.4.0 \
		libadwaita-0.1.1 \
		libadwaita-sys-0.1.0 \
		libc-0.2.121 \
		locale_config-0.3.0 \
		log-0.4.16 \
		malloc_buf-0.0.6 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		mime-0.3.16 \
		mime_guess-2.0.4 \
		minimal-lexical-0.2.1 \
		nix-0.23.1 \
		nom-7.1.1 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		once_cell-1.10.0 \
		ordered-stream-0.0.1 \
		pango-0.15.10 \
		pango-sys-0.15.10 \
		parking-2.0.0 \
		pest-2.1.3 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		pkg-config-0.3.24 \
		polling-2.2.0 \
		ppv-lite86-0.2.16 \
		proc-macro-crate-1.1.3 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quick-xml-0.22.0 \
		quote-1.0.16 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		rustc_version-0.3.3 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_repr-0.1.7 \
		sha1-0.6.1 \
		sha1_smol-1.0.0 \
		slab-0.4.5 \
		smallvec-1.8.0 \
		socket2-0.4.4 \
		static_assertions-1.1.0 \
		syn-1.0.89 \
		system-deps-6.0.2 \
		temp-dir-0.1.11 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		toml-0.5.8 \
		ucd-trie-0.1.3 \
		unicase-2.6.0 \
		unicode-xid-0.2.2 \
		version-compare-0.1.0 \
		version_check-0.9.4 \
		waker-fn-1.1.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wepoll-ffi-0.1.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zbus-2.1.1 \
		zbus_macros-2.1.1 \
		zbus_names-2.1.0 \
		zvariant-3.1.2 \
		zvariant_derive-3.1.2
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

post-patch:
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		-Ee '/cp/s,/(release|debug)/,/${CARGO_BUILD_TARGET}&,' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.mk>
