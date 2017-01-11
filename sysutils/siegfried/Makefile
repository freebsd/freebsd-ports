# Created by: Steffen Fritz <steffen@fritz.wtf>
# $FreeBSD$

PORTNAME=		siegfried
PORTVERSION=		1.6.7
DISTVERSIONPREFIX=	v
CATEGORIES=		sysutils

MAINTAINER=		steffen@fritz.wtf
COMMENT=		File identification tool

LICENSE=		APACHE20

PLIST_FILES=		bin/sf

USE_GITHUB=		yes
GH_ACCOUNT=		richardlehane

USES=	go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/sf

STRIP=		# stripping can break go binaries

.include <bsd.port.mk>
