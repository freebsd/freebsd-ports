PORTNAME=	fend
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
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
		bitflags-2.6.0 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		cc-1.1.25 \
		cfg-if-1.0.0 \
		cfg_aliases-0.1.1 \
		cfg_aliases-0.2.1 \
		clipboard-win-5.4.0 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.7 \
		ctrlc-3.4.5 \
		endian-type-0.1.2 \
		equivalent-1.0.1 \
		errno-0.3.9 \
		error-code-3.3.1 \
		fastrand-2.1.1 \
		fd-lock-4.0.2 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		getrandom-0.2.15 \
		hashbrown-0.15.0 \
		home-0.5.9 \
		indexmap-2.6.0 \
		instant-0.1.13 \
		js-sys-0.3.70 \
		libc-0.2.159 \
		linux-raw-sys-0.4.14 \
		log-0.4.22 \
		memchr-2.7.4 \
		minreq-2.12.0 \
		native-tls-0.2.12 \
		nibble_vec-0.1.0 \
		nix-0.28.0 \
		nix-0.29.0 \
		once_cell-1.20.2 \
		openssl-0.10.66 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.103 \
		pkg-config-0.3.31 \
		ppv-lite86-0.2.20 \
		proc-macro2-1.0.86 \
		quote-1.0.37 \
		radix_trie-0.2.1 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		ring-0.17.8 \
		rustix-0.38.37 \
		rustls-0.21.12 \
		rustls-native-certs-0.6.3 \
		rustls-pemfile-1.0.4 \
		rustls-webpki-0.101.7 \
		rustyline-14.0.0 \
		schannel-0.1.24 \
		sct-0.7.1 \
		security-framework-2.11.1 \
		security-framework-sys-2.12.0 \
		serde-1.0.210 \
		serde_derive-1.0.210 \
		serde_spanned-0.6.8 \
		shlex-1.3.0 \
		smallvec-1.13.2 \
		spin-0.9.8 \
		syn-2.0.79 \
		tempfile-3.13.0 \
		toml-0.8.19 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.22 \
		unicode-ident-1.0.13 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.1.14 \
		untrusted-0.9.0 \
		utf8parse-0.2.2 \
		vcpkg-0.2.15 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.93 \
		wasm-bindgen-backend-0.2.93 \
		wasm-bindgen-macro-0.2.93 \
		wasm-bindgen-macro-support-0.2.93 \
		wasm-bindgen-shared-0.2.93 \
		web-sys-0.3.70 \
		webpki-roots-0.25.4 \
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
		winnow-0.6.20 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
