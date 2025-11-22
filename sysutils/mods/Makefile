PORTNAME=	mods
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
CATEGORIES=	sysutils

MAINTAINER=	mopp7@proton.me
COMMENT=	AI for the command line, built for pipelines
WWW=		https://github.com/charmbracelet/mods

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_SHA=	9b36cf8

GO_MODULE=	github.com/charmbracelet/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.CommitSHA=${_BUILD_SHA}"

PLIST_FILES=	bin/${PORTNAME}
DOCS=		config_template.yml README.md
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=	COMPLETIONS DOCS

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=	etc/bash_completion.d/${PORTNAME} \
				share/fish/completions/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

post-build-COMPLETIONS-on:
	@${MKDIR} ${GO_WRKSRC}/completions
.for sh in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${sh} > \
		${GO_WRKSRC}/completions/${PORTNAME}.${sh}
.endfor

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${GO_WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${GO_WRKSRC}/completions/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
