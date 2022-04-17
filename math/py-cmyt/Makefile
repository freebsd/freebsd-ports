PORTNAME=	cmyt
PORTVERSION=	1.0.4
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of Matplotlib colormaps from the yt project

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8.4:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorspacious>=1.1.2:devel/py-colorspacious@${PY_FLAVOR}
py37_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0.2:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

POST_PLIST=	rm-tests-from-plist

post-install:
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/tests

rm-tests-from-plist:
	@${REINPLACE_CMD} '/\/tests\//d' ${TMPPLIST}

.include <bsd.port.mk>
