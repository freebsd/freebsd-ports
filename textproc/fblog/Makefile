PORTNAME=	fblog
DISTVERSIONPREFIX=	v
DISTVERSION=	4.9.0
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small command-line JSON Log viewer
WWW=		https://github.com/brocode/fblog

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	brocode

CARGO_CRATES=	aho-corasick-1.1.3 \
		anstream-0.6.13 \
		anstyle-1.0.6 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		autocfg-1.2.0 \
		bitflags-2.5.0 \
		block-buffer-0.10.4 \
		bstr-1.9.1 \
		cc-1.0.90 \
		cfg-if-1.0.0 \
		clap-4.5.4 \
		clap_builder-4.5.2 \
		clap_complete-4.5.1 \
		clap_derive-4.5.4 \
		clap_lex-0.7.0 \
		colorchoice-1.0.0 \
		cpufeatures-0.2.12 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		either-1.10.0 \
		equivalent-1.0.1 \
		errno-0.3.8 \
		generic-array-0.14.7 \
		getrandom-0.2.12 \
		handlebars-5.1.2 \
		hashbrown-0.14.3 \
		heck-0.5.0 \
		home-0.5.9 \
		indexmap-2.2.6 \
		itoa-1.0.11 \
		lazy_static-1.4.0 \
		libc-0.2.153 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.13 \
		log-0.4.21 \
		lua-src-546.0.2 \
		luajit-src-210.5.7+d06beb0 \
		memchr-2.7.2 \
		mlua-0.9.6 \
		mlua-sys-0.5.1 \
		num-traits-0.2.18 \
		once_cell-1.19.0 \
		option-ext-0.2.0 \
		pest-2.7.9 \
		pest_derive-2.7.9 \
		pest_generator-2.7.9 \
		pest_meta-2.7.9 \
		pkg-config-0.3.30 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		redox_users-0.4.5 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		rustc-hash-1.1.0 \
		rustix-0.38.32 \
		ryu-1.0.17 \
		serde-1.0.197 \
		serde_derive-1.0.197 \
		serde_json-1.0.115 \
		serde_spanned-0.6.5 \
		sha2-0.10.8 \
		strsim-0.11.1 \
		syn-2.0.58 \
		thiserror-1.0.58 \
		thiserror-impl-1.0.58 \
		toml-0.8.12 \
		toml_datetime-0.6.5 \
		toml_edit-0.22.9 \
		typenum-1.17.0 \
		ucd-trie-0.1.6 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-6.0.1 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.4 \
		winnow-0.6.5 \
		winsafe-0.0.19 \
		yansi-1.0.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
