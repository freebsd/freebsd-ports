PORTNAME=	tuios
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.3
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal window manager and multiplexer
WWW=		https://tuios.dev/ \
		https://github.com/Gaurav-Gosain/tuios

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/Gaurav-Gosain/tuios
# The module ships a go.work for upstream development; go mod vendor refuses
# to run in workspace mode.
GO_ENV=		GOWORK=off
GO_TARGET=	./cmd/tuios \
		./cmd/tuios-web
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/tuios \
		bin/tuios-web \
		share/bash-completion/completions/tuios \
		share/fish/vendor_completions.d/tuios.fish \
		share/zsh/site-functions/_tuios

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/tuios completion bash > \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/tuios
	${STAGEDIR}${PREFIX}/bin/tuios completion fish > \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/tuios.fish
	${STAGEDIR}${PREFIX}/bin/tuios completion zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tuios

.include <bsd.port.mk>
