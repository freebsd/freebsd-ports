# New ports collection makefile for:	py-textile
# Date created:		2008-09-05
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	textile
PORTVERSION=	2.1.3
CATEGORIES=	www textproc python
MASTER_SITES=	CHEESESHOP \
		${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Textile markup generator written in Python

PROJECTHOST=	pytextile
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/textile.py \
		%%PYTHON_SITELIBDIR%%/textile.pyc \
		%%PYTHON_SITELIBDIR%%/textile.pyo

.include <bsd.port.mk>
