# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	Paste
PORTVERSION=	2.0.3
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tools for using a Web Server Gateway Interface stack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
