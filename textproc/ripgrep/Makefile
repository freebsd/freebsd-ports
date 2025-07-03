PORTNAME=	ripgrep
DISTVERSION=	14.1.1
PORTREVISION=	7
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

PLIST_FILES=	bin/rg \
		etc/bash_completion.d/rg.bash \
		share/fish/vendor_completions.d/rg.fish \
		share/man/man1/rg.1.gz \
		share/zsh/site-functions/_rg

PORTDOCS=	CHANGELOG.md FAQ.md GUIDE.md

OPTIONS_DEFINE=		DOCS PCRE2 SIMD
OPTIONS_DEFAULT=	PCRE2

OPTIONS_DEFAULT_aarch64=	SIMD
OPTIONS_DEFAULT_amd64=	${OPTIONS_DEFAULT_i386}
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:S/SSE2/SIMD/}

PCRE2_DESC=		${PCRE_DESC} version 2
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_VARS=		CARGO_FEATURES+=pcre2

SIMD_MAKE_ENV=	RUSTC_BOOTSTRAP=encoding_rs
SIMD_VARS=	${SIMD_VARS_${ARCH}}
SIMD_VARS_i386=	RUSTFLAGS+="-C target-feature=+sse2"

post-install:
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
