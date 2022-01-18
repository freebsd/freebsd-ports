# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>

PORTNAME=	kubectl
PORTVERSION=	1.23.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes command-line tool

LICENSE=	APACHE20

USES=		cpe go:modules
CPE_VENDOR=	jenkins
CPE_PRODUCT=	kubernetes

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

# The vendored golang/sys fails to build on aarch64
GOLANG_SYS_V=	22da62e12c0c
GH_TUPLE=	golang:sys:${GOLANG_SYS_V}:golang_sys/vendor/golang.org/x/sys_${GOLANG_SYS_V}

GO_PKGNAME=	k8s.io/kubernetes
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/component-base/version.gitMajor=${PORTVERSION:R:R} \
		-X k8s.io/component-base/version.gitMinor=${PORTVERSION:R:E} \
		-X k8s.io/component-base/version.buildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X k8s.io/component-base/version.gitCommit="" \
		-X k8s.io/component-base/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION} \
		-X k8s.io/client-go/pkg/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		BASH ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/${PORTNAME}
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-extract:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_${GOLANG_SYS_V} ${WRKSRC}/vendor/golang.org/x/sys

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion bash > ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
