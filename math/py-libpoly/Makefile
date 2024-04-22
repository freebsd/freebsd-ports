PORTNAME=	libpoly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.13
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/SRI-CSL/libpoly/commit/
PATCHFILES=	48f48f945111ab021bed4ad4f192f2cac0c2e84b.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for libpoly
WWW=		https://github.com/SRI-CSL/libpoly

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libpoly.so:math/libpoly

USES=		cmake localbase:ldflags python
USE_GITHUB=	yes
GH_ACCOUNT=	SRI-CSL
USE_LDCONFIG=	yes
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${WRKSRC}/include
LDFLAGS+=	-lpoly

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python
TEST_WRKSRC=	${WRKSRC}/test/python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/polypy*.so

do-test:
	@cd ${WRKSRC}/test/python && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./check.py

.include <bsd.port.mk>
