PORTNAME=	mcfly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION=	1
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
		bstr-0.2.17 \
		bumpalo-3.11.1 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		chrono-0.4.23 \
		clap-4.0.29 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		codespan-reporting-0.11.1 \
		core-foundation-sys-0.8.3 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		cxx-1.0.83 \
		cxx-build-1.0.83 \
		cxxbridge-flags-1.0.83 \
		cxxbridge-macro-1.0.83 \
		directories-next-2.0.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		either-1.8.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		hashlink-0.8.1 \
		heck-0.4.0 \
		hermit-abi-0.2.6 \
		humantime-2.1.0 \
		iana-time-zone-0.1.53 \
		iana-time-zone-haiku-0.1.1 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.1 \
		itertools-0.10.5 \
		itoa-0.4.8 \
		js-sys-0.3.60 \
		lazy_static-1.4.0 \
		libc-0.2.138 \
		libsqlite3-sys-0.25.2 \
		link-cplusplus-1.0.7 \
		linux-raw-sys-0.1.4 \
		log-0.4.17 \
		memchr-2.5.0 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		numtoa-0.1.0 \
		once_cell-1.16.0 \
		os_str_bytes-6.4.1 \
		pkg-config-0.3.26 \
		ppv-lite86-0.2.17 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		quote-1.0.21 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		redox_termios-0.1.2 \
		redox_users-0.4.3 \
		regex-1.7.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		relative-path-1.7.2 \
		rusqlite-0.28.0 \
		rustix-0.36.5 \
		ryu-1.0.11 \
		scratch-1.0.2 \
		serde-1.0.150 \
		shellexpand-2.1.2 \
		smallvec-1.10.0 \
		strsim-0.10.0 \
		syn-1.0.105 \
		termcolor-1.1.3 \
		termion-1.5.6 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		time-0.1.45 \
		unicode-ident-1.0.5 \
		unicode-segmentation-1.10.0 \
		unicode-width-0.1.10 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
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
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0
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
