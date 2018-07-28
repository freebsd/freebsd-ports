# $FreeBSD$

PORTNAME=	license-expression
DISTVERSIONPREFIX=	v
DISTVERSION=	0.98
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Parses, normalizes and compares license expressions

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/NOTICE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boolean.py>=3.5:devel/py-boolean.py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	nexB

NO_ARCH=	yes

.include <bsd.port.mk>
