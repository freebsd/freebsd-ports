PORTNAME=	tuifeed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Trminal feed reader with a fancy UI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	veeso

CARGO_BUILD_ARGS=	--locked
CARGO_INSTALL_ARGS=	--locked
CARGO_UPDATE_ARGS=	--locked

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		argh-0.1.6 \
		argh_derive-0.1.6 \
		argh_shared-0.1.6 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		bumpalo-3.8.0 \
		cassowary-0.3.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		chunked_transfer-1.4.0 \
		crossterm-0.20.0 \
		crossterm_winapi-0.8.0 \
		ctor-0.1.21 \
		diff-0.1.12 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		encoding_rs-0.8.29 \
		feed-rs-1.0.0 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		heck-0.3.3 \
		idna-0.2.3 \
		instant-0.1.12 \
		itoa-0.4.8 \
		js-sys-0.3.55 \
		lazy_static-1.4.0 \
		libc-0.2.107 \
		lock_api-0.4.5 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		mime-0.3.16 \
		mio-0.7.14 \
		miow-0.3.7 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		once_cell-1.8.0 \
		open-2.0.1 \
		output_vt100-0.1.2 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		pathdiff-0.2.1 \
		percent-encoding-2.1.0 \
		ppv-lite86-0.2.15 \
		pretty_assertions-0.7.2 \
		proc-macro2-1.0.32 \
		quick-xml-0.22.0 \
		quote-1.0.10 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		ring-0.16.20 \
		rustls-0.20.1 \
		ryu-1.0.5 \
		scopeguard-1.1.0 \
		sct-0.7.0 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.70 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		signal-hook-0.3.10 \
		signal-hook-mio-0.2.1 \
		signal-hook-registry-1.4.0 \
		siphasher-0.3.7 \
		smallvec-1.7.0 \
		smawk-0.3.1 \
		spin-0.5.2 \
		syn-1.0.81 \
		tempfile-3.2.0 \
		textwrap-0.14.2 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.1.44 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		tui-0.16.0 \
		tui-realm-stdlib-1.0.3 \
		tuirealm-1.0.0 \
		tuirealm_derive-1.0.0 \
		unicode-bidi-0.3.7 \
		unicode-linebreak-0.1.2 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.8.0 \
		unicode-truncate-0.2.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		ureq-2.3.1 \
		url-2.2.2 \
		uuid-0.8.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.78 \
		wasm-bindgen-backend-0.2.78 \
		wasm-bindgen-macro-0.2.78 \
		wasm-bindgen-macro-support-0.2.78 \
		wasm-bindgen-shared-0.2.78 \
		web-sys-0.3.55 \
		webpki-0.22.0 \
		webpki-roots-0.22.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*md
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
