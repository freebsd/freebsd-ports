PORTNAME=	fend
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Arbitrary-precision unit-aware calculator
WWW=		https://printfn.github.io/fend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	printfn

CARGO_CRATES=	base64-0.21.7 \
		bitflags-1.3.2 \
		bitflags-2.4.2 \
		bumpalo-3.15.3 \
		cc-1.0.86 \
		cfg-if-1.0.0 \
		clipboard-win-5.2.0 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.6 \
		ctrlc-3.4.2 \
		endian-type-0.1.2 \
		equivalent-1.0.1 \
		errno-0.3.8 \
		error-code-3.0.0 \
		fastrand-2.0.1 \
		fd-lock-4.0.2 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.2.1 \
		getrandom-0.2.12 \
		hashbrown-0.14.3 \
		home-0.5.9 \
		idna-0.5.0 \
		indexmap-2.2.3 \
		instant-0.1.12 \
		js-sys-0.3.68 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		linux-raw-sys-0.4.13 \
		log-0.4.20 \
		memchr-2.7.1 \
		native-tls-0.2.11 \
		nibble_vec-0.1.0 \
		nix-0.27.1 \
		once_cell-1.19.0 \
		openssl-0.10.64 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.101 \
		percent-encoding-2.3.1 \
		pkg-config-0.3.30 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.78 \
		quote-1.0.35 \
		radix_trie-0.2.1 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		ring-0.17.8 \
		rustix-0.38.31 \
		rustls-0.22.2 \
		rustls-pki-types-1.3.0 \
		rustls-webpki-0.102.2 \
		rustyline-13.0.0 \
		schannel-0.1.23 \
		security-framework-2.9.2 \
		security-framework-sys-2.9.1 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_spanned-0.6.5 \
		smallvec-1.13.1 \
		spin-0.9.8 \
		subtle-2.5.0 \
		syn-2.0.50 \
		tempfile-3.10.0 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		toml-0.8.10 \
		toml_datetime-0.6.5 \
		toml_edit-0.22.6 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.11 \
		untrusted-0.9.0 \
		ureq-2.9.6 \
		url-2.5.0 \
		utf8parse-0.2.1 \
		vcpkg-0.2.15 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.91 \
		wasm-bindgen-backend-0.2.91 \
		wasm-bindgen-macro-0.2.91 \
		wasm-bindgen-macro-support-0.2.91 \
		wasm-bindgen-shared-0.2.91 \
		web-sys-0.3.68 \
		webpki-roots-0.26.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.3 \
		windows_aarch64_gnullvm-0.52.3 \
		windows_aarch64_msvc-0.52.3 \
		windows_i686_gnu-0.52.3 \
		windows_i686_msvc-0.52.3 \
		windows_x86_64_gnu-0.52.3 \
		windows_x86_64_gnullvm-0.52.3 \
		windows_x86_64_msvc-0.52.3 \
		winnow-0.6.2 \
		zeroize-1.7.0

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
