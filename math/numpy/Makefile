# New ports collection makefile for:	numpy
# Version required:	1.0b3
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/01/21 11:44:57 asami Exp $
#

DISTNAME=	NumPy
PKGNAME=	numpy-1.0b3
CATEGORIES=	math
MASTER_SITES=	http://www.sls.lcs.mit.edu/~jjh/numpy/
DISTFILES=	NumPy-1.0b3.tar.gz NumPyLib-1.0b2.tar.gz

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	lapack\\.2\\.:${PORTSDIR}/math/lapack \
		ranlib\\.1\\.:${PORTSDIR}/math/libranlib

CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	sharedmods
MAKE_FLAGS+=	'OPT=${CFLAGS}'

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
NUMPYDIR=	${PYTHONSCRIPTDIR}/${DISTNAME}
DOCDIR=		${PREFIX}/share/doc/${DISTNAME}

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in Makefile)

do-install:
	@${MKDIR} ${NUMPYDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.so ${NUMPYDIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}/*.py ${NUMPYDIR}
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${NUMPYDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${NUMPYDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DOCDIR}
.endif

.include <bsd.port.mk>
