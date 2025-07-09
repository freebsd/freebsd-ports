PORTNAME=	chaoskube
PORTVERSION=	0.35.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Chaoskube periodically kills random pods in your Kubernetes cluster
WWW=		https://github.com/linki/chaoskube

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/linki/chaoskube

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
