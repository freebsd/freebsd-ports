PORTNAME=	soap2py
PORTVERSION=	1.16
CATEGORIES=	net www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python simple and lightweight SOAP Library
WWW=		https://github.com/pysimplesoap/pysimplesoap

LICENSE=	LGPL3+

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/PKG-INFO \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/SOURCES.txt \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/dependency_links.txt \
		${PYTHON_SITELIBDIR}/${PYDISTUTILS_EGGINFO}/top_level.txt

.include <bsd.port.mk>
