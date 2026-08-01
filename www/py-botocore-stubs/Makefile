PORTNAME=	botocore-stubs
DISTVERSION=	1.43.14
CATEGORIES=	www python devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	botocore_stubs-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Type annotations for botocore
WWW=		https://github.com/youtype/mypy_boto3_builder

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}types-awscrt>=0:devel/py-types-awscrt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
