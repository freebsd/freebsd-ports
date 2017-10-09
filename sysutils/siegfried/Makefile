# Created by: Steffen Fritz <steffen@fritz.wtf>
# $FreeBSD$

PORTNAME=		siegfried
PORTVERSION=		1.7.6
DISTVERSIONPREFIX=	v
CATEGORIES=		sysutils

MAINTAINER=		steffen@fritz.wtf
COMMENT=		File identification tool

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE.txt

PLIST_FILES=		bin/sf

USE_GITHUB=		yes
GH_ACCOUNT=		richardlehane

USES=	go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/sf

STRIP=		# stripping can break go binaries

.include <bsd.port.mk>
