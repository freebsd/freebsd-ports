PORTNAME=	process-viewer
DISTVERSION=	g20260130
PORTREVISION=	1
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
GH_TAGNAME=	b69bb53

CARGO_CRATES=	async-channel-2.5.0 \
		autocfg-1.5.0 \
		bitflags-2.10.0 \
		cairo-rs-0.21.5 \
		cairo-sys-rs-0.21.5 \
		cfg-expr-0.20.6 \
		concurrent-queue-2.5.0 \
		crossbeam-utils-0.8.21 \
		equivalent-1.0.2 \
		event-listener-5.4.1 \
		event-listener-strategy-0.5.4 \
		field-offset-0.3.6 \
		futures-channel-0.3.31 \
		futures-core-0.3.31 \
		futures-executor-0.3.31 \
		futures-io-0.3.31 \
		futures-macro-0.3.31 \
		futures-task-0.3.31 \
		futures-util-0.3.31 \
		gdk-pixbuf-0.21.5 \
		gdk-pixbuf-sys-0.21.5 \
		gdk4-0.10.3 \
		gdk4-sys-0.10.3 \
		gio-0.21.5 \
		gio-sys-0.21.5 \
		glib-0.21.5 \
		glib-macros-0.21.5 \
		glib-sys-0.21.5 \
		gobject-sys-0.21.5 \
		graphene-rs-0.21.5 \
		graphene-sys-0.21.5 \
		gsk4-0.10.3 \
		gsk4-sys-0.10.3 \
		gtk4-0.10.3 \
		gtk4-macros-0.10.3 \
		gtk4-sys-0.10.3 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		indexmap-2.13.0 \
		libc-0.2.180 \
		memchr-2.7.6 \
		memoffset-0.9.1 \
		ntapi-0.4.2 \
		objc2-core-foundation-0.3.2 \
		objc2-io-kit-0.3.2 \
		pango-0.21.5 \
		pango-sys-0.21.5 \
		parking-2.2.1 \
		pin-project-lite-0.2.16 \
		pin-utils-0.1.0 \
		pkg-config-0.3.32 \
		proc-macro-crate-3.4.0 \
		proc-macro2-1.0.106 \
		quote-1.0.44 \
		rustc_version-0.4.1 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_spanned-0.6.9 \
		serde_spanned-1.0.4 \
		slab-0.4.11 \
		smallvec-1.15.1 \
		syn-2.0.114 \
		sysinfo-0.38.0 \
		system-deps-7.0.7 \
		target-lexicon-0.13.3 \
		toml-0.8.23 \
		toml-0.9.11+spec-1.1.0 \
		toml_datetime-0.6.11 \
		toml_datetime-0.7.5+spec-1.1.0 \
		toml_edit-0.22.27 \
		toml_edit-0.23.10+spec-1.0.0 \
		toml_parser-1.0.6+spec-1.1.0 \
		toml_write-0.1.2 \
		toml_writer-1.0.6+spec-1.1.0 \
		unicode-ident-1.0.22 \
		version-compare-0.2.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.62.2 \
		windows-collections-0.3.2 \
		windows-core-0.62.2 \
		windows-future-0.3.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-numerics-0.3.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		windows-sys-0.61.2 \
		windows-threading-0.2.1 \
		winnow-0.7.14

PLIST_FILES=	bin/process_viewer

.include <bsd.port.mk>
