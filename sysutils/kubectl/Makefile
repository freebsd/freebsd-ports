# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kubectl
PORTVERSION=	1.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes command-line tool

LICENSE=	APACHE20

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_PROJECT=	kubernetes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${LN} -s ${WRKSRC}/vendor ${WRKSRC}/src
	${MKDIR} ${WRKSRC}/src/k8s.io/kubernetes
	${LN} -s ${WRKSRC}/pkg ${WRKSRC}/src/k8s.io/kubernetes/pkg

do-build:
	cd ${WRKSRC}/cmd/${PORTNAME} && \
		GOPATH=${WRKSRC} go build \
		-ldflags="-X k8s.io/kubernetes/pkg/version.gitMajor=${PORTVERSION:R:R} \
		-X k8s.io/kubernetes/pkg/version.gitMinor=${PORTVERSION:R:E} \
		-X k8s.io/kubernetes/pkg/version.buildDate=$$(date +'%Y-%m-%dT%H:%M:%SZ') \
		-X k8s.io/kubernetes/pkg/version.gitVersion=${DISTVERSIONPREFIX}${PORTVERSION}"

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/cmd/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
