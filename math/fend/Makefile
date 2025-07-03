PORTNAME=	fend
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.6
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Arbitrary-precision unit-aware calculator
WWW=		https://printfn.github.io/fend \
		https://github.com/printfn/fend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	printfn

CARGO_CRATES=	base64-0.21.7 \
		bitflags-2.9.0 \
		bumpalo-3.17.0 \
		cc-1.2.16 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		clipboard-win-5.4.0 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.7 \
		ctrlc-3.4.5 \
		endian-type-0.1.2 \
		equivalent-1.0.2 \
		errno-0.3.10 \
		error-code-3.3.1 \
		fastrand-2.3.0 \
		fd-lock-4.0.4 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		getrandom-0.2.15 \
		getrandom-0.3.1 \
		hashbrown-0.15.2 \
		indexmap-2.8.0 \
		instant-0.1.13 \
		js-sys-0.3.77 \
		libc-0.2.171 \
		linux-raw-sys-0.9.2 \
		log-0.4.26 \
		memchr-2.7.4 \
		minreq-2.13.3 \
		native-tls-0.2.14 \
		nibble_vec-0.1.0 \
		nix-0.29.0 \
		once_cell-1.21.1 \
		openssl-0.10.71 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.6 \
		openssl-sys-0.9.106 \
		pkg-config-0.3.32 \
		ppv-lite86-0.2.21 \
		proc-macro2-1.0.94 \
		quote-1.0.40 \
		radix_trie-0.2.1 \
		rand-0.9.0 \
		rand_chacha-0.9.0 \
		rand_core-0.9.3 \
		ring-0.17.14 \
		rustix-1.0.2 \
		rustls-0.21.12 \
		rustls-native-certs-0.6.3 \
		rustls-pemfile-1.0.4 \
		rustls-webpki-0.101.7 \
		rustversion-1.0.20 \
		rustyline-15.0.0 \
		schannel-0.1.27 \
		sct-0.7.1 \
		security-framework-2.11.1 \
		security-framework-sys-2.14.0 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_spanned-0.6.8 \
		shlex-1.3.0 \
		smallvec-1.14.0 \
		syn-2.0.100 \
		tempfile-3.19.0 \
		toml-0.8.20 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.24 \
		unicode-ident-1.0.18 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.2.0 \
		untrusted-0.9.0 \
		utf8parse-0.2.2 \
		vcpkg-0.2.15 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasi-0.13.3+wasi-0.2.2 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		web-sys-0.3.77 \
		windows-sys-0.52.0 \
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
		winnow-0.7.4 \
		wit-bindgen-rt-0.33.0 \
		zerocopy-0.8.23 \
		zerocopy-derive-0.8.23

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
