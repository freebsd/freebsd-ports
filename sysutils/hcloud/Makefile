PORTNAME=	hcloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.51.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Official Hetzner Cloud command-line interface
WWW=		https://github.com/hetznercloud/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.23

GO_MODULE=	github.com/hetznercloud/cli
GO_TARGET=	./cmd/hcloud

PLIST_FILES=	bin/hcloud \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site_functions/_${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/ \
		${STAGEDIR}${PREFIX}/share/fish/completions/ \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions/
	${STAGEDIR}${PREFIX}/bin/hcloud completion bash > ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${STAGEDIR}${PREFIX}/bin/hcloud completion fish > ${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${STAGEDIR}${PREFIX}/bin/hcloud completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site_functions/_${PORTNAME}

.include <bsd.port.mk>
