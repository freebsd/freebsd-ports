PORTNAME=	handlr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
PORTREVISION=	31
CATEGORIES=	sysutils

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Manage mimeapps.list and default applications with ease
WWW=		https://github.com/Anomalocaridid/handlr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Anomalocaridid
GH_PROJECT=	${PORTNAME}-regex

CARGO_CRATES=	aho-corasick-0.7.18 \
		arrayvec-0.5.2 \
		ascii_table-3.0.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		bumpalo-3.9.1 \
		byte-tools-0.3.1 \
		byteorder-1.4.3 \
		bytes-1.1.0 \
		cc-1.0.73 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-3.1.1 \
		clap_derive-3.1.0 \
		confy-0.4.0 \
		core-foundation-0.9.3 \
		core-foundation-sys-0.8.3 \
		digest-0.8.1 \
		directories-2.0.2 \
		dirs-4.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.6 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		encoding_rs-0.8.30 \
		fake-simd-0.1.2 \
		fastrand-1.7.0 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.1 \
		freedesktop_entry_parser-1.3.0 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		generic-array-0.12.4 \
		getrandom-0.2.5 \
		glob-0.3.0 \
		h2-0.3.11 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		http-0.2.6 \
		http-body-0.4.4 \
		httparse-1.6.0 \
		httpdate-1.0.2 \
		hyper-0.14.17 \
		hyper-tls-0.5.0 \
		idna-0.2.3 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		ipnet-2.3.1 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		json-0.12.4 \
		lazy_static-1.4.0 \
		lexical-core-0.7.6 \
		libc-0.2.119 \
		log-0.4.14 \
		maplit-1.0.2 \
		matches-0.1.9 \
		memchr-2.4.1 \
		mime-0.3.16 \
		mime-db-1.6.0 \
		minimal-lexical-0.2.1 \
		mio-0.8.0 \
		miow-0.3.7 \
		native-tls-0.2.8 \
		nom-5.1.2 \
		nom-7.1.0 \
		ntapi-0.3.7 \
		once_cell-1.9.0 \
		opaque-debug-0.2.3 \
		openssl-0.10.38 \
		openssl-probe-0.1.5 \
		openssl-sys-0.9.72 \
		os_str_bytes-6.0.0 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		pest_derive-2.1.0 \
		pest_generator-2.1.3 \
		pest_meta-2.1.3 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		pkg-config-0.3.24 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		reqwest-0.11.9 \
		ryu-1.0.9 \
		schannel-0.1.19 \
		security-framework-2.6.1 \
		security-framework-sys-2.6.1 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		serde_urlencoded-0.7.1 \
		sha-1-0.8.2 \
		shlex-1.1.0 \
		slab-0.4.5 \
		socket2-0.4.4 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.86 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		textwrap-0.14.2 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.17.0 \
		tokio-macros-1.7.0 \
		tokio-native-tls-0.3.0 \
		tokio-util-0.6.9 \
		toml-0.5.8 \
		tower-service-0.3.1 \
		tracing-0.1.31 \
		tracing-core-0.1.22 \
		try-lock-0.2.3 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		unicase-2.6.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		want-0.3.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-futures-0.4.29 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		xdg-2.4.1 \
		xdg-mime-0.3.3

PLIST_FILES=	bin/handlr

OPTIONS_DEFINE=		COMPLETIONS
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=	Install bash, zsh, and fish shell completions

COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install-COMPLETIONS-on:
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
