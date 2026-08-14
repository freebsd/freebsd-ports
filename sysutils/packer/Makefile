PORTNAME=	packer
DISTVERSION=	1.16.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	brad@facefault.org
COMMENT=	Tool for creating machine images
WWW=		https://www.packer.io/

LICENSE=	BSL11
LICENSE_NAME=	Business Source License 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror pkg-sell auto-accept

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
GO_MODULE=	github.com/hashicorp/packer

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
