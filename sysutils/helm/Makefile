PORTNAME=	helm
PORTVERSION=	3.18.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Package Manager
WWW=		https://helm.sh

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		cpe go:modules tar:xz

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}/v3
GO_PKGNAME=	k8s.io/helm
GO_BUILDFLAGS=	-ldflags="-X helm.sh/helm/v3/internal/version.version=v${PORTVERSION} \
		-X helm.sh/helm/v3/internal/version.gitCommit=b76a950f6835474e0906b96c9ec68a2eff3a6430"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

OPTIONS_DEFINE=		BASH FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/helm
FISH_PLIST_FILES=	share/fish/vendor_functions.d/helm.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_helm

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${STAGEDIR}${PREFIX}/bin/helm completion bash > ${STAGEDIR}${PREFIX}/share/bash-completion/completions/helm

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d
	${STAGEDIR}${PREFIX}/bin/helm completion fish > ${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d/helm.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/helm completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_helm

.include <bsd.port.mk>
