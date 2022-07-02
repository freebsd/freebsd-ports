PORTNAME=	zoxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	12
CATEGORIES=	sysutils

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Fast cd alternative that learns your habits

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ajeetdsouza
CARGO_CRATES=	anyhow-1.0.40 \
		arrayvec-0.5.2 \
		askama-0.10.5 \
		askama_derive-0.10.5 \
		askama_escape-0.10.1 \
		askama_shared-0.11.1 \
		assert_cmd-1.0.3 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bincode-1.3.2 \
		bitflags-1.2.1 \
		bitvec-0.19.5 \
		bstr-0.2.15 \
		byteorder-1.3.4 \
		cfg-if-1.0.0 \
		clap-3.0.0-beta.2 \
		clap_derive-3.0.0-beta.2 \
		difference-2.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		dunce-1.0.1 \
		funty-1.1.0 \
		getrandom-0.1.16 \
		getrandom-0.2.2 \
		glob-0.3.0 \
		hashbrown-0.9.1 \
		heck-0.3.2 \
		hermit-abi-0.1.18 \
		indexmap-1.6.2 \
		lazy_static-1.4.0 \
		lexical-core-0.7.5 \
		libc-0.2.93 \
		memchr-2.3.4 \
		nom-6.1.2 \
		num-traits-0.2.14 \
		once_cell-1.7.2 \
		ordered-float-2.1.1 \
		os_str_bytes-2.4.0 \
		ppv-lite86-0.2.10 \
		predicates-1.0.7 \
		predicates-core-1.0.2 \
		predicates-tree-1.0.2 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.26 \
		quote-1.0.9 \
		radium-0.5.3 \
		rand-0.7.3 \
		rand-0.8.3 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.0 \
		rand_core-0.5.1 \
		rand_core-0.6.2 \
		rand_hc-0.2.0 \
		rand_hc-0.3.0 \
		redox_syscall-0.2.5 \
		redox_users-0.4.0 \
		regex-automata-0.1.9 \
		remove_dir_all-0.5.3 \
		ryu-1.0.5 \
		seq-macro-0.2.1 \
		serde-1.0.125 \
		serde_derive-1.0.125 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.69 \
		tap-1.0.1 \
		tempfile-3.2.0 \
		termcolor-1.1.2 \
		textwrap-0.12.1 \
		treeline-0.1.0 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0

PLIST_FILES=	bin/zoxide

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/zoxide

.include <bsd.port.mk>
