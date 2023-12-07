PORTNAME=		go-yq
DISTVERSIONPREFIX=	v
DISTVERSION=		4.35.2
PORTREVISION=	1
CATEGORIES=		textproc

MAINTAINER=	timp87@gmail.com
COMMENT=	Portable commandline YAML processor written in go
WWW=		https://github.com/mikefarah/yq

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	github.com/mikefarah/yq/v4
GO_TARGET=	.:yq

CONFLICTS_INSTALL=	yq

PLIST_FILES=		bin/yq

.include <bsd.port.mk>
