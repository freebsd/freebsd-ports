PORTNAME=	beautifulsoup
PORTVERSION=	4.13.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	beautifulsoup4-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	HTML/XML Parser for Python
WWW=		https://www.crummy.com/software/BeautifulSoup/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soupsieve>=1.2:www/py-soupsieve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	concurrent pep517 pytest
NO_ARCH=	yes

PLIST_SUB=	BS_VER=${PORTVERSION}

do-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -m build --wheel --no-isolation --outdir ${WRKDIR}

do-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -m installer ${WRKDIR}/*.whl --destdir ${STAGEDIR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest bs4

.include <bsd.port.mk>
