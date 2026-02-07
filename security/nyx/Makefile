PORTNAME=	nyx
PORTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	PYPI

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Command-line monitor for Tor
WWW=		https://nyx.torproject.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stem>=1.7.1:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

PLIST_FILES=	share/man/man1/nyx.1.gz

post-install:
		${INSTALL_MAN} ${WRKSRC}/nyx.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
