# $FreeBSD$

PORTNAME=	cutelyst
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	www

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	C++/Qt web framework

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource localbase
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT5=	qmake_build buildtools_build \
		core network sql
CMAKE_ARGS=	-DBUILD_ALL=OFF \
		-DBUILD_TESTS=OFF \
		-DMANDIR:PATH=man \
		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=TRUE

.include <bsd.port.mk>
