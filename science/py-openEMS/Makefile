PORTNAME=	openEMS
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.36
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electromagnetic field solver using the EC-FDTD method
WWW=		https://www.openems.de/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	${NONEXISTENT}:cad/py-csxcad:patch \
		${PYTHON_PKGNAMEPREFIX}csxcad>0:cad/py-csxcad@${PY_FLAVOR}
LIB_DEPENDS=	libCSXCAD.so:cad/csxcad \
		libopenEMS.so:science/openems
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}csxcad>0:cad/py-csxcad@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	distutils cython autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig

CFLAGS+=	-I${WRKSRC} \
		-I`${MAKE} -C ${PORTSDIR}/cad/py-csxcad -VWRKSRC`

WRKSRC_SUBDIR=	python

post-patch:
	@${CP} ${WRKSRC}/../nf2ff/*.h ${WRKSRC}/openEMS
	@${CP} ${WRKSRC}/../*.h ${WRKSRC}/openEMS

post-install:
.for name in _nf2ff openEMS
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/openEMS/${name}${PYTHON_EXT_SUFFIX}.so
.endfor

.include <bsd.port.mk>
