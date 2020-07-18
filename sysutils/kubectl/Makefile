# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kubectl
PORTVERSION=	1.18.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes command-line tool

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

# The vendored golang/sys fails to build on aarch64
GOLANG_SYS_V=	9fbb57f87de9
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

post-extract:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_${GOLANG_SYS_V} ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
