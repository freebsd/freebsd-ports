PORTNAME=	pycosat
PORTVERSION=	0.6.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Bindings to PicoSAT (a SAT solver)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpicosat.so:math/picosat

USES=		python:3.6+ zip
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILDARGS=	build_ext \
			-I${LOCALBASE}/include -L${LOCALBASE}/lib \
			-DDONT_INCLUDE_PICOSAT \
			-lpicosat

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pycosat*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
