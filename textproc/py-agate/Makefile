PORTNAME=	agate
PORTVERSION=	1.9.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Data analysis library optimized for humans
WWW=		https://agate.rtfd.org/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytimeparse>=1.1.5:devel/py-pytimeparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=2.1:devel/py-parsedatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.5.4:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-slugify>=1.2.1:textproc/py-python-slugify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}leather>=0.3.2:graphics/py-leather@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>=2.4.2:devel/py-pyicu@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
