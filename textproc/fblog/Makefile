PORTNAME=	fblog
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8.0
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small command-line JSON Log viewer
WWW=		https://github.com/brocode/fblog

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	brocode

CARGO_CRATES=	aho-corasick-1.1.2 \
		anstream-0.6.4 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.2 \
		anstyle-query-1.0.0 \
		anstyle-wincon-3.0.1 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		block-buffer-0.10.4 \
		bstr-1.8.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		clap-4.4.10 \
		clap_builder-4.4.9 \
		clap_complete-4.4.4 \
		clap_derive-4.4.7 \
		clap_lex-0.6.0 \
		colorchoice-1.0.0 \
		cpufeatures-0.2.11 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		either-1.9.0 \
		equivalent-1.0.1 \
		errno-0.3.7 \
		generic-array-0.14.7 \
		getrandom-0.2.11 \
		handlebars-4.5.0 \
		hashbrown-0.14.3 \
		heck-0.4.1 \
		home-0.5.5 \
		indexmap-2.1.0 \
		itoa-1.0.9 \
		lazy_static-1.4.0 \
		libc-0.2.150 \
		libredox-0.0.1 \
		linux-raw-sys-0.4.11 \
		log-0.4.20 \
		lua-src-546.0.1 \
		luajit-src-210.5.2+113a168 \
		memchr-2.6.4 \
		mlua-0.9.2 \
		mlua-sys-0.4.0 \
		num-traits-0.2.17 \
		once_cell-1.18.0 \
		option-ext-0.2.0 \
		pest-2.7.5 \
		pest_derive-2.7.5 \
		pest_generator-2.7.5 \
		pest_meta-2.7.5 \
		pkg-config-0.3.27 \
		proc-macro2-1.0.69 \
		quote-1.0.33 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.10.2 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		rustc-hash-1.1.0 \
		rustix-0.38.25 \
		ryu-1.0.15 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_json-1.0.108 \
		serde_spanned-0.6.4 \
		sha2-0.10.8 \
		strsim-0.10.0 \
		syn-2.0.39 \
		thiserror-1.0.50 \
		thiserror-impl-1.0.50 \
		toml-0.8.8 \
		toml_datetime-0.6.5 \
		toml_edit-0.21.0 \
		typenum-1.17.0 \
		ucd-trie-0.1.6 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-5.0.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		winnow-0.5.19 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
