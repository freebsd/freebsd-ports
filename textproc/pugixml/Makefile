# $FreeBSD$

PORTNAME=	pugixml
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/zeux/pugixml/releases/download/v${PORTVERSION}/

MAINTAINER=	ybungalobill@gmail.com
COMMENT=	Light-weight, simple and fast XML parser for C++ with XPath support

LICENSE=	MIT

USES=		cmake compiler:c++11-lang

CXXFLAGS+=	-std=c++11
WRKSRC=		${WRKDIR}/${PORTNAME}-1.8
CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON -DBUILD_STATIC_LIBS=ON -DBUILD_TESTS=OFF -DBUILD_PKGCONFIG=ON

.include <bsd.port.mk>
