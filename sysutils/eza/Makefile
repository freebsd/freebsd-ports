PORTNAME=	eza
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	sysutils

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Modern, maintained replacement for ls
WWW=		https://eza.rocks/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eza-community

OPTIONS_DEFINE=	MANPAGES

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

CARGO_CRATES=	aho-corasick-1.0.5 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anes-0.1.6 \
		ansi_colours-1.2.2 \
		ansiterm-0.12.2 \
		anstream-0.6.4 \
		anstyle-1.0.3 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-3.0.1 \
		approx-0.5.1 \
		autocfg-1.1.0 \
		base64-0.21.5 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		bumpalo-3.13.0 \
		byteorder-1.4.3 \
		cast-0.3.0 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chrono-0.4.31 \
		ciborium-0.2.1 \
		ciborium-io-0.2.1 \
		ciborium-ll-0.2.1 \
		clap-4.4.3 \
		clap_builder-4.4.2 \
		clap_lex-0.5.1 \
		colorchoice-1.0.0 \
		content_inspector-0.2.4 \
		core-foundation-sys-0.8.4 \
		criterion-0.5.1 \
		criterion-plot-0.5.0 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		datetime-0.5.2 \
		deranged-0.3.9 \
		dunce-1.0.4 \
		either-1.9.0 \
		equivalent-1.0.1 \
		errno-0.3.3 \
		errno-dragonfly-0.1.2 \
		fast-srgb8-1.0.0 \
		fastrand-2.0.0 \
		filetime-0.2.22 \
		form_urlencoded-1.0.1 \
		git2-0.18.1 \
		glob-0.3.1 \
		half-1.8.2 \
		hashbrown-0.14.2 \
		hermit-abi-0.3.2 \
		humantime-2.1.0 \
		humantime-serde-1.1.1 \
		iana-time-zone-0.1.57 \
		iana-time-zone-haiku-0.1.2 \
		idna-0.2.3 \
		indexmap-2.1.0 \
		is-terminal-0.4.9 \
		itertools-0.10.5 \
		itoa-1.0.9 \
		jobserver-0.1.22 \
		js-sys-0.3.64 \
		libc-0.2.151 \
		libgit2-sys-0.16.1+1.7.1 \
		libz-sys-1.1.2 \
		line-wrap-0.1.1 \
		linux-raw-sys-0.4.11 \
		locale-0.2.2 \
		log-0.4.20 \
		matches-0.1.8 \
		memchr-2.6.3 \
		memoffset-0.9.0 \
		natord-1.0.9 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.14 \
		num_cpus-1.16.0 \
		number_prefix-0.4.0 \
		once_cell-1.19.0 \
		oorandom-11.1.3 \
		openssl-src-111.26.0+1.1.1u \
		openssl-sys-0.9.61 \
		os_pipe-1.1.4 \
		palette-0.7.3 \
		palette_derive-0.7.3 \
		partition-identity-0.3.0 \
		percent-encoding-2.3.1 \
		phf-0.11.2 \
		phf_generator-0.11.2 \
		phf_macros-0.11.2 \
		phf_shared-0.11.2 \
		pkg-config-0.3.19 \
		plist-1.6.0 \
		plotters-0.3.5 \
		plotters-backend-0.3.5 \
		plotters-svg-0.3.5 \
		powerfmt-0.2.0 \
		proc-macro2-1.0.66 \
		proc-mounts-0.3.0 \
		quick-xml-0.31.0 \
		quote-1.0.33 \
		rand-0.8.5 \
		rand_core-0.6.4 \
		rayon-1.7.0 \
		rayon-core-1.11.0 \
		redox_syscall-0.1.57 \
		redox_syscall-0.3.5 \
		regex-1.9.5 \
		regex-automata-0.3.8 \
		regex-syntax-0.7.5 \
		rustix-0.38.21 \
		ryu-1.0.15 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.2.0 \
		serde-1.0.188 \
		serde_derive-1.0.188 \
		serde_json-1.0.107 \
		serde_spanned-0.6.3 \
		shlex-1.2.0 \
		similar-2.2.1 \
		siphasher-0.3.11 \
		snapbox-0.4.14 \
		snapbox-macros-0.3.6 \
		syn-2.0.29 \
		tempfile-3.8.0 \
		terminal_size-0.3.0 \
		thiserror-1.0.48 \
		thiserror-impl-1.0.48 \
		time-0.3.30 \
		time-core-0.1.2 \
		time-macros-0.2.15 \
		timeago-0.4.2 \
		tinytemplate-1.2.1 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		toml_datetime-0.6.3 \
		toml_edit-0.20.1 \
		trycmd-0.14.19 \
		unicode-bidi-0.3.5 \
		unicode-ident-1.0.11 \
		unicode-normalization-0.1.17 \
		unicode-width-0.1.11 \
		url-2.2.1 \
		utf8parse-0.2.1 \
		uutils_term_grid-0.3.0 \
		uzers-0.11.3 \
		vcpkg-0.2.12 \
		wait-timeout-0.2.0 \
		walkdir-2.4.0 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		web-sys-0.3.64 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.0 \
		winnow-0.5.15 \
		zoneinfo_compiled-0.5.1

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

_MARKDOWN_FILES=	eza.1 eza_colors-explanation.5 eza_colors.5
.for i in ${_MARKDOWN_FILES}
MANPAGES_PLIST_FILES+=	share/man/man${i:C/.*\.//}/${i}.gz
.endfor

post-build-MANPAGES-on:
.for i in ${_MARKDOWN_FILES}
	cd ${WRKSRC}/man && \
		pandoc ${i}.md -s -t man > ${i}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/bash/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/fish/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-MANPAGES-on:
.for i in ${_MARKDOWN_FILES}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${STAGEDIR}${MANPREFIX}/share/man/man${i:C/.*\.//}
.endfor

.include <bsd.port.mk>
