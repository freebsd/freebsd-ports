PORTNAME=	opentofu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for building, changing, and versioning infrastructure
WWW=		https://opentofu.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/opentofu/opentofu
GO_TARGET=	./cmd/tofu
GO_BUILDFLAGS=	-o bin/

PLIST_FILES=	bin/tofu

.include <bsd.port.mk>
