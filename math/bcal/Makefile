# $FreeBSD$

PORTNAME=	bcal
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-12
DISTVERSIONSUFFIX=	-g6867abd
CATEGORIES=	math

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Storage expression, unit conversion & address offset CLI calculator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=	gmake python:test,3.5+ readline

USE_GITHUB=	yes
GH_ACCOUNT=	jarun

MAKE_ARGS=	MANDIR=${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/bcal \
		man/man1/bcal.1.gz

PORTDOCS=	CHANGELOG \
		README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bcal

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v test.py

.include <bsd.port.mk>
