# Created by: Petteri Valkonen <petteri.valkonen@iki.fi>
# $FreeBSD$

# vim: ts=8 noet

PORTNAME=	ripgrep
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command line search tool

LICENSE=	MIT UNLICENSE
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	BurntSushi

CARGO_CRATES=	aho-corasick-0.6.4 \
		ansi_term-0.10.2 \
		atty-0.2.6 \
		bitflags-1.0.1 \
		bytecount-0.3.1 \
		cfg-if-0.1.2 \
		clap-2.30.0 \
		crossbeam-0.3.2 \
		encoding_rs-0.7.2 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.2.11 \
		lazy_static-1.0.0 \
		libc-0.2.40 \
		log-0.4.1 \
		memchr-2.0.1 \
		memmap-0.6.2 \
		num_cpus-1.8.0 \
		rand-0.3.22 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		regex-0.2.6 \
		regex-syntax-0.4.2 \
		same-file-1.0.2 \
		simd-0.2.1 \
		strsim-0.7.0 \
		tempdir-0.3.5 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		unicode-width-0.1.4 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		void-1.0.2 \
		walkdir-2.1.4 \
		winapi-0.3.4 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

RIPGREP_OUTDIR=	${WRKDIR}/cargo-out
CARGO_ENV=	RIPGREP_OUTDIR=${RIPGREP_OUTDIR}

PLIST_FILES=	bin/rg \
		etc/bash_completion.d/rg.bash \
		man/man1/rg.1.gz \
		share/fish/completions/rg.fish \
		share/zsh/site-functions/_rg

PORTDOCS=	CHANGELOG.md FAQ.md GUIDE.md

OPTIONS_DEFINE=	DOCS SIMD

OPTIONS_DEFINE_amd64=	AVX
OPTIONS_DEFINE_i386=	AVX

OPTIONS_DEFAULT_aarch64=SIMD
OPTIONS_DEFAULT_amd64=	${OPTIONS_DEFAULT_i386}
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:S/SSE2/SIMD/}

AVX_DESC=	${SSE_DESC:S/SSE/AVX/}

AVX_VARS=	CARGO_FEATURES+=avx-accel RUSTFLAGS+="-C target-feature=+avx"
AVX_IMPLIES=	SIMD

# simd crate uses cfg_target_feature which isn't stable yet, so unlock
# unstable features similar to how lang/rust bootstraps. www/firefox
# uses the same hack when building with --enable-rust-simd.
SIMD_MAKE_ENV=	RUSTC_BOOTSTRAP=1
SIMD_VARS=	CARGO_FEATURES+=simd-accel ${SIMD_VARS_${ARCH}}
SIMD_VARS_i386=	RUSTFLAGS+="-C target-feature=+sse2"

post-patch:
	@${REINPLACE_CMD} -e 's|OUT_DIR|RIPGREP_OUTDIR|' ${WRKSRC}/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rg
	${INSTALL_MAN} ${RIPGREP_OUTDIR}/rg.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${RIPGREP_OUTDIR}/rg.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${RIPGREP_OUTDIR}/rg.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/complete/_rg \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
