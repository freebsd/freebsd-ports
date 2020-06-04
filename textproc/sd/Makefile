# $FreeBSD$

PORTNAME=	sd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Intuitive find and replace tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmln

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		anyhow-1.0.28 \
		assert_cmd-1.0.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		either-1.5.3 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.11 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		man-0.3.0 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memmap-0.7.0 \
		memoffset-0.5.4 \
		num_cpus-1.13.0 \
		ppv-lite86-0.2.6 \
		predicates-1.0.4 \
		predicates-core-1.0.0 \
		predicates-tree-1.0.0 \
		proc-macro-error-1.0.2 \
		proc-macro-error-attr-1.0.2 \
		proc-macro2-1.0.10 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		redox_syscall-0.1.56 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		roff-0.1.0 \
		scopeguard-1.1.0 \
		strsim-0.8.0 \
		structopt-0.3.14 \
		structopt-derive-0.4.7 \
		syn-1.0.17 \
		syn-mid-0.5.0 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.15 \
		thiserror-impl-1.0.15 \
		thread_local-1.0.1 \
		treeline-0.1.0 \
		unescape-0.1.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		wait-timeout-0.2.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

_SD_OUT_DIR=	${WRKDIR}/cargo-out
MAKE_ENV=	SD_OUT_DIR=${_SD_OUT_DIR}
PLIST_FILES=	bin/sd \
		etc/bash_completion.d/sd.bash \
		man/man1/sd.1.gz \
		share/fish/completions/sd.fish \
		share/zsh/site-functions/_sd
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's,"OUT_DIR","SD_OUT_DIR",g' ${WRKSRC}/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sd
	${INSTALL_MAN} ${_SD_OUT_DIR}/sd.1 \
		${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${_SD_OUT_DIR}/sd.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${_SD_OUT_DIR}/sd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${_SD_OUT_DIR}/_sd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
