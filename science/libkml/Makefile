PORTNAME=	libkml
PORTVERSION=	1.3.0
PORTREVISION=	26
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reference implementation of OGC KML 2.2
WWW=		https://github.com/libkml/libkml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		liburiparser.so:net/uriparser

USES=		cmake compiler:c++11-lang minizip pathfix

CMAKE_OFF=	BUILD_TESTING WITH_JAVA WITH_PYTHON WITH_SWIG
CMAKE_ON=	BUILD_SHARED_LIBS
LDFLAGS+=	-lz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	916a801

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES INSTALL_EXAMPLES
EXAMPLES_CMAKE_ON=	-DKML_EXAMPLES_DIR=${EXAMPLESDIR}
EXAMPLES_LIB_DEPENDS=	libcurl.so:ftp/curl

.include <bsd.port.mk>
