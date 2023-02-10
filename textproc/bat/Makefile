PORTNAME=	bat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.1
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Clone of cat with syntax highlighting
WWW=		https://github.com/sharkdp/bat

LICENSE=	APACHE20

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma

USES=		cargo cpe
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/bat \
		share/zsh/site-functions/_bat \
		man/man1/bat.1.gz

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.18 \
		ansi_colours-1.1.1 \
		ansi_term-0.12.1 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bincode-1.3.3 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bugreport-0.5.0 \
		bytemuck-1.7.3 \
		bytesize-1.1.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		clap-3.2.20 \
		clap_lex-0.2.4 \
		clircle-0.3.0 \
		console-0.15.1 \
		content_inspector-0.2.4 \
		crc32fast-1.3.0 \
		difflib-0.4.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		encode_unicode-0.3.6 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		fancy-regex-0.7.1 \
		fastrand-1.7.0 \
		flate2-1.0.24 \
		float-cmp-0.9.0 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		git-version-0.3.5 \
		git-version-macro-0.3.5 \
		git2-0.15.0 \
		glob-0.3.0 \
		globset-0.4.9 \
		grep-cli-0.1.6 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indexmap-1.7.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		jobserver-0.1.24 \
		lazy_static-1.4.0 \
		libc-0.2.125 \
		libgit2-sys-0.14.0+1.5.0 \
		libz-sys-1.1.3 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.4 \
		lock_api-0.4.5 \
		log-0.4.14 \
		matches-0.1.9 \
		memchr-2.4.1 \
		miniz_oxide-0.5.1 \
		nix-0.24.2 \
		normalize-line-endings-0.3.0 \
		num-traits-0.2.14 \
		once_cell-1.13.1 \
		onig-6.3.1 \
		onig_sys-69.7.1 \
		os_str_bytes-6.3.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		path_abs-0.5.1 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.24 \
		plist-1.3.1 \
		predicates-2.1.1 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.4 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.39 \
		quote-1.0.14 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.6.0 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		rgb-0.8.31 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-1.0.13 \
		serde-1.0.144 \
		serde_derive-1.0.144 \
		serde_json-1.0.74 \
		serde_yaml-0.8.24 \
		serial_test-0.6.0 \
		serial_test_derive-0.6.0 \
		shell-escape-0.1.5 \
		shell-words-1.1.0 \
		smallvec-1.7.0 \
		std_prelude-0.2.12 \
		strsim-0.10.0 \
		syn-1.0.95 \
		syntect-5.0.0 \
		sys-info-0.9.1 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		termtree-0.2.3 \
		textwrap-0.15.0 \
		thiserror-1.0.33 \
		thiserror-impl-1.0.33 \
		time-0.3.5 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.7 \
		unicode-ident-1.0.0 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.9 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wild-2.1.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.8.4 \
		yaml-rust-0.4.5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bat
	${FIND} ${WRKDIR}/target -name "bat.1" -exec ${CP} {} ${WRKSRC}/doc/bat.1 \;
	${FIND} ${WRKDIR}/target -name "bat.zsh" -exec ${CP} {} ${WRKSRC}/doc/bat.zsh \;
	${INSTALL_MAN} ${WRKSRC}/doc/bat.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/doc/bat.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_bat

.include <bsd.port.mk>
