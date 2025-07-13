PORTNAME=	kops
PORTVERSION=	1.32.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Operations
WWW=		https://github.com/kubernetes/kops

LICENSE=	APACHE20

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	kubernetes

GO_PKGNAME=	k8s.io/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags=all="-X k8s.io/kops.Version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	cd ${WRKSRC} && \
		${LOCALBASE}/bin/go-bindata -o upup/models/bindata.go -pkg models \
		-prefix upup/models/ upup/models/...

.include <bsd.port.mk>
