# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minikube
PORTVERSION=	0.34.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Run Kubernetes locally

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes

GO_PKGNAME=	k8s.io/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/minikube/pkg/version.version=v${PORTVERSION} \
		-X k8s.io/minikube/pkg/version.isoVersion=v0.34.0 \
		-X k8s.io/minikube/pkg/version.isoPath=minikube/iso"

PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	cd ${WRKSRC}/pkg/minikube/tunnel && \
		${LN} -s route_darwin.go route_freebsd.go
	cd ${WRKSRC}/vendor/github.com/pkg/browser && \
		${LN} -s browser_linux.go browser_freebsd.go
	cd ${WRKSRC}/pkg/minikube/cluster && \
		${LN} -s cluster_linux.go cluster_freebsd.go
	cd ${WRKSRC}/third_party/go9p && \
		${LN} -s srv_pipe_linux.go srv_pipe_freebsd.go
pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/assets/assets.go -pkg assets deploy/addons/...

.include <bsd.port.mk>
