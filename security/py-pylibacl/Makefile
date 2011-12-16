# New ports collection makefile for:  py-pylibacl
# Date created:        18 april 2009
# Whom:                joris
#
# $FreeBSD$
#

PORTNAME=	pylibacl
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	SF

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	Manipulate ACL with Python

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
