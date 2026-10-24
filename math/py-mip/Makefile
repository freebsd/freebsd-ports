PORTNAME=	mip
DISTVERSION=	2.0.0
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python MIP (Mixed-Integer Linear Programming) Tools
WWW=		https://python-mip.com/ \
		https://github.com/coin-or/python-mip

LICENSE=	EPL

BROKEN=		broken in the run-time: looks for a function Osi_getNumCols that is inline in both libCbc.so and libOsi.so, see https://github.com/coin-or/python-mip/issues/426

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

POST_PLIST=	fix-plist

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/mip/cbc.py

fix-plist: # remove platform-specific libraries
	@${REINPLACE_CMD} ' \
		/\/mip\/libraries/d ; \
		' ${TMPPLIST}

post-install:
	# remove platform-specific libraries
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/mip/libraries
	# update the PREFIX
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${PYTHON_SITELIBDIR}/mip/cbc.py

.include <bsd.port.mk>
