PORTNAME=	dust
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	More useful and intuitive version of du
WWW=		https://github.com/bootandy/dust

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bootandy

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${INSTALL_MAN}  ${WRKSRC}/man-page/dust.1       ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/completions/dust.bash ${STAGEDIR}${PREFIX}/share/bash-completion/completions/dust
	${INSTALL_DATA} ${WRKSRC}/completions/dust.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/completions/_dust     ${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config/config.toml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
