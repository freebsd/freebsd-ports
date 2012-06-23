# New ports collection makefile for:	py-pyctpp2
# Date created:				2012-06-24
# Whom:					Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	pyctpp2
PORTVERSION=	0.12.2
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Python interface to CTPP2 library

LICENSE=	MIT

LIB_DEPENDS=	ctpp2:${PORTSDIR}/textproc/ctpp2

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
