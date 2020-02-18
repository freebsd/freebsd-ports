# $FreeBSD$

PORTNAME=	cutelyst
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	www

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	C++/Qt web framework

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang localbase qt:5
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		qmake_build buildtools_build linguisttools_build \
		core network sql

CMAKE_ARGS=	-DBUILD_ALL=OFF \
		-DPLUGIN_CSRFPROTECTION=ON \
		-DPLUGIN_STATICCOMPRESSED=ON \
		-DBUILD_TESTS=OFF \
		-DMANDIR:PATH=man \
		-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=TRUE

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
