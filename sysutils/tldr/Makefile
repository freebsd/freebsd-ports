PORTNAME=	tldr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	"Official" Rust tldr client
WWW=		https://tldr.sh/tlrc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_PROJECT=	tlrc
GH_ACCOUNT=	tldr-pages

CONFLICTS_INSTALL=	tealdeer

PLIST_FILES=	bin/tldr \
		share/man/man1/tldr.1.gz \
		share/bash-completion/completions/tldr \
		share/fish/vendor_completions.d/tldr.fish \
		share/zsh/site-functions/_tldr

post-install:
	${INSTALL_MAN}  ${WRKSRC}/tldr.1                ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/completions/tldr.bash ${STAGEDIR}${PREFIX}/share/bash-completion/completions/tldr
	${INSTALL_DATA} ${WRKSRC}/completions/tldr.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/completions/_tldr     ${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
