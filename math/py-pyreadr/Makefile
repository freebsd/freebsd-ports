PORTNAME=	pyreadr
PORTVERSION=	0.4.6
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read/write R RData and Rds files into/from pandas data frames

LICENSE=	AGPLv3+

LIB_DEPENDS=	librdata.so:math/librdata
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=1.2.0,1:math/py-pandas@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent cython distutils

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/pyreadr/libs/
	@${RM} -r ${WRKSRC}/win_libs/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
