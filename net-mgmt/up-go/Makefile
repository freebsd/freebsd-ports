PORTNAME=	up-go
DISTVERSIONPREFIX=	v
DISTVERSION=	${MODVERSION:S/-/./g}
CATEGORIES=	net-mgmt

MAINTAINER=	hoanga@gmail.com
COMMENT=	Troubleshoot problems with your Internet connection
WWW=		https://github.com/jesusprubio/up

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=	go:modules
MODVERSION=	1.3.0
GO_MODULE=	github.com/jesusprubio/up@v${MODVERSION}
GO_BUILDFLAGS+=	-ldflags "-s -w"
CGO_ENABLED=	0
GO_PKGNAME=	github.com/jesusprubio/${PORTNAME}
GO_TARGET=	:${BIN_NAME}

CONFLICTS_INSTALL=	up # bin/up

PLIST_FILES=	bin/${BIN_NAME}

BIN_NAME=	up

.include <bsd.port.mk>
