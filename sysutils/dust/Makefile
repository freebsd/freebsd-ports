PORTNAME=	dust
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	kfv@kfv.io
COMMENT=	More intuitive version of du

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bootandy

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		assert_cmd-1.0.8 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		cfg-if-1.0.0 \
		clap-3.1.2 \
		crossbeam-channel-0.5.2 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.7 \
		crossbeam-utils-0.8.7 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		fastrand-1.7.0 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		itertools-0.10.3 \
		lazy_static-1.4.0 \
		libc-0.2.119 \
		lscolors-0.7.1 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		num_cpus-1.13.1 \
		os_str_bytes-6.0.0 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.10 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		scopeguard-1.1.0 \
		stfu8-0.2.5 \
		strsim-0.10.0 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		termtree-0.2.4 \
		textwrap-0.14.2 \
		thousands-0.2.0 \
		unicode-width-0.1.9 \
		wait-timeout-0.2.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
