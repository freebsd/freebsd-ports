PORTNAME=	fingerprints
DISTVERSION=	1.1.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Easy comparing and cross-referencing of companies and people
WWW=		https://github.com/alephdata/fingerprints

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}normality>=2.0.0<3.0.0:textproc/py-normality@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	alephdata
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
