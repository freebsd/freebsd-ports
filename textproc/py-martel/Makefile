# New ports collection makefile for:	py-martel
# Date created:		19 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	martel
PORTVERSION=	0.5
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	textproc biology python
MASTER_SITES=	http://www.biopython.org/~dalke/Martel/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Martel-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes

MARTEL_DIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/Martel
EXAMPLESDIR=	${PREFIX}/share/examples/martel

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ ${MKDIR} ${MARTEL_DIR}
	@ (cd ${WRKSRC} && find *.py *.pyc *.pyo formats test \
	  | cpio --quiet -pdum -R ${BINOWN}:${BINGRP} ${MARTEL_DIR})

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in README HISTORY doc/*
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}/builders
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/builders/* ${EXAMPLESDIR}/builders
.endif

.include <bsd.port.mk>
