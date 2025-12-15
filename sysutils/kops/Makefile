PORTNAME=	kops
PORTVERSION=	1.34.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Operations
WWW=		https://github.com/kubernetes/kops

LICENSE=	APACHE20

BROKEN_i386=	linking fails: mapping output file failed: cannot allocate memory

BUILD_DEPENDS=	go-bindata:devel/go-bindata

USES=		go:1.25+,modules

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
