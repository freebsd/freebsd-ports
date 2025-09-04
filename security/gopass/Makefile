PORTNAME=	gopass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.16
PORTREVISION=	6
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Rewrite of the pass password manager in Go
WWW=		https://www.gopass.pw/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7
ONLY_FOR_ARCHS_REASON=	upstream only supports ${ONLY_FOR_ARCHS}

RUN_DEPENDS=	git:devel/git \
		gpg2:security/gnupg

USES=		go:modules

# Usage examples are in a separate repo
USE_GITHUB=	nodefault
GH_TUPLE=	gopasspw:password-store-example:8db75ba3b69c:password_store_example
GO_MODULE=	github.com/gopasspw/gopass
GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"

PORTDOCS=	README.md docs/*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-build:
.for SHELL in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${SHELL} > ${WRKSRC}/${SHELL}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.sh
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC_password_store_example} && ${COPYTREE_SHARE} "README.md secrets templates" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
