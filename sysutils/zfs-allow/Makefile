PORTNAME=	zfs-allow
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI and CLI for ZFS delegated administration
WWW=		https://github.com/olgeni/zfs-allow

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/olgeni/zfs-allow

PLIST_FILES=	bin/zfs-allow \
		share/bash-completion/completions/zfs-allow \
		share/fish/vendor_completions.d/zfs-allow.fish \
		share/man/man1/zfs-allow.1.gz \
		share/zsh/site-functions/_zfs-allow

post-install:
	${INSTALL_MAN} ${WRKSRC}/zfs-allow.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/zfs-allow.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/zfs-allow
	${INSTALL_DATA} ${WRKSRC}/completions/zfs-allow.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/zfs-allow.fish
	${INSTALL_DATA} ${WRKSRC}/completions/_zfs-allow \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_zfs-allow

.include <bsd.port.mk>
