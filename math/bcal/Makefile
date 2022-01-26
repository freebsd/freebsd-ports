PORTNAME=	bcal
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4
CATEGORIES=	math

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Storage expression, unit conversion & address offset CLI calculator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

# GNU bc must be used because bcal depends on some behaviors
# specific to GNU bc. Run the test suite with the bc from the
# base to see that some tests fail.
RUN_DEPENDS=	${LOCALBASE}/bin/bc:math/gnubc \
		calc:math/calc
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		gmake python:test,3.5+ readline

USE_GITHUB=	yes
GH_ACCOUNT=	jarun

MAKE_ARGS=	CFLAGS_OPTIMIZATION=

PLIST_FILES=	bin/bcal \
		share/man/man1/bcal.1.gz

PORTDOCS=	CHANGELOG README.md

OPTIONS_DEFINE=	DOCS

_BC_CMD=	${LOCALBASE}/bin/bc

post-patch:
	${REINPLACE_CMD} 's|%%BC_CMD%%|${_BC_CMD}|g' ${WRKSRC}/src/bcal.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bcal

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v test.py

.include <bsd.port.mk>
