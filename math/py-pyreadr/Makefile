# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pyreadr
PORTVERSION=	0.4.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read/write R RData and Rds files into/from pandas data frames

LICENSE=	AGPLv3+

LIB_DEPENDS=	librdata.so:math/librdata
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.24.0:math/py-pandas@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent cython distutils

post-patch:
# Clean up bundled libraries
	@${RM} -fr ${WRKSRC}/pyreadr/libs/
	@${RM} -fr ${WRKSRC}/win_libs/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyreadr/librdata${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
