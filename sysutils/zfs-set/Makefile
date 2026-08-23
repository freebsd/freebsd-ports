PORTNAME=	zfs-set
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI and CLI for ZFS dataset properties
WWW=		https://github.com/olgeni/zfs-set

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/olgeni/zfs-set

PLIST_FILES=	bin/zfs-set \
		share/bash-completion/completions/zfs-set \
		share/fish/vendor_completions.d/zfs-set.fish \
		share/man/man1/zfs-set.1.gz \
		share/zsh/site-functions/_zfs-set

post-install:
	${INSTALL_MAN} ${WRKSRC}/zfs-set.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zfs-set.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/zfs-set
	${INSTALL_DATA} ${WRKSRC}/completions/zfs-set.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/zfs-set.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_zfs-set \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_zfs-set

.include <bsd.port.mk>
