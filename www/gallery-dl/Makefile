# $FreeBSD$

PORTNAME=	gallery-dl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.1
CATEGORIES=	www

# Implicit approval to commit trivial version updates.
MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Command-line program to download image galleries and collections

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.0:www/py-requests@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.4+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
GH_ACCOUNT=	mikf

post-patch:
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/gallery_dl/config.py \
		${WRKSRC}/scripts/man.py

post-build:
# USE_GITHUB archive doesn't have generated files
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC} PYTHON="${PYTHON_CMD}" man completion

do-test:
	@${PYTHON_CMD} -m unittest discover -vs ${TEST_WRKSRC}

.include <bsd.port.mk>
