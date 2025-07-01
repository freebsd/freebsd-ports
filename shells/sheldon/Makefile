PORTNAME=	sheldon
DISTVERSION=	0.8.3
CATEGORIES=	shells

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Fast, configurable, shell plugin manager
WWW=		https://sheldon.cli.rs/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libssh2.so:security/libssh2

USES=		cargo localbase:ldflags ssl

USE_GITHUB=	yes
GH_ACCOUNT=	rossmacarthur

CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME} \
		share/zsh/site-functions/_${PORTNAME}

PORTDOCS=	README.md RELEASES.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
