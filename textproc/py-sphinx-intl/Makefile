# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinx-intl
PORTVERSION=	0.9.5
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/s/${PORTNAME}/ \
		http://www.pcbsd.org/~kris/software/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Sphinx-intl translation features

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PKGNAMEPREFIX}sphinx>=1.1.3:${PORTSDIR}/textproc/py-sphinx

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
