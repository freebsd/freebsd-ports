# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	16.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	py-
DISTNAME=	Numeric-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	lapack.3:${PORTSDIR}/math/lapack \
		blas.2:${PORTSDIR}/math/lapack

USE_PYTHON=	yes
MAKE_ENV=	BLASLIBDIR=${LOCALBASE}/lib LAPACKLIBDIR=${LOCALBASE}/lib \
		PYTHON_CMD=${PYTHON_CMD}

DOCDIR=		${PREFIX}/share/doc/py-numeric
EXAMPLEDIR=	${PREFIX}/share/examples/py-numeric

post-install:
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLEDIR}
	@${MKDIR} ${EXAMPLEDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLEDIR}/NumTut
.if !defined(NOPORTDOCS)
#	@${MKDIR} ${DOCDIR}
#	${INSTALL_DATA} ${WRKSRC}/Doc/numpy.pdf ${DOCDIR}
.endif

.include <bsd.port.mk>
