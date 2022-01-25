# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	parse-type
PORTVERSION=	0.6.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	parse_type-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplify to build parse types based on the parse module

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parse>=1.18.0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11:devel/py-six@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
