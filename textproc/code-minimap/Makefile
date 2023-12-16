PORTNAME=	code-minimap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
PORTREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	High performance code minimap render
WWW=		https://github.com/wfxr/code-minimap

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	wfxr

CARGO_CRATES=	anyhow-1.0.52 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cfg-if-1.0.0 \
		clap-3.0.0 \
		clap_complete-3.0.0 \
		clap_derive-3.0.0 \
		either-1.6.1 \
		hashbrown-0.11.2 \
		heck-0.3.2 \
		hermit-abi-0.1.18 \
		indexmap-1.7.0 \
		itertools-0.10.3 \
		lazy_static-1.4.0 \
		libc-0.2.88 \
		memchr-2.4.1 \
		os_str_bytes-6.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.28 \
		quote-1.0.9 \
		rstest-0.12.0 \
		rustc_version-0.4.0 \
		rustversion-1.0.6 \
		semver-1.0.4 \
		strsim-0.10.0 \
		strum-0.23.0 \
		strum_macros-0.23.1 \
		syn-1.0.80 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		textwrap-0.14.2 \
		unicode-segmentation-1.7.1 \
		unicode-xid-0.2.1 \
		version_check-0.9.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/code-minimap \
		etc/bash_completion.d/code-minimap \
		share/fish/vendor_completions.d/code-minimap \
		share/zsh/site-functions/code-minimap

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/code-minimap

	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/ \
		 ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/ \
		 ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

	${STAGEDIR}${PREFIX}/bin/code-minimap completion bash > \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/code-minimap

	${STAGEDIR}${PREFIX}/bin/code-minimap completion fish > \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/code-minimap

	${STAGEDIR}${PREFIX}/bin/code-minimap completion zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/code-minimap

.include <bsd.port.mk>
