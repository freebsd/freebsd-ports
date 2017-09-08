# Created by: Nikolai Lifanov <lifanov@FreeBSD.org>
# $FreeBSD$

PORTNAME=		docker
PORTVERSION=		17.06.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-ce
CATEGORIES=		sysutils

MAINTAINER=		lifanov@FreeBSD.org
COMMENT=		Open-source application container engine

LICENSE=		APACHE20

PLIST_FILES=		bin/docker

USE_GITHUB=		yes
GH_PROJECT=		docker-ce

USES=	go

GO_PKGNAME=	github.com/${PORTNAME}
GO_TARGET=	${GO_PKGNAME}/cli/cmd/docker

pre-build:
		@${MV} ${GO_WRKSRC}/components/* ${GO_WRKSRC}/

.include <bsd.port.mk>
