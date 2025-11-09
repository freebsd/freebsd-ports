PORTNAME=	gallery-dl
DISTVERSION=	1.30.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	PYPI \
		https://github.com/mikf/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

# Implicit approval to commit trivial version updates.
MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Command-line program to download image galleries and collections
WWW=		https://github.com/mikf/gallery-dl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517 unittest
NO_ARCH=	yes
TEST_ARGS=	discover -s test

post-patch:
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/gallery_dl/config.py \
		${WRKSRC}/data/man/gallery-dl.*

.include <bsd.port.mk>
