# $FreeBSD$

PORTNAME=	Quaternion
DISTVERSION=	0.0.9.4
DISTVERSIONSUFFIX=	-beta1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILES=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	QMatrixClient

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5
BUILD_DEPENDS=	${LOCALBASE}/lib/libQMatrixClient.a:net-im/libqmatrixclient

USES=	cmake compiler:c++17-lang localbase:ldflags qt:5 tar:xz
USE_QT=	core declarative gui network widgets \
	buildtools_build linguist_build qmake_build

.include <bsd.port.mk>
