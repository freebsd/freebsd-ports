PORTNAME=	kapp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.59.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Simple deployment tool for Kubernetes
WWW=		https://github.com/carvel-dev/kapp

LICENSE=	APACHE20

USES=		go:modules
GO_MODULE=	github.com/carvel-dev/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/vmware-tanzu/carvel-kapp/pkg/kapp/version.Version=v${PORTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
