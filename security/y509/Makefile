PORTNAME=	y509
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
CATEGORIES=	security

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	TUI tool for viewing and analyzing X.509 certificate chains
WWW=		https://github.com/kanywst/y509

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/kanywst/y509
GO_TARGET=	./cmd/${PORTNAME}
GO_LDFLAGS=	-X ${GO_MODULE}/internal/version.Version=${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME} \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-build:
	@${MKDIR} ${GO_WRKSRC}/completions
.for sh in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${sh} > \
		${GO_WRKSRC}/completions/${PORTNAME}.${sh}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${GO_WRKSRC}/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${GO_WRKSRC}/completions/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
