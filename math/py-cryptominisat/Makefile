PORTNAME=	cryptominisat
DISTVERSION=	5.11.4
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Bindings to CryptoMiniSat (a SAT solver)
WWW=		https://github.com/msoos/cryptominisat

LICENSE=	MIT LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

USES=		compiler:c++11-lib python:3.6+
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	msoos

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pycryptosat*.so

.include <bsd.port.mk>
