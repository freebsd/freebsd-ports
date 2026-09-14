PORTNAME=	vm-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI and CLI for vm-bhyve guests, switches and images
WWW=		https://github.com/olgeni/vm-tui

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	vm:sysutils/vm-bhyve

USES=		go:modules
GO_MODULE=	github.com/olgeni/vm-tui

PLIST_FILES=	bin/vm-tui \
		share/bash-completion/completions/vm-tui \
		share/fish/vendor_completions.d/vm-tui.fish \
		share/man/man1/vm-tui.1.gz \
		share/zsh/site-functions/_vm-tui

post-install:
	${INSTALL_MAN} ${WRKSRC}/vm-tui.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/vm-tui.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/vm-tui
	${INSTALL_DATA} ${WRKSRC}/completions/vm-tui.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/vm-tui.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_vm-tui \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_vm-tui

.include <bsd.port.mk>
