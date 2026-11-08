PORTNAME=	python-xmp-toolkit
DISTVERSION=	2.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_xmp_toolkit-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	XMP Toolkit for working with metadata
WWW=		https://github.com/python-xmp-toolkit/python-xmp-toolkit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}
LIB_DEPENDS=	libexempi.so:textproc/exempi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
