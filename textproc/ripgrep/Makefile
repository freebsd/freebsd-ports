# Created by: Petteri Valkonen <petteri.valkonen@iki.fi>
# $FreeBSD$

# vim: ts=8 noet

PORTNAME=	ripgrep
DISTVERSION=	11.0.2
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

CARGO_CRATES=	aho-corasick-0.7.4 \
		atty-0.2.13 \
		base64-0.10.1 \
		bitflags-1.1.0 \
		bstr-0.2.6 \
		bytecount-0.5.1 \
		byteorder-1.3.2 \
		c2-chacha-0.2.2 \
		cc-1.0.38 \
		cfg-if-0.1.9 \
		clap-2.33.0 \
		crossbeam-channel-0.3.9 \
		crossbeam-utils-0.6.6 \
		encoding_rs-0.8.17 \
		encoding_rs_io-0.1.6 \
		fnv-1.0.6 \
		fs_extra-1.1.0 \
		getrandom-0.1.7 \
		glob-0.3.0 \
		itoa-0.4.4 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		lazy_static-1.3.0 \
		libc-0.2.60 \
		log-0.4.8 \
		memchr-2.2.1 \
		memmap-0.7.0 \
		num_cpus-1.10.1 \
		packed_simd-0.3.3 \
		pcre2-0.2.1 \
		pcre2-sys-0.2.2 \
		pkg-config-0.3.15 \
		ppv-lite86-0.2.5 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rand-0.7.0 \
		rand_chacha-0.2.1 \
		rand_core-0.5.0 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.2.0 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.10 \
		remove_dir_all-0.5.2 \
		ryu-1.0.0 \
		same-file-1.0.5 \
		serde-1.0.98 \
		serde_derive-1.0.98 \
		serde_json-1.0.40 \
		strsim-0.8.0 \
		syn-0.15.42 \
		tempfile-3.1.0 \
		termcolor-1.0.5 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.5 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.3 \
		walkdir-2.2.9 \
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/complete/_rg \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
