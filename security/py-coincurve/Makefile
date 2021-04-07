PORTNAME=	coincurve
DISTVERSION=	15.0.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform Python CFFI bindings for libsecp256k1

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		aclocal:devel/automake \
		autoreconf:devel/autoconf \
		gmake:devel/gmake \
		libtool:devel/libtool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}

USES=		pkgconfig python:3.6+
USE_PYTHON=	distutils autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/coincurve/_libsecp256k1*.so

.include <bsd.port.mk>
