PORTNAME=	smug
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Session manager and task runner for tmux

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
MANPAGES_PLIST_FILES=		man/man1/${PORTNAME}.1.gz

post-install-COMPLETIONS-on:
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/completion/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
