PORTNAME=	infisical-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.43.99
CATEGORIES=	security

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Official Infisical CLI
WWW=		https://github.com/Infisical/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/Infisical/cli
GO_TARGET=	${PORTNAME}:infisical
GO_LDFLAGS=	-X github.com/Infisical/infisical-merge/packages/util.CLI_VERSION=${DISTVERSION}

OPTIONS_DEFINE=	BASH FISH MANPAGES ZSH
OPTIONS_DEFAULT=BASH FISH MANPAGES ZSH
OPTIONS_SUB=	yes

post-build-BASH-on:
	@${MKDIR} ${WRKDIR}/completions
	cd ${GO_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run . \
		completion bash > ${WRKDIR}/completions/infisical.bash

post-build-FISH-on:
	@${MKDIR} ${WRKDIR}/completions
	cd ${GO_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run . \
		completion fish > ${WRKDIR}/completions/infisical.fish

post-build-MANPAGES-on:
	@${MKDIR} ${WRKDIR}/manpages
	cd ${GO_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run . \
		man | ${GZIP_CMD} -c > ${WRKDIR}/manpages/infisical.1.gz

post-build-ZSH-on:
	@${MKDIR} ${WRKDIR}/completions
	cd ${GO_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run . \
		completion zsh > ${WRKDIR}/completions/infisical.zsh

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKDIR}/completions/infisical.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/infisical

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKDIR}/completions/infisical.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKDIR}/manpages/infisical.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/completions/infisical.fish \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_infisical

.include <bsd.port.mk>
