PORTNAME=	systeroid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	More powerful alternative to sysctl(8) with a terminal user interface
WWW=		https://systeroid.cli.rs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	orhun

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.20 \
		aho-corasick-1.0.2 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.3.3 \
		block-0.1.6 \
		bstr-1.5.0 \
		bumpalo-3.13.0 \
		byteorder-1.4.3 \
		cassowary-0.3.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chrono-0.4.26 \
		clipboard-win-3.1.1 \
		const-random-0.1.15 \
		const-random-macro-0.1.15 \
		copypasta-0.8.2 \
		copypasta-ext-0.4.4 \
		core-foundation-sys-0.8.4 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		crunchy-0.2.2 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		dlib-0.5.2 \
		dlv-list-0.5.0 \
		downcast-rs-1.2.0 \
		either-1.8.1 \
		enum-as-inner-0.5.1 \
		env_logger-0.10.0 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		flate2-1.0.26 \
		fnv-1.0.7 \
		fxhash-0.2.1 \
		gethostname-0.2.3 \
		getopts-0.2.21 \
		getrandom-0.2.10 \
		globset-0.4.10 \
		globwalk-0.8.1 \
		hashbrown-0.13.2 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		hermit-abi-0.3.1 \
		humantime-2.1.0 \
		iana-time-zone-0.1.57 \
		iana-time-zone-haiku-0.1.2 \
		ignore-0.4.20 \
		indoc-2.0.3 \
		io-lifetimes-1.0.11 \
		is-terminal-0.4.7 \
		is_ci-1.1.1 \
		itertools-0.11.0 \
		itoa-1.0.6 \
		js-sys-0.3.64 \
		lazy-bytes-cast-5.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.146 \
		libloading-0.8.0 \
		linux-raw-sys-0.3.8 \
		lock_api-0.4.10 \
		log-0.4.20 \
		malloc_buf-0.0.6 \
		memchr-2.5.0 \
		memmap2-0.5.10 \
		memoffset-0.6.5 \
		memoffset-0.9.0 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.7.1 \
		nix-0.24.3 \
		nom-7.1.3 \
		num-traits-0.2.15 \
		num_cpus-1.15.0 \
		numtoa-0.1.0 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		once_cell-1.18.0 \
		ordered-multimap-0.6.0 \
		owo-colors-3.5.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		parseit-0.1.2 \
		paste-1.0.14 \
		pkg-config-0.3.27 \
		proc-macro-hack-0.5.20+deprecated \
		proc-macro2-1.0.63 \
		quote-1.0.29 \
		ratatui-0.23.0 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		redox_syscall-0.2.16 \
		redox_syscall-0.3.5 \
		redox_termios-0.1.2 \
		redox_users-0.4.3 \
		regex-1.8.4 \
		regex-syntax-0.7.2 \
		rust-ini-0.19.0 \
		rustix-0.37.20 \
		rustversion-1.0.14 \
		ryu-1.0.13 \
		same-file-1.0.6 \
		scoped-tls-1.0.1 \
		scopeguard-1.1.0 \
		serde-1.0.188 \
		serde_derive-1.0.188 \
		serde_json-1.0.107 \
		smallvec-1.10.0 \
		smithay-client-toolkit-0.16.0 \
		smithay-clipboard-0.6.6 \
		strum-0.25.0 \
		strum_macros-0.25.2 \
		supports-color-1.3.1 \
		syn-1.0.109 \
		syn-2.0.28 \
		sysctl-0.5.4 \
		termcolor-1.2.0 \
		termion-2.0.1 \
		thiserror-1.0.48 \
		thiserror-impl-1.0.48 \
		thread_local-1.1.7 \
		tiny-keccak-2.0.2 \
		tui-logger-0.9.6 \
		unicode-ident-1.0.9 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.10 \
		walkdir-2.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		wayland-client-0.29.5 \
		wayland-commons-0.29.5 \
		wayland-cursor-0.29.5 \
		wayland-protocols-0.29.5 \
		wayland-scanner-0.29.5 \
		wayland-sys-0.29.5 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-wsapoll-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.48.0 \
		x11-clipboard-0.7.1 \
		x11rb-0.10.1 \
		x11rb-protocol-0.10.0 \
		xcursor-0.3.4 \
		xml-rs-0.8.14

PROGS=		${PORTNAME} \
		${PORTNAME}-tui

PLIST_FILES=	${PROGS:S/^/bin\//}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
.for p in ${PROGS}
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/*/release/${p} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
