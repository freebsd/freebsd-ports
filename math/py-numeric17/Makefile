# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	15.3
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	py-
DISTNAME=	Numerical-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/python1.5/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
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
