# $FreeBSD$

PORTNAME=	trans
PORTVERSION=	1.5.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	d.pryadko@rambler-co.ru
COMMENT=	Module for performing transliteration

LICENSE=	BSD

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/trans.py \
		%%PYTHON_SITELIBDIR%%/trans.pyc \
		%%PYTHON_SITELIBDIR%%/trans.pyo

USE_BZIP2=	yes
USE_PYTHON=	2
USE_PYDISTUTILS=yes

NO_STAGE=	yes
.include <bsd.port.mk>
