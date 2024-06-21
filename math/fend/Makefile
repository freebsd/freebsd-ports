PORTNAME=	fend
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.9
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Arbitrary-precision unit-aware calculator
WWW=		https://printfn.github.io/fend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	printfn

CARGO_CRATES=	base64-0.22.1 \
		bitflags-2.5.0 \
		bumpalo-3.16.0 \
		cc-1.0.99 \
		cfg-if-1.0.0 \
		cfg_aliases-0.1.1 \
		clipboard-win-5.3.1 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.6 \
		ctrlc-3.4.4 \
		endian-type-0.1.2 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		error-code-3.2.0 \
		fastrand-2.1.0 \
		fd-lock-4.0.2 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.2.1 \
		getrandom-0.2.15 \
		hashbrown-0.14.5 \
		home-0.5.9 \
		idna-0.5.0 \
		indexmap-2.2.6 \
		instant-0.1.13 \
		js-sys-0.3.69 \
		libc-0.2.155 \
		linux-raw-sys-0.4.14 \
		log-0.4.21 \
		memchr-2.7.4 \
		native-tls-0.2.12 \
		nibble_vec-0.1.0 \
		nix-0.28.0 \
		once_cell-1.19.0 \
		openssl-0.10.64 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.102 \
		percent-encoding-2.3.1 \
		pkg-config-0.3.30 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.85 \
		quote-1.0.36 \
		radix_trie-0.2.1 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		ring-0.17.8 \
		rustix-0.38.34 \
		rustls-0.22.4 \
		rustls-pki-types-1.7.0 \
		rustls-webpki-0.102.4 \
		rustyline-14.0.0 \
		schannel-0.1.23 \
		security-framework-2.11.0 \
		security-framework-sys-2.11.0 \
		serde-1.0.203 \
		serde_derive-1.0.203 \
		serde_spanned-0.6.6 \
		smallvec-1.13.2 \
		spin-0.9.8 \
		subtle-2.6.0 \
		syn-2.0.66 \
		tempfile-3.10.1 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		toml-0.8.14 \
		toml_datetime-0.6.6 \
		toml_edit-0.22.14 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-segmentation-1.11.0 \
		unicode-width-0.1.13 \
		untrusted-0.9.0 \
		ureq-2.9.7 \
		url-2.5.2 \
		utf8parse-0.2.2 \
		vcpkg-0.2.15 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.92 \
		wasm-bindgen-backend-0.2.92 \
		wasm-bindgen-macro-0.2.92 \
		wasm-bindgen-macro-support-0.2.92 \
		wasm-bindgen-shared-0.2.92 \
		web-sys-0.3.69 \
		webpki-roots-0.26.3 \
		windows-sys-0.52.0 \
		windows-targets-0.52.5 \
		windows_aarch64_gnullvm-0.52.5 \
		windows_aarch64_msvc-0.52.5 \
		windows_i686_gnu-0.52.5 \
		windows_i686_gnullvm-0.52.5 \
		windows_i686_msvc-0.52.5 \
		windows_x86_64_gnu-0.52.5 \
		windows_x86_64_gnullvm-0.52.5 \
		windows_x86_64_msvc-0.52.5 \
		winnow-0.6.13 \
		zeroize-1.8.1

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
