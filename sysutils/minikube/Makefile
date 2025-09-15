PORTNAME=	minikube
PORTVERSION=	1.37.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Run Kubernetes locally
WWW=		https://github.com/kubernetes/minikube

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		cpe go:modules
CPE_VENDOR=	kubernetes

GO_MODULE=	github.com/kubernetes/${PORTNAME}

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X k8s.io/minikube/pkg/version.version=v${PORTVERSION} \
		-X k8s.io/minikube/pkg/version.isoVersion=v1.37.0 \
		-X k8s.io/minikube/pkg/version.storageProvisionerVersion=v5 \
		-X k8s.io/minikube/pkg/version.isoPath=minikube/iso"

PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	pkg-message

pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/assets/assets.go -pkg assets deploy/addons/... && \
		${LOCALBASE}/bin/go-bindata -nomemcopy \
		-o pkg/minikube/translate/translations.go -pkg translate translations/... && \
		${LOCALBASE}/bin/gofmt${GO_SUFFIX} -s -w pkg/minikube/translate/translations.go

.include <bsd.port.mk>
