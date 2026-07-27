PORTNAME=	faust-cchardet
DISTVERSION=	2.2.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High speed universal character encoding detector
WWW=		https://github.com/faust-streaming/cChardet

LICENSE=	MPL11
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.16.0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>0:devel/py-pkgconfig@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cchardet/_cchardet${PYTHON_TAG}.so

.include <bsd.port.mk>
