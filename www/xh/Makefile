PORTNAME=	xh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.0
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Friendly and fast tool for sending HTTP requests
WWW=		https://github.com/ducaale/xh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	ducaale

CARGO_FEATURES=	--no-default-features native-tls

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES
OPTIONS_SUB=		yes

COMPLETIONS_DESC=		Install shell completions for bash, fish and zsh
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}
MANPAGES_PLIST_FILES=		share/man/man1/${PORTNAME}.1.gz

post-install-COMPLETIONS-on:
	@${MV} ${WRKSRC}/completions/_${PORTNAME} ${WRKSRC}/completions/${PORTNAME}.zsh
.for _shell in bash fish zsh
	${INSTALL_DATA} ${WRKSRC}/completions/${PORTNAME}.${_shell}\
		${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
