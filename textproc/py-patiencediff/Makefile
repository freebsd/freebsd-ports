# $FreeBSD$

PORTNAME=	patiencediff
PORTVERSION=	0.2.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Implementation of the "Patience Diff" algorithm

LICENSE=	GPLv2+

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/patiencediff/_patiencediff_c.so

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v build/

.include <bsd.port.mk>
