# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	soap2py
PORTVERSION=	1.16
CATEGORIES=	net www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python simple and lightweight SOAP Library

LICENSE=	LGPL3+

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/PKG-INFO \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/SOURCES.txt \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/dependency_links.txt \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/top_level.txt

.include <bsd.port.mk>
