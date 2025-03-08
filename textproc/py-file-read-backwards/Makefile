PORTNAME=	file-read-backwards
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Memory efficient way of reading files line-by-line from the end of file
WWW=		https://github.com/RobinNil/file_read_backwards

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest2

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
