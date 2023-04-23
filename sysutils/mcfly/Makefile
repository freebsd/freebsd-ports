PORTNAME=	mcfly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fly through your shell history
WWW=		https://github.com/cantino/mcfly

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	cantino

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.20 \
		android_system_properties-0.1.5 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bumpalo-3.12.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chrono-0.4.23 \
		clap-4.1.6 \
		clap_derive-4.1.0 \
		clap_lex-0.3.2 \
		codespan-reporting-0.11.1 \
		core-foundation-sys-0.8.3 \
		crossterm-0.26.0 \
		crossterm_winapi-0.9.0 \
		csv-1.2.0 \
		csv-core-0.1.10 \
		cxx-1.0.91 \
		cxx-build-1.0.91 \
		cxxbridge-flags-1.0.91 \
		cxxbridge-macro-1.0.91 \
		directories-next-2.0.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		either-1.8.1 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		filedescriptor-0.8.2 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		hashlink-0.8.1 \
		heck-0.4.1 \
		hermit-abi-0.3.1 \
		humantime-2.1.0 \
		iana-time-zone-0.1.53 \
		iana-time-zone-haiku-0.1.1 \
		io-lifetimes-1.0.5 \
		is-terminal-0.4.4 \
		itertools-0.10.5 \
		itoa-1.0.5 \
		js-sys-0.3.61 \
		libc-0.2.139 \
		libsqlite3-sys-0.25.2 \
		link-cplusplus-1.0.8 \
		linux-raw-sys-0.1.4 \
		lock_api-0.4.9 \
		log-0.4.17 \
		memchr-2.5.0 \
		mio-0.8.6 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		once_cell-1.17.1 \
		os_str_bytes-6.4.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.7 \
		pkg-config-0.3.26 \
		ppv-lite86-0.2.17 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.51 \
		quote-1.0.23 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.1 \
		regex-syntax-0.6.28 \
		relative-path-1.7.3 \
		rusqlite-0.28.0 \
		rustix-0.36.8 \
		ryu-1.0.12 \
		scopeguard-1.1.0 \
		scratch-1.0.3 \
		serde-1.0.152 \
		shellexpand-2.1.2 \
		signal-hook-0.3.15 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.10.0 \
		strsim-0.10.0 \
		syn-1.0.109 \
		termcolor-1.2.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		time-0.1.45 \
		unicode-ident-1.0.6 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.10 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.84 \
		wasm-bindgen-backend-0.2.84 \
		wasm-bindgen-macro-0.2.84 \
		wasm-bindgen-macro-support-0.2.84 \
		wasm-bindgen-shared-0.2.84 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.1 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1
PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install: # install shell completion files
	# strip
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mcfly
	# bash
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	# fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	# zsh
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
