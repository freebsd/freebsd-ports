# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kubectl
PORTVERSION=	1.17.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes command-line tool

LICENSE=	APACHE20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

GH_TUPLE=	golang:sys:fead79001313:golang_sys/vendor/golang.org/x/sys_fead79001313

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
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_fead79001313 ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
