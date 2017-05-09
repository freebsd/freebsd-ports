# Created by: Nikolai Lifanov <lifanov@FreeBSD.org>
# $FreeBSD$

PORTNAME=		docker
PORTVERSION=		17.05.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-ce
CATEGORIES=		sysutils

MAINTAINER=		lifanov@FreeBSD.org
COMMENT=		Open-source application container engine

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

PLIST_FILES=		bin/docker

USE_GITHUB=		yes
GH_ACCOUNT=		moby
GH_PROJECT=		moby

USES=	go

GO_PKGNAME=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	github.com/${PORTNAME}/${PORTNAME}/cmd/docker

.include <bsd.port.mk>
