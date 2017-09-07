# Created by: gahr
# $FreeBSD$

PORTNAME=	xerces-c
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	APACHE/xerces/c/3/sources
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

CMAKE_ARGS=	-Dnetwork=ON \
		-Dthreads=ON \
		-Dtranscoder=iconv
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		cmake cpe iconv pathfix

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R}

CPE_PRODUCT=	xerces-c++
CPE_VENDOR=	apache

post-patch:
	@${REINPLACE_CMD} -e '/list(APPEND netaccessors curl)/d' ${WRKSRC}/cmake/XercesNetAccessorSelection.cmake

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/add_subdirectory(doc)/d' ${WRKSRC}/CMakeLists.txt

post-install:
	${LN} -s libxerces-c-${PORTVERSION:R}.so ${STAGEDIR}${PREFIX}/lib/libxerces-c.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
