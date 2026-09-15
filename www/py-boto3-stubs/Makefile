PORTNAME=	boto3-stubs
DISTVERSION=	1.43.94
CATEGORIES=	www python devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Type annotations for boto3
WWW=		https://github.com/youtype/mypy_boto3_builder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore-stubs>=0:www/py-botocore-stubs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-s3transfer>=0:devel/py-types-s3transfer@${PY_FLAVOR}
py311_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
