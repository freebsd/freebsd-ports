# $FreeBSD$

PORTNAME=	otter
PORTVERSION=	0.9.05
CATEGORIES=	www
# Avoid pkgname conflict with misc/otter
PKGNAMESUFFIX=	-browser
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Browser based on Qt 5

USE_QT5=	concurrent core gui multimedia network printsupport \
		script sql webkit widgets \
		buildtools_build qmake_build
USES=		cmake:outsource desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	OtterBrowser
GH_PROJECT=	otter-browser
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	c1819f1

.include <bsd.port.mk>
