PORTNAME=	tealdeer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
PORTREVISION=	18
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fast tldr client written in Rust
WWW=		https://github.com/dbrgn/tealdeer

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	dbrgn

CONFLICTS_INSTALL=	tldr

PLIST_FILES=	bin/tldr

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		COMPLETIONS DOCS LOGGER
OPTIONS_DEFAULT=	COMPLETIONS

LOGGER_DESC=	Debug build with logging enabled
LOGGER_VARS=	CARGO_FEATURES+=logging

COMPLETIONS_DESC=		Install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install:
.for _shell in bash fish zsh
	${INSTALL_DATA} ${WRKSRC}/completion/${_shell}_${PORTNAME} \
		${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
