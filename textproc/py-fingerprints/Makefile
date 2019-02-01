# $FreeBSD$

PORTNAME=	fingerprints
DISTVERSION=	0.5.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Easy comparing and cross-referencing of companies and people

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}normality>=0.4.0:textproc/py-normality@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-extract:
	# Prevents that the tests directory will be installed into site-packages
	@(cd ${WRKSRC} && ${MV} tests test)

.include <bsd.port.mk>
