PORTNAME=	magika
DISTVERSIONPREFIX=	cli/v
DISTVERSION=	1.1.0
CATEGORIES=	sysutils # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and accurate AI powered file content types detection
WWW=		https://securityresearch.google/magika/ \
		https://github.com/google/magika

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

LIB_DEPENDS=	libonnxruntime.so:misc/onnxruntime

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	google

WRKSRC_SUBDIR=	rust/cli

CARGO_CRATES=	addr2line-0.25.1 \
		adler2-2.0.1 \
		anstream-0.6.21 \
		anstyle-1.0.13 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.4 \
		anstyle-wincon-3.0.10 \
		anyhow-1.0.100 \
		async-channel-2.5.0 \
		autocfg-1.5.0 \
		backtrace-0.3.76 \
		base64-0.22.1 \
		base64ct-1.8.0 \
		bitflags-2.9.4 \
		byteorder-1.5.0 \
		bytes-1.11.1 \
		cc-1.2.40 \
		cfg-if-1.0.3 \
		clap-4.5.48 \
		clap_builder-4.5.48 \
		clap_derive-4.5.47 \
		clap_lex-0.7.5 \
		colorchoice-1.0.4 \
		colored-3.0.0 \
		concurrent-queue-2.5.0 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.7 \
		crossbeam-utils-0.8.21 \
		der-0.7.10 \
		errno-0.3.14 \
		event-listener-5.4.1 \
		event-listener-strategy-0.5.4 \
		fastrand-2.3.0 \
		find-msvc-tools-0.1.3 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		futures-core-0.3.31 \
		getrandom-0.3.3 \
		gimli-0.32.3 \
		heck-0.5.0 \
		hermit-abi-0.5.2 \
		hmac-sha256-1.1.14 \
		http-1.3.1 \
		httparse-1.10.1 \
		io-uring-0.7.10 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.15 \
		libc-0.2.176 \
		linux-raw-sys-0.11.0 \
		lock_api-0.4.14 \
		log-0.4.28 \
		lzma-rust2-0.15.7 \
		matrixmultiply-0.3.10 \
		memchr-2.7.6 \
		miniz_oxide-0.8.9 \
		mio-1.0.4 \
		native-tls-0.2.14 \
		ndarray-0.17.1 \
		num-complex-0.4.6 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		num_cpus-1.17.0 \
		object-0.37.3 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.1 \
		openssl-0.10.78 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.6 \
		openssl-sys-0.9.114 \
		ort-2.0.0-rc.12 \
		ort-sys-2.0.0-rc.12 \
		parking-2.2.1 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		pem-rfc7468-0.7.0 \
		percent-encoding-2.3.2 \
		pin-project-lite-0.2.16 \
		pkg-config-0.3.32 \
		portable-atomic-1.11.1 \
		portable-atomic-util-0.2.4 \
		proc-macro2-1.0.101 \
		quote-1.0.41 \
		r-efi-5.3.0 \
		rawpointer-0.2.1 \
		redox_syscall-0.5.18 \
		rustc-demangle-0.1.26 \
		rustix-1.1.2 \
		rustls-pemfile-2.2.0 \
		rustls-pki-types-1.12.0 \
		ryu-1.0.20 \
		schannel-0.1.28 \
		scopeguard-1.2.0 \
		security-framework-2.11.1 \
		security-framework-sys-2.15.0 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.145 \
		shlex-1.3.0 \
		signal-hook-registry-1.4.6 \
		slab-0.4.11 \
		smallvec-1.15.1 \
		socket2-0.6.0 \
		socks-0.3.4 \
		strsim-0.11.1 \
		syn-2.0.106 \
		tempfile-3.23.0 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		tokio-1.47.1 \
		tokio-macros-2.5.0 \
		tracing-0.1.41 \
		tracing-core-0.1.34 \
		unicode-ident-1.0.19 \
		ureq-3.1.2 \
		ureq-proto-0.5.2 \
		utf-8-0.7.6 \
		utf8parse-0.2.2 \
		vcpkg-0.2.15 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasi-0.14.7+wasi-0.2.4 \
		wasip2-1.0.1+wasi-0.2.4 \
		webpki-root-certs-1.0.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.0 \
		windows-sys-0.59.0 \
		windows-sys-0.60.2 \
		windows-sys-0.61.1 \
		windows-targets-0.52.6 \
		windows-targets-0.53.4 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_gnullvm-0.53.0 \
		windows_aarch64_msvc-0.52.6 \
		windows_aarch64_msvc-0.53.0 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnu-0.53.0 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_gnullvm-0.53.0 \
		windows_i686_msvc-0.52.6 \
		windows_i686_msvc-0.53.0 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnu-0.53.0 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_gnullvm-0.53.0 \
		windows_x86_64_msvc-0.52.6 \
		windows_x86_64_msvc-0.53.0 \
		wit-bindgen-0.46.0 \
		zeroize-1.8.2

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

MAKE_ENV+=	ORT_STRATEGY=compile \
		ORT_LIB_PATH=${LOCALBASE}/lib \
		ORT_PREFER_DYNAMIC_LINK=1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
