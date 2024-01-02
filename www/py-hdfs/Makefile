PORTNAME=	hdfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.3
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HdfsCLI: API and command line interface for HDFS
WWW=		https://hdfscli.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fastavro>=0.21.19:textproc/py-fastavro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.14.1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.7.0:security/py-requests-kerberos@${PY_FLAVOR}


USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	mtth

NO_ARCH=	yes

.include <bsd.port.mk>
