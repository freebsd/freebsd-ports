PORTNAME=	tinyhtml5
DISTVERSION=	2.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tiny HTML5 parser
WWW=		https://doc.courtbouillon.org/tinyhtml5/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12.0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webencodings>=0.5.1:converters/py-webencodings@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
