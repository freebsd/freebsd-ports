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
COMMENT=	Fast implementation of the xmlrpc spec for Python

LICENSE=	LGPL21 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
