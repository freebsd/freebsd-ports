# Created by: Steffen Fritz <steffen@fritz.wtf>
# $FreeBSD$

PORTNAME=	siegfried
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.8
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	steffen@fritz.wtf
COMMENT=	File identification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	richardlehane

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}/cmd/sf

PLIST_FILES=	bin/sf

.include <bsd.port.mk>
