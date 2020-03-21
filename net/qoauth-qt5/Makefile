# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qoauth
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	net devel security
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 support for OAuth-powered network services

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang qmake:outsource qca qt:5
USE_LDCONFIG=	yes
USE_QT=		core network testlib buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	ayoy

.include <bsd.port.mk>
