# New ports collection makefile for:	numpy
# Version required:	15.2
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Numerical-15.2
PKGNAME=	py-numeric-15.2
CATEGORIES=	math python
MASTER_SITES=	http://downloads.sourceforge.net/

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/python1.5/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

DOCDIR=		${PREFIX}/share/doc/py-numeric
EXAMPLEDIR=	${PREFIX}/share/examples/py-numeric

do-build:
	@(cd ${WRKSRC}; python setup.py build)

do-install:
	@(cd ${WRKSRC}; python setup.py install)
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLEDIR}
	@${MKDIR} ${EXAMPLEDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLEDIR}/NumTut
.if !defined(NOPORTDOCS)
#	@${MKDIR} ${DOCDIR}
#	${INSTALL_DATA} ${WRKSRC}/Doc/numpy.pdf ${DOCDIR}
.endif

.include <bsd.port.mk>
