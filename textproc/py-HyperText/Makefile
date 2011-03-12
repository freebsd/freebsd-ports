# Ports collection Makefile for:	HyperText
# Date created:				10/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	HyperText
PORTVERSION=	1.0.1
CATEGORIES=	textproc python
MASTER_SITES=	http://dustman.net/andy/python/HyperText/1.0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight HTML/XHTML generator for Python

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/HyperText

# get rid of pre-compiled stuff: it may not work for the installed
# version of Python
post-extract:
	@cd ${WRKSRC} && ${RM} -f *.py[co]

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/HyperText
	${CHOWN} ${BINOWN}:${BINGRP} ${PYTHON_SITELIBDIR}/HyperText
	${CHMOD} ${BINMODE} ${PYTHON_SITELIBDIR}/HyperText
	@(set -e -x; cd ${WRKSRC}; for f in *.py *.py[co]; do       \
	    ${INSTALL_DATA} $$f ${PYTHON_SITELIBDIR}/HyperText/$$f; \
	    done)

.include <bsd.port.mk>
