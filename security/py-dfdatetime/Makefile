PORTNAME=	dfdatetime
PORTVERSION=	20230506
CATEGORIES=	security devel python
MASTER_SITES=	PYPI \
		https://github.com/log2timeline/dfdatetime/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Date and Time
WWW=		https://github.com/log2timeline/dfdatetime

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist concurrent
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} "s,share/doc/dfdatetime,${DOCSDIR_REL}," ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/pip/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
