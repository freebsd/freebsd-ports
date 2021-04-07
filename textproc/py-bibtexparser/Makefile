PORTNAME=	bibtexparser
DISTVERSION=	1.2.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bibtex parser

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.3:devel/py-pyparsing@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
