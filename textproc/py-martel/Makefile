# New ports collection makefile for:	py-martel
# Date created:		19 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	martel
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	textproc biology python
MASTER_SITES=	http://www.biopython.org/~dalke/Martel/
PKGNAMEPREFIX=	py-
DISTNAME=	Martel-${PORTVERSION}

MAINTAINER=	johann@egenetics.com

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/TextTools/__init__.py:${PORTSDIR}/textproc/py-mxTextTools

WRKSRC=		${WRKDIR}/${DISTNAME}/Martel
USE_PYTHON=	yes
NO_BUILD=	yes

MARTEL_DIR=	${PYTHON_SITELIBDIR}/Martel
MARTEL_EXAMPLEDIR=${PREFIX}/share/examples/martel
MARTEL_DOCDIR=	${PREFIX}/share/doc/martel

do-install:
	@ ${MKDIR} ${MARTEL_DIR}
	@ (cd ${WRKSRC} && find *.py examples formats test \
	  | cpio --quiet -pdum -R ${BINOWN}:${BINGRP} ${MARTEL_DIR})
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MARTEL_DIR}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${MARTEL_DIR}
	@ ${MKDIR} ${MARTEL_EXAMPLEDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${MARTEL_EXAMPLEDIR}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${MARTEL_DOCDIR}
.for docfile in README HISTORY doc/*
	@ ${INSTALL_MAN} ${WRKSRC}/${docfile} ${MARTEL_DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
