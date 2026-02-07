PORTNAME=	cfv
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	security
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	terry-freebsd@glaver.org
COMMENT=	Utility to both test and create .sfv, .csv, and md5sum files
WWW=		https://github.com/cfv-project/cfv

LICENSE=	GPLv2+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	cfv-project

USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|man/man1|share/man/man1|' ${WRKSRC}/setup.py

do-test:
	cd ${WRKSRC}/test && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test.py

.include <bsd.port.mk>
