# $FreeBSD$

PORTNAME=	otter
PORTVERSION=	0.9.05
DISTVERSIONPREFIX=	v
CATEGORIES=	www
# Avoid pkgname conflict with misc/otter
PKGNAMESUFFIX=	-browser

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

USE_QT5=	concurrent core gui multimedia network printsupport \
		script sql webkit widgets \
		buildtools_build qmake_build
USES=		cmake:outsource desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser
GH_PROJECT=	otter-browser

.include <bsd.port.mk>
