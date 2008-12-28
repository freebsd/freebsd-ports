# New ports collection makefile for:	py-textile
# Date created:		2008-09-05
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	textile
PORTVERSION=	2.0.11
CATEGORIES=	www textproc python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yzlin@cs.nctu.edu.tw
COMMENT=	Textile markup generator written in Python

PROJECTHOST=	pytextile
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
