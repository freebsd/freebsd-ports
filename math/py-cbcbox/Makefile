PORTNAME=	cbcbox
DISTVERSION=	2.937 # not tagged on GH
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python access to the CBC MILP solver
WWW=		https://github.com/h-g-s/cbcbox

LICENSE=	EPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	cbc:math/cbc

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	h-g-s
GH_TAGNAME=	e96fe7e0e2ea1b428dfea087ee54ccd543fe851b # adequate commit for 2.937 release

NO_ARCH=	yes

TEST_ENV=	PYTHONPATH=${WRKSRC}/build/lib
TEST_ARGS=	--disable-plugin-autoload

post-patch:
	@${REINPLACE_CMD} -e 's|@LOCALBASE@|${LOCALBASE}|g' ${WRKSRC}/src/__init__.py

# tests as of 2.937: 33 passed, 1 skipped in 170.11s (0:02:50)

.include <bsd.port.mk>
