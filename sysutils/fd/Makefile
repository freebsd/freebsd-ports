PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	8.5.3
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-find

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Simple, fast and user-friendly alternative to find
WWW=		https://github.com/sharkdp/fd

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	aho-corasick-0.7.19 \
		android_system_properties-0.1.5 \
		ansi_term-0.12.1 \
		anyhow-1.0.66 \
		argmax-0.3.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.11.1 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.22 \
		clap-4.0.22 \
		clap_complete-4.0.5 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		codespan-reporting-0.11.1 \
		core-foundation-sys-0.8.3 \
		crossbeam-channel-0.5.6 \
		crossbeam-utils-0.8.12 \
		ctrlc-3.2.3 \
		cxx-1.0.80 \
		cxx-build-1.0.80 \
		cxxbridge-flags-1.0.80 \
		cxxbridge-macro-1.0.80 \
		diff-0.1.13 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		faccess-0.2.4 \
		filetime-0.2.18 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.2.8 \
		globset-0.4.9 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		iana-time-zone-0.1.51 \
		iana-time-zone-haiku-0.1.1 \
		ignore-0.4.18 \
		io-lifetimes-0.7.4 \
		jemalloc-sys-0.5.2+5.3.0-patched \
		jemallocator-0.5.0 \
		js-sys-0.3.60 \
		lazy_static-1.4.0 \
		libc-0.2.136 \
		link-cplusplus-1.0.7 \
		linux-raw-sys-0.0.46 \
		log-0.4.17 \
		lscolors-0.12.0 \
		memchr-2.5.0 \
		nix-0.24.2 \
		nix-0.25.0 \
		normpath-0.3.2 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		rustix-0.35.12 \
		same-file-1.0.6 \
		scratch-1.0.2 \
		strsim-0.10.0 \
		syn-1.0.103 \
		tempdir-0.3.7 \
		termcolor-1.1.3 \
		terminal_size-0.2.1 \
		test-case-2.2.2 \
		test-case-macros-2.2.2 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		thread_local-1.1.4 \
		time-0.1.44 \
		unicode-ident-1.0.5 \
		unicode-width-0.1.10 \
		users-0.11.0 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.36.1 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.36.1 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.36.1 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.36.1 \
		windows_x86_64_msvc-0.42.0

CONFLICTS_INSTALL=	fd

PLIST_FILES=	bin/fd \
		etc/bash_completion.d/fd.bash \
		share/fish/completions/fd.fish \
		share/man/man1/fd.1.gz \
		share/zsh/site-functions/_fd

post-build:
	${MKDIR} ${WRKSRC}/autocomplete
	${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/fd --gen-completions bash > ${WRKSRC}/autocomplete/fd.bash
	${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/fd --gen-completions fish > ${WRKSRC}/autocomplete/fd.fish

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fd
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/autocomplete/fd.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/autocomplete/fd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/_fd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
