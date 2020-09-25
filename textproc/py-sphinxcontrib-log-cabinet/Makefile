# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinxcontrib-log-cabinet
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Organize changelog directives in Sphinx docs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PY_SPHINX}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
