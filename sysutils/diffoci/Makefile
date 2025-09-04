PORTNAME=	diffoci
PORTVERSION=	0.1.7
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff for Docker and OCI container images
WWW=		https://github.com/reproducible-containers/diffoci

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/reproducible-containers/diffoci
GO_TARGET=	./cmd/diffoci

PLIST_FILES=	bin/diffoci

.include <bsd.port.mk>
