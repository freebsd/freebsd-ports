PORTNAME=	paginate
DISTVERSION=	0.5.7
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Divides large result sets into pages for easier browsing
WWW=		https://github.com/Pylons/paginate

LICENSE=	MIT

USES=		python
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
