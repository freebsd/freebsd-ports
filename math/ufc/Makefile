# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	ufc
PORTVERSION=	${MMVERSION}.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${MMVERSION}.x/${PORTVERSION}/+download/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Unified framework for finite element assembly

BUILD_DEPENDS=	swig2.0:devel/swig20
LIB_DEPENDS=	libboost_math_c99.so:devel/boost-libs

# LICENSE=	public domain

USES=		cmake python:2

CMAKE_ARGS+=	-DUFC_PKGCONFIG_DIR=${PREFIX}/libdata/pkgconfig

MMVERSION=	2.2

post-patch:
	${REINPLACE_CMD} -i '' -e 's|os.path.join(os.path.sep, "usr")|os.path.normpath("${PREFIX}")|' ${WRKSRC}/src/utils/python/ufc_utils/build.py

.include <bsd.port.mk>
