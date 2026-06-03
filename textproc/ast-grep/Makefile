PORTNAME=	ast-grep
DISTVERSION=	0.43.0
CATEGORIES=	textproc devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	CLI tool for code structural search, lint and rewriting
WWW=		https://ast-grep.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes

CARGO_BUILD_ARGS=	--package ${PORTNAME}
CARGO_INSTALL_PATH=	crates/cli

PLIST_FILES=	bin/${PORTNAME} \
		bin/sg
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	COMPLETIONS DOCS
OPTIONS_DEFAULT=COMPLETIONS

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

post-build-COMPLETIONS-on:
	@${MKDIR} ${WRKSRC}/completions
.for sh in bash fish zsh
	${CARGO_TARGET_DIR}/*/${PORTNAME} completions ${sh} > \
		${WRKSRC}/completions/${PORTNAME}.${sh}
.endfor

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
