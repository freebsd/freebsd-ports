# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soap2py
PORTVERSION=	1.16
CATEGORIES=	net www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python simple and lightweight SOAP Library

LICENSE=	LGPL3+

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

X_PLIST_FILES=	%%PYTHON_SITELIBDIR%%/soap2py-1.16-py%%PYTHON_VER%%.egg-info/PKG-INFO \
		%%PYTHON_SITELIBDIR%%/soap2py-1.16-py%%PYTHON_VER%%.egg-info/SOURCES.txt \
		%%PYTHON_SITELIBDIR%%/soap2py-1.16-py%%PYTHON_VER%%.egg-info/dependency_links.txt \
		%%PYTHON_SITELIBDIR%%/soap2py-1.16-py%%PYTHON_VER%%.egg-info/top_level.txt
PLIST_FILES=	${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/PKG-INFO \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/SOURCES.txt \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/dependency_links.txt \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/top_level.txt

.include <bsd.port.mk>
