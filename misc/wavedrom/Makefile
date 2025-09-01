PORTNAME=	wavedrom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Beautiful Digital Timing Diagrams with Rust
WWW=		https://coastalwhite.github.io/wavedrom-rs \
		https://github.com/coastalwhite/wavedrom-rs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	coastalwhite
GH_PROJECT=	${PORTNAME}-rs

CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.7 \
		anyhow-1.0.98 \
		autocfg-1.4.0 \
		bitflags-2.9.0 \
		block-buffer-0.10.4 \
		bstr-1.12.0 \
		bumpalo-3.17.0 \
		cc-1.2.21 \
		cfg-if-1.0.0 \
		chrono-0.4.41 \
		clap-4.5.37 \
		clap_builder-4.5.37 \
		clap_complete-4.5.49 \
		clap_lex-0.7.4 \
		colorchoice-1.0.3 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.6 \
		darling-0.20.11 \
		darling_core-0.20.11 \
		darling_macro-0.20.11 \
		dbus-0.9.7 \
		derive_builder-0.20.2 \
		derive_builder_core-0.20.2 \
		derive_builder_macro-0.20.2 \
		digest-0.10.7 \
		env_filter-0.1.3 \
		env_logger-0.11.8 \
		errno-0.3.11 \
		fastrand-2.3.0 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getopts-0.2.21 \
		getrandom-0.3.2 \
		handlebars-6.3.2 \
		hex-0.4.3 \
		iana-time-zone-0.1.63 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.15 \
		jiff-0.2.13 \
		jiff-static-0.2.13 \
		js-sys-0.3.77 \
		json5-0.4.1 \
		libc-0.2.172 \
		libdbus-sys-0.2.5 \
		linux-raw-sys-0.9.4 \
		log-0.4.27 \
		mdbook-0.4.49 \
		memchr-2.7.4 \
		normpath-1.3.0 \
		num-modular-0.6.1 \
		num-order-1.2.0 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		opener-0.7.2 \
		pest-2.8.0 \
		pest_derive-2.8.0 \
		pest_generator-2.8.0 \
		pest_meta-2.8.0 \
		pkg-config-0.3.32 \
		portable-atomic-1.11.0 \
		portable-atomic-util-0.2.4 \
		proc-macro2-1.0.95 \
		pulldown-cmark-0.9.6 \
		pulldown-cmark-0.10.3 \
		pulldown-cmark-escape-0.10.1 \
		pulldown-cmark-to-cmark-10.0.4 \
		quote-1.0.40 \
		r-efi-5.2.0 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustix-1.0.7 \
		rustversion-1.0.20 \
		ryu-1.0.20 \
		semver-1.0.26 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.140 \
		sha2-0.10.9 \
		shlex-1.3.0 \
		strsim-0.11.1 \
		syn-2.0.101 \
		tempfile-3.19.1 \
		terminal_size-0.4.2 \
		thiserror-2.0.12 \
		thiserror-impl-2.0.12 \
		toml-0.5.11 \
		topological-sort-0.2.2 \
		ttf-parser-0.19.2 \
		typenum-1.18.0 \
		ucd-trie-0.1.7 \
		unicase-2.8.1 \
		unicode-ident-1.0.18 \
		unicode-width-0.1.14 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		wasi-0.14.2+wasi-0.2.4 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.61.0 \
		windows-implement-0.60.0 \
		windows-interface-0.59.1 \
		windows-link-0.1.1 \
		windows-result-0.3.2 \
		windows-strings-0.4.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		wit-bindgen-rt-0.39.0

PLIST_FILES=	bin/${PORTNAME}  \
		bin/mdbook-wavedrom-rs

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
.for e in ${PORTNAME} mdbook-wavedrom-rs
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${e} \
		${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
