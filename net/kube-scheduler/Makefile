PORTNAME=	kube-scheduler
PORTVERSION=	1.13.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Kubernetes scheduler daemon

LICENSE=	APACHE20

BROKEN_aarch64=	fails to build: vendor/golang.org/x/sys/unix/cap_freebsd.go:18:23: undefined: CAP_RIGHTS_VERSION_00

USES=		cpe go
CPE_VENDOR=	jenkins
CPE_PRODUCT=	kubernetes

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

BUILD_DATE=	2019-01-30T00:00:00Z

GO_PKGNAME=	k8s.io/kubernetes
GO_TARGET=	${GO_PKGNAME}/cmd/kube-scheduler
GO_BUILDFLAGS=	-ldflags="-X k8s.io/kubernetes/pkg/version.gitMajor=${PORTVERSION:R:R} \
		-X k8s.io/kubernetes/pkg/version.gitMinor=${PORTVERSION:R:E} \
		-X k8s.io/kubernetes/pkg/version.buildDate=${BUILD_DATE} \
		-X k8s.io/kubernetes/pkg/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
