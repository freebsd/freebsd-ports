PORTNAME=	trivy
DISTVERSION=	0.49.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Security scanner written in go
WWW=		https://github.com/aquasecurity/trivy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.21

GO_MODULE=	github.com/aquasecurity/trivy
GO_TARGET=	./cmd/trivy
GO_BUILDFLAGS= -ldflags=" \
		-extldflags '-static' \
		-X github.com/aquasecurity/trivy/pkg/version.ver=${DISTVERSION} \
		-s -w"

PLIST_FILES=	bin/${PORTNAME}

	

.include <bsd.port.mk>
