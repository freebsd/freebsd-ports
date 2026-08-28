PORTNAME=	nsc-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for the NATS nsc tool
WWW=		https://github.com/olgeni/nsc-tui

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nsc:net/nats-nsc

USES=		go:modules
GO_MODULE=	github.com/olgeni/nsc-tui

PLIST_FILES=	bin/nsc-tui \
		share/bash-completion/completions/nsc-tui \
		share/fish/vendor_completions.d/nsc-tui.fish \
		share/man/man1/nsc-tui.1.gz \
		share/zsh/site-functions/_nsc-tui

post-install:
	${INSTALL_MAN} ${WRKSRC}/nsc-tui.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/nsc-tui.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/nsc-tui
	${INSTALL_DATA} ${WRKSRC}/completions/nsc-tui.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/nsc-tui.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_nsc-tui \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_nsc-tui

.include <bsd.port.mk>
