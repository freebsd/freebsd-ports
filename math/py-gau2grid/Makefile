# $FreeBSD$

PORTNAME=	gau2grid
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	0deace28eaad3359a595e384daf7bb9dd157c0d6.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast computation of a gaussian and its derivative on a grid

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		cmake:devel/cmake
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c11 python
USE_GITHUB=	yes
GH_ACCOUNT=	dgasmith
USE_PYTHON=	distutils autoplist

PLIST_FILES=	${PYTHON_SITELIBDIR}/gau2grid/libgg.so.1 # https://github.com/dgasmith/gau2grid/issues/33

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
