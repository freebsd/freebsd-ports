PORTNAME=	packer
PORTVERSION=	1.10.1
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	sysutils

MAINTAINER=	brad@facefault.org
COMMENT=	Tool for creating machine images
WWW=		https://www.packer.io/

LICENSE_NAME=   Business Source License 1.1
LICENSE_FILE=   ${WRKSRC}/LICENSE
LICENSE_PERMS=  dist-mirror pkg-mirror pkg-sell auto-accept

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
GO_MODULE=	github.com/hashicorp/packer

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
