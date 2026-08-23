PORTNAME=	pizauth
DISTVERSION=	1.1.0
PORTREVISION=	0
CATEGORIES=	mail

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Command-line OAuth2 authentication daemon
WWW=		https://tratt.net/laurie/src/pizauth/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ltratt
GH_TAGNAME=	${DISTNAME}

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

post-install:
	(cd ${WRKSRC} && \
		${INSTALL_MAN} pizauth.1 ${STAGEDIR}${PREFIX}/share/man/man1/ && \
		${INSTALL_MAN} pizauth.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/)
	(cd ${WRKSRC} && \
		${INSTALL_DATA} share/bash/completion.bash ${STAGEDIR}${PREFIX}/share/bash-completion/completions/pizauth && \
		${INSTALL_DATA} share/fish/pizauth.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/pizauth.fish && \
		${INSTALL_DATA} share/zsh/_pizauth ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_pizauth)

.include <bsd.port.mk>
