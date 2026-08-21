PORTNAME=	facl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI and CLI for NFSv4 ACLs
WWW=		https://github.com/olgeni/facl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/olgeni/facl

PLIST_FILES=	bin/facl \
		share/bash-completion/completions/facl \
		share/fish/vendor_completions.d/facl.fish \
		share/man/man1/facl.1.gz \
		share/zsh/site-functions/_facl

post-install:
	${INSTALL_MAN} ${WRKSRC}/facl.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/facl.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/facl
	${INSTALL_DATA} ${WRKSRC}/completions/facl.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/facl.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_facl \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_facl

.include <bsd.port.mk>
