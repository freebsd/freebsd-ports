# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	pycdf
PORTVERSION=	0.6.3
PORTREVISION=	5
CATEGORIES=	science python
MASTER_SITES=	SF/pysclint/${PORTNAME}/${PORTNAME}-${PORTVERSION}b
DISTNAME=	${PORTNAME}-0.6-3b

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Interface to the Unidata NetCDF Library

LIB_DEPENDS=	libnetcdf.so:science/netcdf
BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS}

LDFLAGS+=	"-L${LOCALBASE}/lib"

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pycdf/_pycdfext.so

.include <bsd.port.mk>
