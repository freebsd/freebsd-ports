PORTNAME=	rust-coreutils
DISTVERSION=	0.0.23
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
WWW=		https://crates.io/crates/coreutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	uutils
GH_PROJECT=	coreutils

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-1.0.4 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.5.0 \
		anstyle-1.0.0 \
		anstyle-parse-0.2.0 \
		anstyle-query-1.0.0 \
		anstyle-wincon-2.1.0 \
		arrayref-0.3.6 \
		arrayvec-0.7.4 \
		autocfg-1.1.0 \
		bigdecimal-0.4.0 \
		binary-heap-plus-0.5.0 \
		bindgen-0.63.0 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		blake2b_simd-1.0.2 \
		blake3-1.5.0 \
		block-buffer-0.10.3 \
		bstr-1.8.0 \
		bumpalo-3.11.1 \
		bytecount-0.6.7 \
		byteorder-1.5.0 \
		cc-1.0.79 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chrono-0.4.31 \
		clang-sys-1.4.0 \
		clap-4.4.2 \
		clap_builder-4.4.2 \
		clap_complete-4.4.0 \
		clap_lex-0.5.0 \
		clap_mangen-0.2.9 \
		colorchoice-1.0.0 \
		compare-0.1.0 \
		console-0.15.7 \
		const-random-0.1.16 \
		const-random-macro-0.1.16 \
		constant_time_eq-0.3.0 \
		conv-0.3.3 \
		core-foundation-sys-0.8.3 \
		coz-0.1.3 \
		cpp-0.5.9 \
		cpp_build-0.5.9 \
		cpp_common-0.5.9 \
		cpp_macros-0.5.9 \
		cpufeatures-0.2.5 \
		crc32fast-1.3.2 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.2 \
		crossbeam-epoch-0.9.14 \
		crossbeam-utils-0.8.15 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		crunchy-0.2.2 \
		crypto-common-0.1.6 \
		ctrlc-3.4.1 \
		custom_derive-0.1.7 \
		data-encoding-2.4.0 \
		data-encoding-macro-0.1.13 \
		data-encoding-macro-internal-0.1.11 \
		diff-0.1.13 \
		digest-0.10.7 \
		dlv-list-0.5.0 \
		dns-lookup-2.0.4 \
		dunce-1.0.4 \
		either-1.8.0 \
		encode_unicode-0.3.6 \
		env_logger-0.8.4 \
		errno-0.3.5 \
		exacl-0.11.0 \
		fastrand-2.0.0 \
		file_diff-1.0.0 \
		filetime-0.2.22 \
		flate2-1.0.24 \
		fnv-1.0.7 \
		fs_extra-1.3.0 \
		fsevent-sys-4.1.0 \
		fts-sys-0.2.4 \
		fundu-2.0.0 \
		fundu-core-0.3.0 \
		futures-0.3.28 \
		futures-channel-0.3.28 \
		futures-core-0.3.28 \
		futures-executor-0.3.28 \
		futures-io-0.3.28 \
		futures-macro-0.3.28 \
		futures-sink-0.3.28 \
		futures-task-0.3.28 \
		futures-timer-3.0.2 \
		futures-util-0.3.28 \
		gcd-2.3.0 \
		generic-array-0.14.6 \
		getrandom-0.2.9 \
		glob-0.3.1 \
		half-2.3.1 \
		hashbrown-0.13.2 \
		hermit-abi-0.3.2 \
		hex-0.4.3 \
		hex-literal-0.4.1 \
		hostname-0.3.1 \
		iana-time-zone-0.1.53 \
		iana-time-zone-haiku-0.1.2 \
		indicatif-0.17.3 \
		inotify-0.9.6 \
		inotify-sys-0.1.5 \
		io-lifetimes-1.0.11 \
		itertools-0.11.0 \
		itoa-1.0.4 \
		js-sys-0.3.64 \
		keccak-0.1.4 \
		kqueue-1.0.7 \
		kqueue-sys-1.0.3 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.150 \
		libloading-0.7.4 \
		libm-0.2.7 \
		linux-raw-sys-0.3.8 \
		linux-raw-sys-0.4.10 \
		lock_api-0.4.9 \
		log-0.4.17 \
		lscolors-0.15.0 \
		match_cfg-0.1.0 \
		md-5-0.10.6 \
		memchr-2.6.2 \
		memmap2-0.9.0 \
		memoffset-0.8.0 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.5.4 \
		mio-0.8.6 \
		nix-0.27.1 \
		nom-7.1.3 \
		notify-6.0.1 \
		nu-ansi-term-0.49.0 \
		num-bigint-0.4.4 \
		num-integer-0.1.45 \
		num-traits-0.2.17 \
		num_threads-0.1.6 \
		number_prefix-0.4.0 \
		once_cell-1.18.0 \
		onig-6.4.0 \
		onig_sys-69.8.1 \
		ordered-multimap-0.6.0 \
		os_display-0.1.3 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		parse_datetime-0.5.0 \
		peeking_take_while-0.1.2 \
		phf-0.11.2 \
		phf_codegen-0.11.2 \
		phf_generator-0.11.1 \
		phf_shared-0.11.2 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		pkg-config-0.3.26 \
		platform-info-2.0.2 \
		portable-atomic-0.3.15 \
		ppv-lite86-0.2.17 \
		pretty_assertions-1.4.0 \
		proc-macro2-1.0.63 \
		procfs-0.16.0 \
		procfs-core-0.16.0 \
		quick-error-2.0.1 \
		quickcheck-1.0.3 \
		quote-1.0.29 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rand_pcg-0.3.1 \
		rayon-1.8.0 \
		rayon-core-1.12.0 \
		redox_syscall-0.3.5 \
		redox_syscall-0.4.0 \
		reference-counted-singleton-0.1.2 \
		regex-1.10.2 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		relative-path-1.8.0 \
		rlimit-0.10.1 \
		roff-0.2.1 \
		rstest-0.18.2 \
		rstest_macros-0.18.2 \
		rust-ini-0.19.0 \
		rustc-hash-1.1.0 \
		rustc_version-0.4.0 \
		rustix-0.37.26 \
		rustix-0.38.21 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		self_cell-1.0.2 \
		selinux-0.4.0 \
		selinux-sys-0.6.2 \
		semver-1.0.14 \
		serde-1.0.147 \
		sha1-0.10.6 \
		sha2-0.10.8 \
		sha3-0.10.8 \
		shlex-1.1.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		siphasher-0.3.10 \
		slab-0.4.7 \
		sm3-0.4.2 \
		smallvec-1.11.0 \
		smawk-0.3.1 \
		socket2-0.5.3 \
		strsim-0.10.0 \
		syn-1.0.109 \
		syn-2.0.23 \
		tempfile-3.8.1 \
		terminal_size-0.2.6 \
		terminal_size-0.3.0 \
		textwrap-0.16.0 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		time-0.3.20 \
		time-core-0.1.0 \
		time-macros-0.2.8 \
		tiny-keccak-2.0.2 \
		typenum-1.15.0 \
		unicode-ident-1.0.5 \
		unicode-linebreak-0.1.5 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.11 \
		unicode-xid-0.2.4 \
		unindent-0.2.1 \
		utf8parse-0.2.1 \
		uuid-1.2.2 \
		uutils_term_grid-0.3.0 \
		version_check-0.9.4 \
		walkdir-2.4.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		which-4.3.0 \
		wild-2.2.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-targets-0.42.2 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.0 \
		xattr-1.0.1 \
		yansi-0.5.1 \
		z85-3.0.5 \
		zip-0.6.6

CARGO_FEATURES=	unix
BINPREFIX=	uu-
PLIST_SUB=	BINPREFIX=${BINPREFIX}

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/symlink-install-helper.sh.in ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%GREP%%|${GREP}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%CARGO_TARGET_DIR%%|${CARGO_TARGET_DIR}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%CARGO_BUILD_TARGET%%|${CARGO_BUILD_TARGET}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%SED%%|${SED}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%TR%%|${TR}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%RLN%%|${RLN}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%STAGEDIR%%|${STAGEDIR}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%BINPREFIX%%|${BINPREFIX}|g' \
		${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/coreutils \
		${STAGEDIR}${PREFIX}/bin/${BINPREFIX}coreutils
	${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/symlink-install-helper.sh

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${BINPREFIX}coreutils

.include <bsd.port.mk>
