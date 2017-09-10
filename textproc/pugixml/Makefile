# $FreeBSD$

PORTNAME=	pugixml
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/zeux/pugixml/releases/download/v${PORTVERSION}/

MAINTAINER=	ybungalobill@gmail.com
COMMENT=	Light-weight, simple and fast XML parser for C++ with XPath support

LICENSE=	MIT

USES=		cmake compiler:c++11-lang
CMAKE_SOURCE_PATH=	${WRKSRC}/scripts

CXXFLAGS+=	-std=c++11

.include <bsd.port.mk>
