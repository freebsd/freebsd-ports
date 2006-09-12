# New ports collection makefile for:	numpy
# Date created:				24 July 2006
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	numpy
PORTVERSION=	1.0b3
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		${MASTER_SITE_SOURCEFORGE:S/$/:source/}
MASTER_SITE_SUBDIR=	numpy/:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	numpy-${PORTVERSION}${EXTRACT_SUFX}:source \
		numpy.pdf:doc
EXTRACT_ONLY=	numpy-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	tonymaher@optusnet.com.au
COMMENT=	The New Numeric Extension to Python

LIB_DEPENDS=	lapack.3:${PORTSDIR}/math/lapack \
		blas.1:${PORTSDIR}/math/blas

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

pre-fetch:
.if ${PYTHON_REL} < 200
	@${ECHO} "Py-numpy doesn't work with Python versions < 2.0."
	@${ECHO} "Please use the py-numeric17 port for these."
	@${FALSE}
.endif

post-extract:
	@${CP} ${DISTDIR}/numpy.pdf ${WRKDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpy.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
