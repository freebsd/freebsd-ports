# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plumbum
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Shell combinators and more for python

LICENSE=	MIT

TEST_DEPENDS=	nosetests-${PYTHON_VER}:${PORTSDIR}/devel/py-nose

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils concurrent
GH_ACCOUNT=	tomerfiliba

do-test:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} nosetests-${PYTHON_VER} --processes=${MAKE_JOBS_NUMBER})
.include <bsd.port.mk>
