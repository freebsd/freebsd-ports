# New ports collection makefile for:	py-numarray
# Date created:		30 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	numarray
PORTVERSION=	0.6
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Numeric array manipulation extension module for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
NO_BUILD=	yes # setup.py doesn't work as expected for 'build' target.

DOCDIR=		${PREFIX}/share/doc/py-numarray
EXAMPLEDIR=	${PREFIX}/share/examples/py-numarray

post-extract:
	cd ${WRKSRC} && \
	${PYTHON_CMD} Lib/codegenerator.py && \
	${PYTHON_CMD} Include/numarray/genapis.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR} ${EXAMPLEDIR}
	@${TAR} -C ${WRKSRC}/Doc -cf- .|${TAR} -C ${DOCDIR} -xf-
	@${TAR} -C ${WRKSRC}/Examples -cf- .|${TAR} -C ${EXAMPLEDIR} -xf-
.endif

.include <bsd.port.mk>
