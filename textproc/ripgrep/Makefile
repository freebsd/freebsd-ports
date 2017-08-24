# Created by: Petteri Valkonen <petteri.valkonen@iki.fi>
# $FreeBSD$

# vim: ts=8 noet

PORTNAME=	ripgrep
PORTVERSION=	0.6.0
CATEGORIES=	textproc

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command line search tool

LICENSE=	MIT UNLICENSE
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	BurntSushi

OPTIONS_DEFINE=	BASH FISH ZSH
OPTIONS_DEFAULT=BASH FISH ZSH
FISH_DESC=	Install programmable completions for Fish

PLIST_FILES=	bin/rg \
		man/man1/rg.1.gz
BASH_PLIST_FILES=	etc/bash_completion.d/rg.bash-completion
FISH_PLIST_FILES=	share/fish/completions/rg.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_rg

CARGO_CRATES=	aho-corasick-0.6.3 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.9.1 \
		bytecount-0.1.7 \
		cfg-if-0.1.2 \
		clap-2.26.0 \
		crossbeam-0.2.10 \
		encoding_rs-0.6.11 \
		env_logger-0.4.3 \
		fnv-1.0.5 \
		fs2-0.4.2 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.29 \
		log-0.3.8 \
		memchr-1.0.1 \
		memmap-0.5.2 \
		num_cpus-1.6.2 \
		regex-0.2.2 \
		regex-syntax-0.4.1 \
		same-file-0.1.3 \
		simd-0.1.1 \
		simd-0.2.0 \
		strsim-0.6.0 \
		term_size-0.3.0 \
		textwrap-0.7.0 \
		thread_local-0.3.4 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		walkdir-1.0.7 \
		winapi-0.2.8 \
		winapi-build-0.1.1

RIPGREP_OUTDIR=	${WRKDIR}/cargo-out
CARGO_ENV=	RIPGREP_OUTDIR=${RIPGREP_OUTDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|OUT_DIR|RIPGREP_OUTDIR|' ${WRKSRC}/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rg
	${INSTALL_MAN} ${WRKSRC}/doc/rg.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${RIPGREP_OUTDIR}/rg.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${RIPGREP_OUTDIR}/rg.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/complete/_rg \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
