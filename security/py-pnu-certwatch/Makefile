PORTNAME=	pnu-certwatch
DISTVERSION=	1.0.3
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hubert.tournier@gmail.com
COMMENT=	Watch X509 certificates expiration dates
WWW=		https://github.com/HubTou/certwatch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pnu-libpnu>=1.3.0:devel/py-pnu-libpnu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist flavors pep517 cryptography

SHEBANG_FILES=	src/certwatch/*.py

.include <bsd.port.mk>
