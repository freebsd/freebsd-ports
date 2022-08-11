PORTNAME=	normality
DISTVERSION=	2.3.3
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Micro-library to normalize text strings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}banal>=1.0.1:devel/py-banal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>0:textproc/py-charset-normalizer@${PY_FLAVOR}

USES=		python:3.5+ pytest
USE_GITHUB=	yes
GH_ACCOUNT=	pudo
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=		ICU
OPTIONS_DEFAULT=	ICU

ICU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyicu>=1.9.3:devel/py-pyicu@${PY_FLAVOR}

.include <bsd.port.mk>
