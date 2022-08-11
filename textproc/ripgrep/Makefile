PORTNAME=	ripgrep
DISTVERSION=	13.0.0
PORTREVISION=	12
CATEGORIES=	textproc

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command line search tool

LICENSE=	MIT UNLICENSE
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

USES=		cargo cpe
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	BurntSushi

CARGO_CRATES=	aho-corasick-0.7.18 \
		atty-0.2.14 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		bstr-0.2.16 \
		bytecount-0.6.2 \
		cc-1.0.68 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		crossbeam-channel-0.5.1 \
		crossbeam-utils-0.8.5 \
		encoding_rs-0.8.28 \
		encoding_rs_io-0.1.7 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		glob-0.3.0 \
		globset-0.4.7 \
		grep-0.2.8 \
		grep-cli-0.1.6 \
		grep-matcher-0.1.5 \
		grep-pcre2-0.1.5 \
		grep-printer-0.1.6 \
		grep-regex-0.1.9 \
		grep-searcher-0.1.8 \
		hermit-abi-0.1.18 \
		ignore-0.4.18 \
		itoa-0.4.7 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		jobserver-0.1.22 \
		lazy_static-1.4.0 \
		libc-0.2.97 \
		libm-0.1.4 \
		log-0.4.14 \
		memchr-2.4.0 \
		memmap2-0.3.0 \
		num_cpus-1.13.0 \
		once_cell-1.7.2 \
		packed_simd_2-0.3.7 \
		pcre2-0.2.3 \
		pcre2-sys-0.2.5 \
		pkg-config-0.3.19 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		regex-1.5.4 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		serde_json-1.0.64 \
		strsim-0.8.0 \
		syn-1.0.73 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		walkdir-2.3.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

RIPGREP_OUTDIR=	${WRKDIR}/cargo-out
CARGO_ENV=	RIPGREP_OUTDIR=${RIPGREP_OUTDIR}

PLIST_FILES=	bin/rg \
		etc/bash_completion.d/rg.bash \
		man/man1/rg.1.gz \
		share/fish/vendor_completions.d/rg.fish \
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

SIMD_MAKE_ENV=	RUSTC_BOOTSTRAP=encoding_rs,packed_simd_2
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/
	${INSTALL_DATA} ${RIPGREP_OUTDIR}/rg.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/complete/_rg \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
