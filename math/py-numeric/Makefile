# New ports collection makefile for:	numpy
# Version required:	1.1
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/01/21 13:07:44 tg Exp $
#

DISTNAME=	NumPy-11
PKGNAME=	numpy-1.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/python/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

WRKSRC=		${WRKDIR}/LLNLDistribution/Numerical
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
NUMPYDIR=	${PREFIX}/lib/python1.5/site-packages
DOCDIR=		${PREFIX}/share/doc/NumPy

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python makethis.py)

post-install:
	${INSTALL_DATA} ${WRKSRC}/Lib/* ${NUMPYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${NUMPYDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DOCDIR}
.endif

.include <bsd.port.mk>
