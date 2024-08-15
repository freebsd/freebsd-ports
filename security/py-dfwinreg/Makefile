PORTNAME=	dfwinreg
PORTVERSION=	20221218
PORTREVISION=	1
CATEGORIES=	security devel python
MASTER_SITES=	https://github.com/log2timeline/dfwinreg/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Digital Forensics Windows Registry
WWW=		https://github.com/log2timeline/dfwinreg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	libcreg>=e:devel/libcreg \
		libregf>=a:devel/libregf \
		${PYTHON_PKGNAMEPREFIX}dtfabric>=0:devel/py-dtfabric@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dfdatetime>=0:security/py-dfdatetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} "s,share/doc/dfwinreg,${DOCSDIR_REL}," ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/pip/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
