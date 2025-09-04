PORTNAME=	kube-controller-manager
PORTVERSION=	1.27.2
DISTVERSIONPREFIX=	v
PORTREVISION=	17
CATEGORIES=	net

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Kubernetes controller manager daemon
WWW=		https://github.com/kubernetes/kubernetes

LICENSE=	APACHE20

USES=		cpe go
CPE_VENDOR=	jenkins
CPE_PRODUCT=	kubernetes

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

GO_PKGNAME=	k8s.io/kubernetes
GO_TARGET=	${GO_PKGNAME}/cmd/kube-controller-manager

BUILD_DATE=	$$(date +'%Y-%m-%dT%H:%M:%SZ')

GO_BUILDFLAGS=	-ldflags="-X k8s.io/kubernetes/vendor/k8s.io/client-go/pkg/version.buildDate=${BUILD_DATE} \
      		-X k8s.io/kubernetes/vendor/k8s.io/component-base/version.buildDate=${BUILD_DATE} \
      		-X k8s.io/client-go/pkg/version.buildDate=${BUILD_DATE} \
      		-X k8s.io/component-base/version.buildDate=${BUILD_DATE} \
		-X k8s.io/kubernetes/vendor/k8s.io/client-go/pkg/version.gitMinor=${PORTVERSION:R:E} \
      		-X k8s.io/kubernetes/vendor/k8s.io/component-base/version.gitMinor=${PORTVERSION:R:E} \
      		-X k8s.io/client-go/pkg/version.gitMinor=${PORTVERSION:R:E} \
      		-X k8s.io/component-base/version.gitMinor=${PORTVERSION:R:E} \
		-X k8s.io/kubernetes/vendor/k8s.io/client-go/pkg/version.gitMajor=${PORTVERSION:R:R} \
      		-X k8s.io/kubernetes/vendor/k8s.io/component-base/version.gitMajor=${PORTVERSION:R:R} \
      		-X k8s.io/client-go/pkg/version.gitMajor=${PORTVERSION:R:R} \
      		-X k8s.io/component-base/version.gitMajor=${PORTVERSION:R:R} \
		-X k8s.io/kubernetes/vendor/k8s.io/client-go/pkg/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION} \
      		-X k8s.io/kubernetes/vendor/k8s.io/component-base/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION} \
      		-X k8s.io/client-go/pkg/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION} \
      		-X k8s.io/component-base/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION}"

USE_RC_SUBR=	kube-controller-manager

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
