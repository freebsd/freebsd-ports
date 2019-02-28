# Created by: Petteri Valkonen <petteri.valkonen@iki.fi>
# $FreeBSD$

# vim: ts=8 noet

PORTNAME=	ripgrep
DISTVERSION=	0.10.0
PORTREVISION=	6
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

CARGO_CRATES=	aho-corasick-0.6.8 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		base64-0.9.2 \
		bitflags-1.0.4 \
		bytecount-0.5.1 \
		byteorder-1.2.6 \
		cc-1.0.24 \
		cfg-if-0.1.5 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		crossbeam-channel-0.2.4 \
		crossbeam-epoch-0.5.2 \
		crossbeam-utils-0.5.0 \
		encoding_rs-0.8.16 \
		encoding_rs_io-0.1.2 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.2.11 \
		itoa-0.4.2 \
		lazy_static-1.1.0 \
		libc-0.2.49 \
		lock_api-0.1.3 \
		log-0.4.5 \
		memchr-2.0.2 \
		memmap-0.6.2 \
		memoffset-0.2.1 \
		nodrop-0.1.12 \
		num_cpus-1.8.0 \
		owning_ref-0.3.3 \
		packed_simd-0.3.3 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.0 \
		pcre2-0.1.0 \
		pcre2-sys-0.1.1 \
		pkg-config-0.3.14 \
		proc-macro2-0.4.18 \
		quote-0.6.8 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand_core-0.2.1 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.5 \
		regex-syntax-0.6.2 \
		remove_dir_all-0.5.1 \
		ryu-0.2.6 \
		safemem-0.2.0 \
		same-file-1.0.3 \
		scopeguard-0.3.3 \
		serde-1.0.77 \
		serde_derive-1.0.77 \
		serde_json-1.0.27 \
		simd-0.2.2 \
		smallvec-0.6.5 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.15.1 \
		tempdir-0.3.7 \
		termcolor-1.0.3 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.1 \
		version_check-0.1.4 \
		void-1.0.2 \
		walkdir-2.2.5 \
		winapi-0.3.5 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
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
