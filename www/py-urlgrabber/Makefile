PORTNAME=	urlgrabber
PORTVERSION=	4.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	High-level cross-protocol url-grabber
WWW=		http://urlgrabber.baseurl.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.48.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycurl>=7.19.0_1:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	scripts/urlgrabber-ext-down

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_MAKE_ENV=	INSTALL_DOCS=yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%DOCSDIR%%,${DOCSDIR},' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
