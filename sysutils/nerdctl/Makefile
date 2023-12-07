PORTNAME=	nerdctl
DISTVERSIONPREFIX=v
DISTVERSION=	1.2.1
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Docker-compatible CLI for containerd
WWW=		https://github.com/containerd/nerdctl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/containerd/nerdctl
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-s -w -X ${GO_MODULE}/pkg/version.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/containerd-rootless.sh \
		bin/containerd-rootless-setuptool.sh \
		bin/nerdctl \
		etc/bash_completion.d/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extras/rootless/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion bash > ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion fish > ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion zsh  > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
