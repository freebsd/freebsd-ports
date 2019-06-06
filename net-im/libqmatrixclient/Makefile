# $FreeBSD$

PORTNAME=	libqmatrixclient
DISTVERSION=	0.5.2
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	cmake compiler:c++14-lang qt:5 tar:xz
USE_QT=	core gui multimedia network \
	buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_PROJECT=	libQuotient

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=include/Quotient

.include <bsd.port.mk>
