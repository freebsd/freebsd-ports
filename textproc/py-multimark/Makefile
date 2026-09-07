PORTNAME=	multimark
PORTVERSION=	0.3.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to cmark: CommonMark parsing and rendering
WWW=		https://github.com/posit-dev/multimark

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.15:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.15:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR}

USES=		compiler:c11 python
USE_PYTHON=	autoplist pep517 pytest

TEST_ARGS=	--disable-plugin-autoload

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

# tests as of 0.3.2: 6643 passed, 43 xfailed in 2.24s

.include <bsd.port.mk>
