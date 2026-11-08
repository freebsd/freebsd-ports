PORTNAME=	APKiD
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Android Application Identifier
WWW=		https://rednaga.io/

LICENSE=	GPLv3 RedNaga
LICENSE_COMB=	dual
LICENSE_NAME_RedNaga=	Commercial
LICENSE_FILE_RedNaga=	${WRKSRC}/LICENSE.COMMERCIAL
LICENSE_PERMS_RedNaga=	pkg-mirror pkg-sell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yara-python-dex>0:security/py-yara-python-dex@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yara-python-dex>0:security/py-yara-python-dex@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}factory-boy>0:devel/py-factory-boy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytest-factoryboy>0:devel/py-pytest-factoryboy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytest-flask>0:devel/py-pytest-flask@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	rednaga

PLIST_SUB=	VER=${PORTVERSION}
NO_ARCH=	yes

TESTING_UNSAFE=	pytest-runner has been removed

post-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} ./prep-release.py)
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/apkid/rules
	${CP} ${WRKSRC}/apkid/rules/rules.yarc	\
		${STAGEDIR}${PYTHON_SITELIBDIR}/apkid/rules/

.include <bsd.port.mk>
