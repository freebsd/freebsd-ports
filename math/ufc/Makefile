# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	ufc
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/2.0.x/${PORTVERSION}/+download/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Unified framework for finite element assembly

BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	boost_math_c99:${PORTSDIR}/devel/boost-libs

# LICENSE=	public domain

USE_CMAKE=	yes
USE_PYTHON=	-2.7
PYDISTUTILS_PKGNAME=	ufc

FETCH_ARGS=	-F

post-patch:
	${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -i '' -e 's|"usr")|"usr", "local")|g' \
		${WRKSRC}/src/utils/python/ufc_utils/build.py

.include <bsd.port.mk>
