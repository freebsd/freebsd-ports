PORTNAME=	feedparser
PORTVERSION=	6.0.12
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Universal feed parser written in Python
WWW=		https://github.com/kurtmckee/feedparser

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sgmllib3k>=0:devel/py-sgmllib3k@${PY_FLAVOR}

USES=		cpe python tar:bzip2
CPE_VENDOR=	mark_pilgrim
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	kurtmckee

NO_ARCH=	yes

PORTDOCS=	NEWS README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC}; ${PYTHON_CMD} tests/runtests.py)

.include <bsd.port.mk>
