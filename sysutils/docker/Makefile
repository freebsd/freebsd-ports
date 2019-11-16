# Created by: Nikolai Lifanov <lifanov@FreeBSD.org>
# $FreeBSD$

PORTNAME=		docker
PORTVERSION=		18.09.5
DISTVERSIONPREFIX=	v
PORTREVISION=		1
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
		@${CP} ${FILESDIR}/default_store_freebsd.go \
			${GO_WRKSRC}/cli/cli/config/credentials/

.include <bsd.port.mk>
