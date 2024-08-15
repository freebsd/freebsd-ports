PORTNAME=	popeye
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.3
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Kubernetes cluster resource sanitizer
WWW=		https://popeye.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

_BUILD_DATE=	$$(date -u +"%FT%T%z")
_BUILD_HASH=	f736e64

GO_MODULE=	github.com/derailed/popeye
GO_BUILDFLAGS=	-ldflags "\
		-w \
		-X ${GO_MODULE}/cmd.version=${DISTVERSION} \
		-X ${GO_MODULE}/cmd.commit=${_BUILD_HASH} \
		-X ${GO_MODULE}/cmd.date=${_BUILD_DATE}" \
		-a -tags netgo

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
