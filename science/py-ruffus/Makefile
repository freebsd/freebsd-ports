PORTNAME=	ruffus
DISTVERSION=	2.8.4
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Lightweight library for computational pipelines
WWW=		http://www.ruffus.org.uk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_FILES=	${WRKSRC}/ruffus/test/*.py

NO_ARCH=	yes

.include <bsd.port.mk>
