# New ports collection makefile for:	py-numarray
# Date created:		30 April 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	numarray
PORTVERSION=	0.3.4
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCDIR=		${PREFIX}/share/doc/py-numarray
EXAMPLEDIR=	${PREFIX}/share/examples/py-numarray

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR} ${EXAMPLEDIR}
	@${TAR} -C ${WRKSRC}/Doc -cf- .|${TAR} -C ${DOCDIR} -xf-
	@${TAR} -C ${WRKSRC}/Examples -cf- .|${TAR} -C ${EXAMPLEDIR} -xf-
.endif

.include <bsd.port.mk>
