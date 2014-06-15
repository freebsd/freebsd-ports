# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinxcontrib-adadomain
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/s/${PORTNAME}/ \
		LOCAL/marino
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Sphinx Adadomain Extension

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
