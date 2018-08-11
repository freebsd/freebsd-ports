# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minikube
PORTVERSION=	0.28.2
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

PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	${LN} -s ${WRKSRC}/vendor ${WRKSRC}/src
	${MKDIR} ${WRKSRC}/src/k8s.io/${PORTNAME}
	${LN} -s ${WRKSRC}/pkg ${WRKSRC}/src/k8s.io/${PORTNAME}/pkg
	${LN} -s ${WRKSRC}/cmd ${WRKSRC}/src/k8s.io/${PORTNAME}/cmd
	${LN} -s ${WRKSRC}/third_party ${WRKSRC}/src/k8s.io/${PORTNAME}/third_party

do-build:
	(cd ${WRKSRC}; ${LOCALBASE}/bin/go-bindata -nomemcopy -o pkg/minikube/assets/assets.go -pkg assets deploy/addons/...)
	cd ${WRKSRC}/cmd/${PORTNAME} && \
		GOPATH=${WRKSRC} go build \
		-ldflags="-X k8s.io/minikube/pkg/version.version=v${PORTVERSION} \
			-X k8s.io/minikube/pkg/version.isoVersion=v0.28.1 \
			-X k8s.io/minikube/pkg/version.isoPath=minikube/iso \
			-X k8s.io/kubernetes/pkg/version.gitCommit=fc32d2f3698e36b93322a3465f63a14e9f0eaead \
			-X k8s.io/kubernetes/pkg/version.gitTreeState=clean \
			-X k8s.io/kubernetes/pkg/version.gitVersion=v1.10.0 \
			-X k8s.io/kubernetes/pkg/version.gitMajor=1 \
			-X k8s.io/kubernetes/pkg/version.gitMinor=10 \
			-X k8s.io/kubernetes/pkg/version.buildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
			-X k8s.io/client-go/pkg/version.gitCommit=fc32d2f3698e36b93322a3465f63a14e9f0eaead \
			-X k8s.io/client-go/pkg/version.gitTreeState=clean \
			-X k8s.io/client-go/pkg/version.gitVersion=v1.10.0 \
			-X k8s.io/client-go/pkg/version.gitMajor=1 \
			-X k8s.io/client-go/pkg/version.gitMinor=10 \
			-X k8s.io/client-go/pkg/version.buildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ')"

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/cmd/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
