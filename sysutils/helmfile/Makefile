PORTNAME=	helmfile
DISTVERSIONPREFIX=	v
DISTVERSION=	0.167.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Helmfile is a declarative spec for deploying helm charts
WWW=		https://github.com/helmfile/helmfile

LICENSE=	MIT

RUN_DEPENDS=	helm:sysutils/helm

USES=		go:1.22,modules
GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X go.szostok.io/version.version=v${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
