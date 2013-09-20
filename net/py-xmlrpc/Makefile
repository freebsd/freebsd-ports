# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	xmlrpc
PORTVERSION=	0.8.8.3
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	SF/py-${PORTNAME}/source/py-${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast implementation of the xmlrpc spec for Python

LICENSE=	LGPL21 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py-${PORTNAME}

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTEXAMPLES=	*
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/_xmlrpc.so \
		%%PYTHON_SITELIBDIR%%/pyxmlrpclib.py \
		%%PYTHON_SITELIBDIR%%/pyxmlrpclib.pyc \
		%%PYTHON_SITELIBDIR%%/pyxmlrpclib.pyo \
		%%PYTHON_SITELIBDIR%%/xmlrpc.py \
		%%PYTHON_SITELIBDIR%%/xmlrpc.pyc \
		%%PYTHON_SITELIBDIR%%/xmlrpc.pyo

NO_STAGE=	yes
post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
