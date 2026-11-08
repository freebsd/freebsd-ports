PORTNAME=	pyphen
DISTVERSION=	0.18.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Module to hyphenate text based on Hunspell dictionaries
WWW=		https://pyphen.org/

LICENSE=	GPLv2 LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING.MPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.18.1: 15 passed in 1.73s

.include <bsd.port.mk>
