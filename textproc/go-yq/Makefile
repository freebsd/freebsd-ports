PORTNAME=		go-yq
DISTVERSIONPREFIX=	v
DISTVERSION=		4.25.1
PORTREVISION=	3
CATEGORIES=		textproc

MAINTAINER=	timp87@gmail.com
COMMENT=	Portable commandline YAML processor written in go

LICENSE=	MIT

USES=		go:modules
GO_MODULE=	github.com/mikefarah/yq/v4
GO_TARGET=	.:yq

CONFLICTS_INSTALL=	yq

PLIST_FILES=		bin/yq

.include <bsd.port.mk>
