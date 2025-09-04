PORTNAME=	autorestic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.3
PORTREVISION=	7
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Config driven, easy backup cli for restic
WWW=		https://github.com/cupcakearmy/${PORTNAME}

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	restic:sysutils/restic

USES=		go:modules
GO_MODULE=	github.com/cupcakearmy/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
