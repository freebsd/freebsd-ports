# $FreeBSD$

PORTNAME=	ffsend
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.46
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Easily and securely share files from the command line via Firefox Send

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE CC0-1.0 FUCHSIACPRNG GPLv3 ISCL MIT MPL20 UNLICENSE
LICENSE_COMB=	multi
# Main license.
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE
LICENSE_NAME_FUCHSIACPRNG=	BSD-like license + patent clause
LICENSE_FILE_FUCHSIACPRNG=	${WRKSRC}/cargo-crates/fuchsia-cprng-0.1.1/LICENSE
LICENSE_PERMS_FUCHSIACPRNG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		xclip:x11/xclip \
		xsel:x11/xsel-conrad

USES=		cargo localbase:ldflags python:build,3.5+ ssl xorg
USE_GITLAB=	yes
GL_ACCOUNT=	timvisee
GL_COMMIT=	7751898851511a516aa0d017afea1d8a8260a02a
USE_XORG=	xcb

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		approx-0.1.1 \
		argon2rs-0.2.5 \
		arrayref-0.3.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		base64-0.10.1 \
		base64-0.9.3 \
		bitflags-1.0.5 \
		blake2-rfc-0.2.18 \
		block-0.1.6 \
		block-buffer-0.7.3 \
		block-padding-0.1.4 \
		build_const-0.2.1 \
		byte-tools-0.3.1 \
		byteorder-1.3.1 \
		bytes-0.4.12 \
		cc-1.0.36 \
		cfg-if-0.1.7 \
		cgmath-0.16.1 \
		chbs-0.0.8 \
		checked_int_cast-1.0.0 \
		chrono-0.4.6 \
		clap-2.33.0 \
		clipboard-0.5.0 \
		clipboard-win-2.1.2 \
		cloudabi-0.0.3 \
		colored-1.8.0 \
		constant_time_eq-0.1.3 \
		cookie-0.11.1 \
		cookie_store-0.5.1 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crc-1.8.1 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		crossterm-0.9.3 \
		crossterm_style-0.3.1 \
		crossterm_utils-0.2.1 \
		crossterm_winapi-0.1.2 \
		crypto-mac-0.7.0 \
		csv-1.0.7 \
		csv-core-0.1.5 \
		darling-0.6.3 \
		darling-0.8.6 \
		darling_core-0.6.3 \
		darling_core-0.8.6 \
		darling_macro-0.6.3 \
		darling_macro-0.8.6 \
		derive_builder-0.6.0 \
		derive_builder-0.7.1 \
		derive_builder_core-0.3.0 \
		derive_builder_core-0.4.1 \
		digest-0.8.0 \
		directories-1.0.2 \
		dirs-1.0.5 \
		dtoa-0.4.4 \
		encode_unicode-0.3.5 \
		encoding_rs-0.8.17 \
		error-chain-0.12.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fake-simd-0.1.2 \
		ffsend-api-0.3.2 \
		filetime-0.2.5 \
		flate2-1.0.7 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fs2-0.4.3 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.26 \
		futures-cpupool-0.1.8 \
		generic-array-0.12.0 \
		h2-0.1.18 \
		hkdf-0.7.0 \
		hmac-0.7.0 \
		http-0.1.17 \
		httparse-1.3.3 \
		hyper-0.10.16 \
		hyper-0.12.28 \
		hyper-tls-0.3.2 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		indexmap-1.0.2 \
		iovec-0.1.2 \
		itoa-0.4.4 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-1.3.0 \
		lazycell-1.2.1 \
		libc-0.2.54 \
		lock_api-0.1.5 \
		log-0.3.9 \
		log-0.4.6 \
		malloc_buf-0.0.6 \
		matches-0.1.8 \
		memchr-2.2.0 \
		memoffset-0.2.1 \
		mime-0.2.6 \
		mime-0.3.13 \
		mime_guess-2.0.0-alpha.6 \
		miniz_oxide-0.2.1 \
		miniz_oxide_c_api-0.2.1 \
		mio-0.6.16 \
		miow-0.2.1 \
		native-tls-0.2.3 \
		net2-0.2.33 \
		nodrop-0.1.13 \
		num-integer-0.1.39 \
		num-traits-0.1.43 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		numtoa-0.1.0 \
		objc-0.2.6 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		opaque-debug-0.2.2 \
		open-1.2.2 \
		openssl-0.10.21 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.45 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot_core-0.4.0 \
		pbr-1.0.1 \
		percent-encoding-1.0.1 \
		phf-0.7.24 \
		phf_codegen-0.7.24 \
		phf_generator-0.7.24 \
		phf_shared-0.7.24 \
		pkg-config-0.3.14 \
		prettytable-rs-0.8.0 \
		proc-macro2-0.3.8 \
		proc-macro2-0.4.29 \
		publicsuffix-1.5.2 \
		qr2term-0.1.2 \
		qrcode-0.10.0 \
		quote-0.5.2 \
		quote-0.6.12 \
		rand-0.4.6 \
		rand-0.5.6 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		regex-1.1.6 \
		regex-syntax-0.6.6 \
		remove_dir_all-0.5.1 \
		reqwest-0.9.16 \
		rgb-0.8.13 \
		rpassword-3.0.2 \
		rustc-demangle-0.1.14 \
		rustc_version-0.2.3 \
		ryu-0.2.8 \
		safemem-0.3.0 \
		schannel-0.1.15 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		security-framework-0.3.1 \
		security-framework-sys-0.3.1 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		serde_json-1.0.39 \
		serde_urlencoded-0.5.5 \
		sha1-0.6.0 \
		sha2-0.8.0 \
		siphasher-0.2.3 \
		slab-0.4.2 \
		smallvec-0.6.9 \
		stable_deref_trait-1.1.1 \
		string-0.1.3 \
		strsim-0.8.0 \
		subtle-1.0.0 \
		syn-0.13.11 \
		syn-0.15.33 \
		synstructure-0.10.1 \
		tar-0.4.24 \
		tempfile-3.0.7 \
		term-0.5.2 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		tokio-0.1.19 \
		tokio-codec-0.1.1 \
		tokio-current-thread-0.1.6 \
		tokio-executor-0.1.7 \
		tokio-io-0.1.12 \
		tokio-reactor-0.1.9 \
		tokio-sync-0.1.5 \
		tokio-tcp-0.1.3 \
		tokio-threadpool-0.1.14 \
		tokio-timer-0.2.10 \
		tokio-tls-0.2.1 \
		tokio-trace-core-0.1.0 \
		toml-0.5.0 \
		traitobject-0.1.0 \
		try-lock-0.2.2 \
		try_from-0.3.2 \
		typeable-0.1.2 \
		typenum-1.10.0 \
		ucd-util-0.1.3 \
		unicase-1.4.2 \
		unicase-2.4.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		url-1.7.2 \
		url_serde-0.2.0 \
		urlshortener-0.10.0 \
		utf8-ranges-1.0.2 \
		uuid-0.7.4 \
		vcpkg-0.2.6 \
		vec_map-0.8.1 \
		version-compare-0.0.6 \
		version-compare-0.0.8 \
		version_check-0.1.5 \
		want-0.0.6 \
		websocket-0.22.4 \
		which-2.0.1 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winconsole-0.10.0 \
		ws2_32-sys-0.2.1 \
		x11-clipboard-0.3.1 \
		xattr-0.2.2 \
		xcb-0.8.2

BINARY_ALIAS=	python3=${PYTHON_CMD}
MAKE_ENV=	XCLIP_PATH=${LOCALBASE}/bin/xclip \
		XSEL_PATH=${LOCALBASE}/bin/xsel
PLIST_FILES=	bin/${PORTNAME} \
		bin/ffdel \
		bin/ffget \
		bin/ffput

# XXX: Remove when support for FreeBSD is enabled upstream:
# https://gitlab.com/timvisee/ffsend/issues/87
post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} 's,"linux","${OPSYS:tl}",g' \
		build.rs Cargo.toml src/action/debug.rs src/util.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for f in ffdel ffget ffput
	cd ${STAGEDIR}${PREFIX}/bin && ${RLN} ${PORTNAME} ${f}
.endfor

.include <bsd.port.mk>
