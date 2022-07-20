PORTNAME=	nyx
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	CHEESESHOP

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Command-line monitor for Tor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stem>=1.7.1:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist noflavors

NO_ARCH=	yes

PLIST_FILES=	man/man1/nyx.1.gz

post-install:
		${INSTALL_MAN} ${WRKSRC}/nyx.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
