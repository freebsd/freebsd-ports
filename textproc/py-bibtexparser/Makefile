PORTNAME=	bibtexparser
DISTVERSION=	1.4.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bibtex parser
WWW=		https://github.com/sciunto-org/python-bibtexparser

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.3:devel/py-pyparsing@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
