PORTNAME=	chaoskube
PORTVERSION=	0.29.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	nulldutra@proton.me
COMMENT=	Chaoskube periodically kills random pods in your Kubernetes cluster
WWW=		https://github.com/linki/chaoskube

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/linki/chaoskube

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
