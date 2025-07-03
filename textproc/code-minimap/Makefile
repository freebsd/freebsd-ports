PORTNAME=	code-minimap
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.8
PORTREVISION=	5
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

PLIST_FILES=	bin/code-minimap \
		etc/bash_completion.d/code-minimap \
		share/fish/vendor_completions.d/code-minimap \
		share/zsh/site-functions/code-minimap

post-install:
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
