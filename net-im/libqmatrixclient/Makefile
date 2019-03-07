# $FreeBSD$

PORTNAME=	libqmatrixclient
DISTVERSION=	0.5.0
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies

LICENSE=	LGPL21
LICENSE_FILES=	${WRKSRC}/COPYING

USES=	cmake compiler:c++14-lang qt:5 tar:xz
USE_QT=	core gui multimedia network \
	buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	QMatrixClient

.include <bsd.port.mk>
