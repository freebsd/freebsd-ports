# $FreeBSD$

PORTNAME=	cryptominisat
PORTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Bindings to CryptoMiniSat (a SAT solver)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

USES=		compiler:c++11-lib python:-2.7
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	msoos

WRKSRC_SUBDIR=	python

PYDISTUTILS_BUILDTARGET=	build_ext --include-dirs=${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|@PROJECT_VERSION@|${PORTVERSION}|' ${WRKSRC}/setup.py.in
	${CP} ${WRKSRC}/setup.py.in ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pycryptosat.so

.include <bsd.port.mk>
