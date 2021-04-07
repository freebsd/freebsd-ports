PORTNAME=	python-nss
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for NSS and NSPR

LICENSE=	LGPL21+ GPLv2+ MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE.lgpl
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.gpl
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE.mpl

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libnss3.so:security/nss

USES=		compiler:c11 python:3.6+ tar:bzip2
USE_PYTHON=	autoplist distutils

PYDISTUTILS_CONFIGUREARGS=	--include-root="${LOCALBASE}/include"
PYDISTUTILS_BUILDARGS=		${PYDISTUTILS_CONFIGUREARGS}
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} ${PYDISTUTILS_CONFIGUREARGS}

TEST_TARGET=	# empty
TEST_WRKSRC=	${WRKSRC}/test
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} run_tests -t

post-patch:
	@(cd ${WRKSRC}/test && ${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g' setup_certs.py test_pkcs12.py)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/nss/*.so

.include <bsd.port.mk>
