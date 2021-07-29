PORTNAME=	packer
PORTVERSION=	1.7.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	brad@facefault.org
COMMENT=	Tool for creating machine images

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/${PORTNAME}

USES=	go:modules
GO_MODULE= github.com/hashicorp/packer

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

.include <bsd.port.mk>
