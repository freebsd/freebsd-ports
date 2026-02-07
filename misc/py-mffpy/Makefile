PORTNAME=	mffpy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	3
CATEGORIES=	misc
#MASTER_SITES=	PYPI # no test files
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reader and writer for Philips' MFF file format
WWW=		https://github.com/BEL-Public/mffpy/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>=1.2.12:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.8.0:devel/py-lxml@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2019.2:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # 14 tests fail with AttributeError: module 'numpy' has no attribute 'float', see https://github.com/BEL-Public/mffpy/issues/126

USE_GITHUB=	yes
GH_ACCOUNT=	BEL-Public

NO_ARCH=	yes

.include <bsd.port.mk>
