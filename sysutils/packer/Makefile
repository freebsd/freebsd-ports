# $FreeBSD$

PORTNAME=	packer
PORTVERSION=	1.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Tool for creating machine images

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/${PORTNAME}

USES=	go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

.include <bsd.port.mk>
