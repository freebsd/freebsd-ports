PORTNAME=	go-yq
DISTVERSIONPREFIX=	v
DISTVERSION=	4.45.4
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	timp87@gmail.com
COMMENT=	Portable commandline YAML processor written in go
WWW=		https://github.com/mikefarah/yq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GO_MODULE=	github.com/mikefarah/yq/v4
GO_TARGET=	.:yq

CONFLICTS_INSTALL=	yq

PLIST_FILES=	bin/yq

.include <bsd.port.mk>
