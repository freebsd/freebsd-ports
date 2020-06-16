# $FreeBSD$

PORTNAME=	PuLP
DISTVERSION=	2.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LP modeler written in python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${PY_FLAVOR} \
		cbc:math/cbc \
		glpsol:math/glpk

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

post-patch:
	@${CP} ${WRKSRC}/pulp/pulp.cfg.linux ${WRKSRC}/pulp/pulp.cfg.freebsd
	@${REINPLACE_CMD} -E 's/^(CplexPath|PulpCbcPath) = .*/#&/' ${WRKSRC}/pulp/pulp.cfg.freebsd

.include <bsd.port.mk>
