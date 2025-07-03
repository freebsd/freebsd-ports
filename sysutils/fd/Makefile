PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	10.2.0
PORTREVISION=	8
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-find

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple, fast and user-friendly alternative to find
WWW=		https://github.com/sharkdp/fd

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CONFLICTS_INSTALL=	fd

PLIST_FILES=	bin/fd \
		etc/bash_completion.d/fd.bash \
		share/fish/completions/fd.fish \
		share/man/man1/fd.1.gz \
		share/zsh/site-functions/_fd

post-build:
	${MKDIR} ${WRKSRC}/autocomplete
	${CARGO_TARGET_DIR}/release/fd --gen-completions bash > ${WRKSRC}/autocomplete/fd.bash
	${CARGO_TARGET_DIR}/release/fd --gen-completions fish > ${WRKSRC}/autocomplete/fd.fish

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/autocomplete/fd.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/autocomplete/fd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/_fd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
