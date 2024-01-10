PORTNAME=	ripgrep
DISTVERSION=	14.0.3
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Command line search tool
WWW=		https://blog.burntsushi.net/ripgrep/

LICENSE=	MIT UNLICENSE
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_UNLICENSE=	${WRKSRC}/UNLICENSE

USES=		cargo cpe
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	BurntSushi

CARGO_CRATES=	aho-corasick-1.1.2 \
		anyhow-1.0.75 \
		autocfg-1.1.0 \
		bstr-1.8.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		crossbeam-channel-0.5.8 \
		crossbeam-deque-0.8.3 \
		crossbeam-epoch-0.9.15 \
		crossbeam-utils-0.8.16 \
		encoding_rs-0.8.33 \
		encoding_rs_io-0.1.7 \
		glob-0.3.1 \
		itoa-1.0.9 \
		jemalloc-sys-0.5.4+5.3.0-patched \
		jemallocator-0.5.4 \
		jobserver-0.1.27 \
		lexopt-0.3.0 \
		libc-0.2.150 \
		libm-0.2.8 \
		log-0.4.20 \
		memchr-2.6.4 \
		memmap2-0.9.0 \
		memoffset-0.9.0 \
		num-traits-0.2.17 \
		packed_simd-0.3.9 \
		pcre2-0.2.6 \
		pcre2-sys-0.2.7 \
		pkg-config-0.3.27 \
		proc-macro2-1.0.70 \
		quote-1.0.33 \
		regex-1.10.2 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		ryu-1.0.15 \
		same-file-1.0.6 \
		scopeguard-1.2.0 \
		serde-1.0.193 \
		serde_derive-1.0.193 \
		serde_json-1.0.108 \
		syn-2.0.39 \
		termcolor-1.4.0 \
		textwrap-0.16.0 \
		unicode-ident-1.0.12 \
		walkdir-2.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/rg \
		etc/bash_completion.d/rg.bash \
		share/man/man1/rg.1.gz \
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

SIMD_MAKE_ENV=	RUSTC_BOOTSTRAP=encoding_rs,packed_simd
SIMD_VARS=	CARGO_FEATURES+=simd-accel ${SIMD_VARS_${ARCH}}
SIMD_VARS_i386=	RUSTFLAGS+="-C target-feature=+sse2"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rg
	${STAGEDIR}${PREFIX}/bin/rg --generate man > ${WRKDIR}/rg.1
	${INSTALL_MAN} ${WRKDIR}/rg.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${STAGEDIR}${PREFIX}/bin/rg --generate complete-bash > ${STAGEDIR}${PREFIX}/etc/bash_completion.d/rg.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/
	${STAGEDIR}${PREFIX}/bin/rg --generate complete-fish > ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/rg.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${STAGEDIR}${PREFIX}/bin/rg --generate complete-zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_rg

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
