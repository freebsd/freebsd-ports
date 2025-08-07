PORTNAME=	smug
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
PORTREVISION=	18
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Session manager and task runner for tmux
WWW=		https://github.com/ivaaaan/smug

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	tmux:sysutils/tmux

USES=		go:modules
GO_MODULE=	github.com/ivaaaan/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CODE_OF_CONDUCT.md README.md

OPTIONS_DEFINE=		COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES

COMPLETIONS_DESC=	Install bash and fish shell completions

COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish
MANPAGES_PLIST_FILES=		share/man/man1/${PORTNAME}.1.gz

post-install-COMPLETIONS-on:
.for _shell in bash fish
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.${_shell} \
		${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
