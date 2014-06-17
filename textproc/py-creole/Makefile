# Created by: Stanislav Svirid <count@211.ru>
# $FreeBSD$

PORTNAME=	creole
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	count@211.ru
COMMENT=	Markup converter in pure Python

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data ${DATADIR}

.include <bsd.port.post.mk>
