PORTNAME=	step-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.7
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step-ca command line client
WWW=		https://smallstep.com/cli/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules shebangfix

SHEBANG_FILES=	autocomplete/bash_autocomplete

GO_MODULE=	github.com/smallstep/cli
GO_TARGET=	./cmd/step
GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

PLIST_FILES=	bin/step \
		etc/bash_completion.d/step-completion.bash \
		share/zsh/site-functions/_step

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${CP} ${WRKSRC}/autocomplete/bash_autocomplete ${STAGEDIR}${PREFIX}/etc/bash_completion.d/step-completion.bash
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${CP} ${WRKSRC}/autocomplete/zsh_autocomplete ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_step

.include <bsd.port.mk>
