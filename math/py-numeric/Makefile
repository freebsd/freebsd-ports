# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	16.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	py-
DISTNAME=	Numeric-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYDISTUTILS}
LIB_DEPENDS=	lapack.3:${PORTSDIR}/math/lapack \
		blas.2:${PORTSDIR}/math/lapack
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

MAKE_ENV=	BLASLIBDIR=${LOCALBASE}/lib LAPACKLIBDIR=${LOCALBASE}/lib
PLIST_SUB=	PYVERSION="python${PYVERSION}"

DOCDIR=		${PREFIX}/share/doc/py-numeric
EXAMPLEDIR=	${PREFIX}/share/examples/py-numeric
PYVERSION!=	(python -c 'import string, sys; \
			   print string.split(sys.version)[0][:3]') 2> /dev/null \
			|| echo "1.5"

.if ${PYVERSION} == "2.0"
PYDISTUTILS=	${LOCALBASE}/lib/python${PYVERSION}/distutils/core.py:${PORTSDIR}/lang/python
.else
PYDISTUTILS=	${LOCALBASE}/lib/python${PYVERSION}/site-packages/distutils/core.py:${PORTSDIR}/misc/py-distutils
.endif

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
