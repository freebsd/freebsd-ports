# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	17.3.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Numeric-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

DOCDIR=		${PREFIX}/share/doc/py-numeric
EXAMPLEDIR=	${PREFIX}/share/examples/py-numeric

post-extract:
.for dir in FFT LALITE RANLIB RNG
	@(cd ${WRKSRC}/Packages/${dir}; \
		${LN} -sf ../../../Include Include/Numeric)
.endfor

do-build:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup_all.py build)

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup_all.py install)

	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLEDIR}
	@${MKDIR} ${EXAMPLEDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLEDIR}/NumTut
.if !defined(NOPORTDOCS)
#	@${MKDIR} ${DOCDIR}
#	${INSTALL_DATA} ${WRKSRC}/Doc/numpy.pdf ${DOCDIR}
.endif

.include <bsd.port.mk>
