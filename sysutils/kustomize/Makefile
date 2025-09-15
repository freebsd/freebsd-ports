PORTNAME=	kustomize
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7.1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Kustomize simplifies resource management with customizable overlays
WWW=		https://github.com/kubernetes-sigs/kustomize

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

_BUILD_DATE=	$$(date -u +"%FT%T%z")

GO_MODULE=	sigs.k8s.io/kustomize/kustomize/v5

GO_BUILDFLAGS=	-ldflags="\
		-X sigs.k8s.io/kustomize/api/provenance.version=${DISTVERSIONPREFIX}${PORTVERSION} \
		-X sigs.k8s.io/kustomize/api/provenance.buildDate=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
