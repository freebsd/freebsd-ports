PORTNAME=	tailspin
DISTVERSION=	5.5.0
CATEGORIES=	sysutils

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Log file highlighter
WWW=		https://github.com/bensadeh/tailspin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	bensadeh

PLIST_FILES=	bin/tspin
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=COMPLETIONS MANPAGES

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/tspin \
			share/fish/completions/tspin.fish \
			share/zsh/site-functions/_tspin
MANPAGES_PLIST_FILES=	share/man/man1/tspin.1.gz

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/tspin.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/tspin
	${INSTALL_DATA} ${WRKSRC}/completions/tspin.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/tspin.fish
	${INSTALL_DATA} ${WRKSRC}/completions/tspin.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tspin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/tspin.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
