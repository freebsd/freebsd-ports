# New ports collection makefile for:	numpy
# Version required:	1.8
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	LLNLDistribution11
PKGNAME=	py-numeric-1.8
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/${DISTNAME}/Numerical
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
NUMPYDIR=	${PYTHONSCRIPTDIR}/site-packages/numerical
DOCDIR=		${PREFIX}/share/doc/py-numerical
EXAMPLEDIR=	${PREFIX}/share/examples/py-numerical

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python makethis.py)

post-install:
	@${MKDIR} ${NUMPYDIR}
	${INSTALL_DATA} ${WRKSRC}/Lib/* ${NUMPYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${NUMPYDIR}
	@${ECHO} "numerical" > ${NUMPYDIR}/../numerical.pth
	@${MKDIR} ${PREFIX}/include/python1.5/numerical
	${INSTALL_DATA} ${WRKSRC}/Include/*object.h ${PREFIX}/include/python1.5/numerical
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DOCDIR}
.endif

.include <bsd.port.mk>
