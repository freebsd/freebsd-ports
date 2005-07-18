# New ports collection makefile for:	py-numarray
# Date created:		30 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	numarray
PORTVERSION=	1.3.3
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Numeric array manipulation extension module for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-configure:
	cd ${WRKSRC} && \
	${PYTHON_CMD} generate.py && \
	${PYTHON_CMD} Include/numarray/genapis.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/Doc -cf- .|${TAR} -C ${DOCSDIR} -xf-
	@${TAR} -C ${WRKSRC}/Examples -cf- .|${TAR} -C ${EXAMPLESDIR} -xf-
	@${RM} -fr ${EXAMPLESDIR}/ufunc/build
.endif

.include <bsd.port.mk>
