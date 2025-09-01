PORTNAME=	sd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	17
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Intuitive find and replace tool
WWW=		https://github.com/chmln/sd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmln

PLIST_FILES=	bin/sd \
		etc/bash_completion.d/sd.bash \
		share/fish/completions/sd.fish \
		share/man/man1/sd.1.gz \
		share/zsh/site-functions/_sd
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/gen/sd.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/gen/completions/sd.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/gen/completions/sd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/gen/completions/_sd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
