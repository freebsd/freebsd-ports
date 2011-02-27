# ex:ts=8
# Ports collection makefile for:	py-bcrypt
# Date created:			07 maerch, 2007
# Whom:				Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bcrypt
PORTVERSION=	0.2
CATEGORIES=	security python
MASTER_SITES=	http://www.mindrot.org/files/py-bcrypt/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Python bcrypt module

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py_${PORTNAME}
PYEASYINSTALL_ARCHDEP=	yes
PYEASYINSTALL_EGG=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	"LDFLAGS=-L${LOCALBASE}/lib"

.include <bsd.port.mk>
