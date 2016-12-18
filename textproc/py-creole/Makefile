# Created by: Stanislav Svirid <count@211.ru>
# $FreeBSD$

PORTNAME=	creole
PORTVERSION=	1.3.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	count@211.ru
COMMENT=	Markup converter in pure Python

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/docutils/__init__.py:textproc/py-docutils

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data ${DATADIR}

.include <bsd.port.post.mk>
