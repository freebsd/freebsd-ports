PORTNAME=	coincurve
DISTVERSION=	20.0.0
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/bitcoin-core/secp256k1/archive/:bitcoin_core
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		1ad5185cd42c0636104129fcc9f6a4bf9c67cc40.tar.gz:bitcoin_core
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform Python CFFI bindings for libsecp256k1
WWW=		https://github.com/ofek/coincurve

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.24.2:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		aclocal:devel/automake \
		autoreconf:devel/autoconf \
		cmake:devel/cmake-core \
		libtool:devel/libtool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.3.0:devel/py-cffi@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	pep517 autoplist pytest # tests fail due to missing imports, but sources were changed after 19.0.1

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|https://github.com/bitcoin-core/secp256k1/archive/|file://${DISTDIR}/|' \
		${WRKSRC}/pyproject.toml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/coincurve/_libsecp256k1*.so

.include <bsd.port.mk>
