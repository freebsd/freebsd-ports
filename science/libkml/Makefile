# Created by: Wen Heping <wen@FreeBSD.org>

PORTNAME=	libkml
PORTVERSION=	1.3.0
PORTREVISION=	21
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reference implementation of OGC KML 2.2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>=1.44.0:devel/boost-libs \
		googletest>=1.7.0:devel/googletest
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libgtest.so:devel/googletest \
		liburiparser.so:net/uriparser

OPTIONS_DEFINE=	EXAMPLES

USES=		cmake compiler:c11 minizip pathfix

CMAKE_OFF=	WITH_JAVA WITH_PYTHON WITH_SWIG
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes

USE_GITHUB=	yes

EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES INSTALL_EXAMPLES
EXAMPLES_CMAKE_ON=	-DKML_EXAMPLES_DIR=${EXAMPLESDIR}
EXAMPLES_LIB_DEPENDS=	libcurl.so:ftp/curl

.include <bsd.port.mk>
