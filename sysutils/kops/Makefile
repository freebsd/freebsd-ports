# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kops
PORTVERSION=	1.10.0
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Operations

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes
GH_SUBDIR=	src/k8s.io/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -o upup/models/bindata.go -pkg models \
		-prefix upup/models/ upup/models/... && \
		GOPATH=${WRKSRC} go build \
		-ldflags=all="-X k8s.io/kops.Version=${PORTVERSION}" \
		k8s.io/kops/cmd/kops

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
