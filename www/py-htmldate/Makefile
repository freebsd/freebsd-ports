PORTNAME=	htmldate
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast and robust extraction of publication dates from URLs and web pages
WWW=		https://htmldate.readthedocs.io/en/latest/ \
		https://github.com/adbar/htmldate

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.4.0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateparser>=1.1.2:devel/py-dateparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=5.3.0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.9.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26,1<3,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
