# New ports collection makefile for:	numpy
# Version required:	1.3
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1998/06/24 06:09:13 tg Exp $
#

DISTNAME=	LLNLPython4
PKGNAME=	numpy-1.3
CATEGORIES=	math python
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/LLNLPython4/Numerical
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
NUMPYDIR=	${PREFIX}/lib/python1.5/site-packages
DOCDIR=		${PREFIX}/share/doc/NumPy
EXAMPLEDIR=	${PREFIX}/share/examples/NumPy

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python makethis.py)

post-install:
	${INSTALL_DATA} ${WRKSRC}/Lib/* ${NUMPYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${NUMPYDIR}
	${INSTALL_DATA} ${WRKSRC}/Include/*object.h ${PREFIX}/include/python1.5
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DOCDIR}
.endif

.include <bsd.port.mk>
