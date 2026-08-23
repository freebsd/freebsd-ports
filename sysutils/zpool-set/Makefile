PORTNAME=	zpool-set
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI and CLI for ZFS pool properties
WWW=		https://github.com/olgeni/zpool-set

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/olgeni/zpool-set

PLIST_FILES=	bin/zpool-set \
		share/bash-completion/completions/zpool-set \
		share/fish/vendor_completions.d/zpool-set.fish \
		share/man/man1/zpool-set.1.gz \
		share/zsh/site-functions/_zpool-set

post-install:
	${INSTALL_MAN} ${WRKSRC}/zpool-set.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zpool-set.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/zpool-set
	${INSTALL_DATA} ${WRKSRC}/completions/zpool-set.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/zpool-set.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_zpool-set \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_zpool-set

.include <bsd.port.mk>
