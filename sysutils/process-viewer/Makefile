PORTNAME=	process-viewer
DISTVERSION=	g20220909
PORTREVISION=	24
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Process viewer GUI in Rust
WWW=		https://github.com/guillaumegomez/process-viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		cargo gnome
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 pango

USE_GITHUB=	yes
GH_ACCOUNT=	guillaumegomez
GH_TAGNAME=	b270176

CARGO_CRATES=	anyhow-1.0.57 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cairo-rs-0.15.11 \
		cairo-sys-rs-0.15.1 \
		cfg-expr-0.10.2 \
		cfg-if-1.0.0 \
		core-foundation-sys-0.8.3 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		either-1.6.1 \
		field-offset-0.3.4 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		gdk-pixbuf-0.15.11 \
		gdk-pixbuf-sys-0.15.10 \
		gdk4-0.4.7 \
		gdk4-sys-0.4.2 \
		gio-0.15.11 \
		gio-sys-0.15.10 \
		glib-0.15.11 \
		glib-macros-0.15.11 \
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
		hermit-abi-0.1.19 \
		lazy_static-1.4.0 \
		libc-0.2.124 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		ntapi-0.3.7 \
		num_cpus-1.13.1 \
		once_cell-1.10.0 \
		pango-0.15.10 \
		pango-sys-0.15.10 \
		pest-2.1.3 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.25 \
		proc-macro-crate-1.1.3 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.37 \
		quick-xml-0.22.0 \
		quote-1.0.18 \
		rayon-1.5.2 \
		rayon-core-1.9.2 \
		rustc_version-0.3.3 \
		scopeguard-1.1.0 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		slab-0.4.6 \
		smallvec-1.8.0 \
		syn-1.0.91 \
		sysinfo-0.26.2 \
		system-deps-6.0.2 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		toml-0.5.9 \
		ucd-trie-0.1.3 \
		unicode-xid-0.2.2 \
		version-compare-0.1.0 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/process_viewer

.include <bsd.port.mk>
