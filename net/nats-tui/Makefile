PORTNAME=	nats-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI for the NATS nats tool
WWW=		https://github.com/olgeni/nats-tui

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nats:net/natscli

USES=		go:modules
GO_MODULE=	github.com/olgeni/nats-tui

PLIST_FILES=	bin/nats-tui \
		share/bash-completion/completions/nats-tui \
		share/fish/vendor_completions.d/nats-tui.fish \
		share/man/man1/nats-tui.1.gz \
		share/zsh/site-functions/_nats-tui

post-install:
	${INSTALL_MAN} ${WRKSRC}/nats-tui.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/nats-tui.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/nats-tui
	${INSTALL_DATA} ${WRKSRC}/completions/nats-tui.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/nats-tui.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_nats-tui \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_nats-tui

.include <bsd.port.mk>
