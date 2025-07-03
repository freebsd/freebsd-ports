PORTNAME=	tailspin
DISTVERSION=	5.4.5
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Log file highlighter
WWW=		https://github.com/bensadeh/tailspin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	bensadeh

PLIST_FILES=	bin/tspin \
		etc/bash_completion.d/tspin \
		share/fish/completions/tspin.fish \
		share/man/man1/tspin.1.gz \
		share/zsh/site-functions/_tspin

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/tspin.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/tspin.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/tspin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/tspin.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/tspin.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/tspin.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tspin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
