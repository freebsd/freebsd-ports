PORTNAME=	toot
DISTVERSION=	0.27.0
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Interact with the Mastodon social network from the command line

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.5.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.1.7:devel/py-wcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.0.0:devel/py-urwid@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.5.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.4.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.0.0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	ihabunek
USE_PYTHON=	autoplist distutils

TEST_TARGET=	coverage test

NO_ARCH=	yes

PORTDOCS=	CHANGELOG.md README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

pre-test:
	@${REINPLACE_CMD} -e 's|py.test |py.test-${PYTHON_VER} |' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|pytest |pytest-${PYTHON_VER} |' ${WRKSRC}/Makefile

.include <bsd.port.mk>
