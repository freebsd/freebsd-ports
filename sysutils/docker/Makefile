# Created by: Nikolai Lifanov <lifanov@FreeBSD.org>
# $FreeBSD$

PORTNAME=		docker
PORTVERSION=		17.03.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-ce
CATEGORIES=		sysutils

MAINTAINER=		lifanov@FreeBSD.org
COMMENT=		Open-source application container engine

LICENSE=		APACHE20

PLIST_FILES=		bin/docker

USE_GITHUB=		yes

USES=	go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/docker

STRIP=		# stripping can break go binaries

.include <bsd.port.mk>
