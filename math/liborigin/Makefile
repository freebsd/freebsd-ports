# $FreeBSD$

PORTNAME=	liborigin
PORTVERSION=	3.0.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/3.0

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Library and utility for reading OriginLab project files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING # GPLv3

USES=		compiler:c++11-lang cmake:outsource pathfix

CMAKE_ARGS=	-DLIB_SUFFIX=""
USE_LDCONFIG=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=ON

post-patch:
	${REINPLACE_CMD} -e 's,lib$${LIB_SUFFIX}/pkgconfig,libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
