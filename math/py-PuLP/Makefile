PORTNAME=	PuLP
DISTVERSION=	2.6.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LP modeler written in python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amply>=0.1.2:math/py-amply@${PY_FLAVOR} \
		cbc:math/cbc \
		glpsol:math/glpk

USES=		cpe python:3.6+
CPE_VENDOR=	${PORTNAME:tl}project
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

post-patch:
	@${CP} ${WRKSRC}/pulp/pulp.cfg.linux ${WRKSRC}/pulp/pulp.cfg.freebsd
	@${REINPLACE_CMD} -E 's/^(CplexPath|PulpCbcPath) = .*/#&/' ${WRKSRC}/pulp/pulp.cfg.freebsd

do-test: install # one test is known to fail: https://github.com/coin-or/pulp/issues/494
	@cd ${TEST_WRKSRC} && py.test

.include <bsd.port.mk>
