PORTNAME=	coincurve
DISTVERSION=	19.0.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform Python CFFI bindings for libsecp256k1
WWW=		https://github.com/ofek/coincurve

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.3.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		aclocal:devel/automake \
		autoreconf:devel/autoconf \
		gmake:devel/gmake \
		libtool:devel/libtool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.3.0:devel/py-cffi@${PY_FLAVOR}

USES=		pkgconfig python
USE_PYTHON=	distutils autoplist pytest # tests fail due to missing imports, but sources were changed after 19.0.1

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/coincurve/_libsecp256k1*.so

.include <bsd.port.mk>
