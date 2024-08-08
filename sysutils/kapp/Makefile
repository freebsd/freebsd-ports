PORTNAME=	kapp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.62.1
CATEGORIES=	sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Simple deployment tool for Kubernetes
WWW=		https://github.com/carvel-dev/kapp

LICENSE=	APACHE20

USES=		go:1.22,modules
GO_MODULE=	github.com/carvel-dev/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X carvel.dev/kapp/pkg/kapp/version.Version=v${DISTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
