PORTNAME=	crush
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	misc devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Glamourous AI coding agent for your favourite terminal
WWW=		https://github.com/charmbracelet/crush

LICENSE=	FSL-1.1-MIT
LICENSE_NAME=	Functional Source License, Version 1.1, MIT Future License
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		go:1.25,modules

GO_MODULE=	github.com/charmbracelet/crush
GO_BUILDFLAGS=	-ldflags '-s -w -X github.com/charmbracelet/crush/internal/version.Version=${DISTVERSION}'

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=		COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-build-COMPLETIONS-on:
	@${MKDIR} ${GO_WRKSRC}/completions
.for sh in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${sh} > \
		${GO_WRKSRC}/completions/${PORTNAME}.${sh}
.endfor

post-build-MANPAGES-on:
	@${MKDIR} ${GO_WRKSRC}/manpages
	${GO_WRKDIR_BIN}/${PORTNAME} man > ${GO_WRKSRC}/manpages/${PORTNAME}.1

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${GO_WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/manpages/${PORTNAME}.1 \
		${STAGEDIR}/${PREFIX}/share/man/man1

.include <bsd.port.mk>
