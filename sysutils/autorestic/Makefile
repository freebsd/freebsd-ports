PORTNAME=	autorestic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.9
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Config driven, easy backup cli for restic
WWW=		https://github.com/cupcakearmy/${PORTNAME}

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	restic:sysutils/restic

USES=		go:modules
GO_MODULE=	github.com/cupcakearmy/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
