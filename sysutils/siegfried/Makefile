# Created by: Steffen Fritz <steffen@fritz.wtf>
# $FreeBSD$

PORTNAME=	siegfried
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.13
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	File identification tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	richardlehane

GO_TARGET=	./cmd/sf
GO_TEST_TARGET=	./cmd/sf

PLIST_FILES=	bin/sf

.include <bsd.port.mk>
