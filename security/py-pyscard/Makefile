PORTNAME=	pyscard
PORTVERSION=	2.3.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mp39590@gmail.com
COMMENT=	Smartcard module for Python
WWW=		http://pyscard.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:devel/swig \
		pcsc-lite>0:devel/pcsc-lite
RUN_DEPENDS=	pcsc-lite>0:devel/pcsc-lite

## Python3 is supported
USES=		python
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=	--include-dirs=${LOCALBASE}/include/PCSC

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/smartcard/scard/_scard*.so

.include <bsd.port.mk>
