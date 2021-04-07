PORTNAME=	pdfminer.six
PORTVERSION=	20201018
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	PDF parser and analyzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	pdfminer
USE_PYTHON=	distutils concurrent autoplist

CONFLICTS_INSTALL=	py??-pdfminer-* py??-pdfminer3k-*
NO_ARCH=		yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v --nologcapture)

.include <bsd.port.mk>
