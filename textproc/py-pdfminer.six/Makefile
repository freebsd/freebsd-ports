# $FreeBSD$

PORTNAME=	pdfminer.six
PORTVERSION=	20191110
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	PDF parser and analyzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pdfminer
USE_PYTHON=	distutils concurrent autoplist

CONFLICTS_INSTALL=	py??-pdfminer-* py??-pdfminer3k-*
NO_ARCH=		yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR}
.endif

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v --nologcapture)

.include <bsd.port.post.mk>
