# Created by: Petteri Valkonen <petteri.valkonen@iki.fi>
# $FreeBSD$

# vim: ts=8 noet

PORTNAME=	ripgrep
DISTVERSION=	11.0.1
PORTREVISION=	3
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

CARGO_CRATES=	aho-corasick-0.7.3 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		base64-0.10.1 \
		bitflags-1.0.4 \
		bstr-0.1.2 \
		bytecount-0.5.1 \
		byteorder-1.3.1 \
		cc-1.0.35 \
		cfg-if-0.1.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		crossbeam-channel-0.3.8 \
		crossbeam-utils-0.6.5 \
		encoding_rs-0.8.17 \
		encoding_rs_io-0.1.6 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		glob-0.3.0 \
		itoa-0.4.3 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		log-0.4.6 \
		memchr-2.2.0 \
		memmap-0.7.0 \
		num_cpus-1.10.0 \
		packed_simd-0.3.3 \
		pcre2-0.2.0 \
		pcre2-sys-0.2.0 \
		pkg-config-0.3.14 \
		proc-macro2-0.4.27 \
		quote-0.6.12 \
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
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		regex-1.1.6 \
		regex-automata-0.1.6 \
		regex-syntax-0.6.6 \
		remove_dir_all-0.5.1 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		serde_json-1.0.39 \
		smallvec-0.6.9 \
		strsim-0.8.0 \
		syn-0.15.31 \
		tempfile-3.0.7 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		walkdir-2.2.7 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

RIPGREP_OUTDIR=	${WRKDIR}/cargo-out
CARGO_ENV=	RIPGREP_OUTDIR=${RIPGREP_OUTDIR}

PLIST_FILES=	bin/rg \
		etc/bash_completion.d/rg.bash \
		man/man1/rg.1.gz \
		share/fish/completions/rg.fish \
		share/zsh/site-functions/_rg

PORTDOCS=	CHANGELOG.md FAQ.md GUIDE.md

OPTIONS_DEFINE=	DOCS PCRE2 SIMD
OPTIONS_DEFAULT=PCRE2

OPTIONS_DEFAULT_aarch64=SIMD
OPTIONS_DEFAULT_amd64=	${OPTIONS_DEFAULT_i386}
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:S/SSE2/SIMD/}

PCRE2_DESC=	${PCRE_DESC} version 2
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_VARS=	CARGO_FEATURES+=pcre2

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
