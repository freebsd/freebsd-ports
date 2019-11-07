# $FreeBSD$

PORTNAME=	sd
DISTVERSION=	0.6.5
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Intuitive find and replace tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmln

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		bitflags-1.0.4 \
		cfg-if-0.1.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		crossbeam-deque-0.6.3 \
		crossbeam-epoch-0.7.1 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.6.5 \
		either-1.5.2 \
		fuchsia-cprng-0.1.1 \
		heck-0.3.1 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		man-0.3.0 \
		memchr-2.2.0 \
		memmap-0.7.0 \
		memoffset-0.2.1 \
		nodrop-0.1.13 \
		num_cpus-1.10.0 \
		proc-macro2-0.4.27 \
		quote-0.6.11 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_xorshift-0.1.1 \
		rayon-1.1.0 \
		rayon-core-1.5.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.53 \
		redox_termios-0.1.1 \
		regex-1.1.7 \
		regex-syntax-0.6.6 \
		remove_dir_all-0.5.1 \
		roff-0.1.0 \
		scopeguard-0.3.3 \
		strsim-0.8.0 \
		structopt-0.2.16 \
		structopt-derive-0.2.16 \
		syn-0.15.30 \
		tempfile-3.0.8 \
		termion-1.5.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unescape-0.1.0 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		winapi-0.3.7 \
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
