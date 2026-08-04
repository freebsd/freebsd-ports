PORTNAME=	stackit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.68.0
CATEGORIES=	sysutils

MAINTAINER=	gogolok@gmail.com
COMMENT=	Command-line interface to manage STACKIT resources
WWW=		https://github.com/stackitcloud/stackit-cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.26+,modules
GO_MODULE=	github.com/stackitcloud/stackit-cli
GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
