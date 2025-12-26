PORTNAME=	kapp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.65.0
CATEGORIES=	sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Simple deployment tool for Kubernetes
WWW=		https://github.com/carvel-dev/kapp

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	carvel-dev

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X carvel.dev/kapp/pkg/kapp/version.Version=v${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
