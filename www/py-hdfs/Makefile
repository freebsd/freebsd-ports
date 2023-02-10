PORTNAME=	hdfs
DISTVERSION=	2.7.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	HdfsCLI: API and command line interface for HDFS
WWW=		https://hdfscli.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist # tests require nose which is unmaintained and abandoned, see https://github.com/mtth/hdfs/issues/190

NO_ARCH=	yes

.include <bsd.port.mk>
