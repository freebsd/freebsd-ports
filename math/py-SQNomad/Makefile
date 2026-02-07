PORTNAME=	SQNomad
DISTVERSION=	0.2.3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Blackbox optimization software
WWW=		https://www.gerad.ca/nomad/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}SQCommon>0:misc/py-SQCommon@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/libsqnomad${PYTHON_TAG}.so

# there are a lot of errors during build stemming from the numpy code, for example:
# cc: error: unknown argument: '-mavx5124fmaps'
# cc: error: unknown argument: '-mavx5124vnniw'
# but these erros are in the test coe nd they don't break the build

.include <bsd.port.mk>
