PORTNAME=	readtime
DISTVERSION=	3.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Calculates the time some text takes the average human to read
WWW=		https://github.com/alanhamlett/readtime

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown2>=2.4.3:textproc/py-markdown2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyquery>=1.2:devel/py-pyquery@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
