PORTNAME=	pyrad
DISTVERSION=	2.4
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	steve@energistic.com
COMMENT=	Python implementation of RADIUS client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0.10.0b1:devel/py-nose@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	pyradius
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	pyrad_project

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|zip_safe=True|zip_safe=False|' \
		${WRKSRC}/setup.py

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TESTENV} ${PYTHON_CMD} -m nose -v

.include <bsd.port.mk>
