# $FreeBSD$

PORTNAME=	kube-controller-manager
PORTVERSION=	1.13.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Kubernetes command-line tool

LICENSE=	APACHE20

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

BUILD_DATE=	2019-01-30T00:00:00Z

GO_PKGNAME=	k8s.io/kubernetes
GO_TARGET=	${GO_PKGNAME}/cmd/kube-controller-manager
GO_BUILDFLAGS=	-ldflags="-X k8s.io/kubernetes/pkg/version.gitMajor=${PORTVERSION:R:R} \
		-X k8s.io/kubernetes/pkg/version.gitMinor=${PORTVERSION:R:E} \
		-X k8s.io/kubernetes/pkg/version.buildDate=${BUILD_DATE} \
		-X k8s.io/kubernetes/pkg/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
