# New ports collection makefile for:	py-asv
# Date created:		4 April 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	asv
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://tratt.net/~laurie/python/asv/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johann@egenetics.com

PYTHON_VERSION=	python2.0

ASV_BASEDIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages
ASV_DOCDIR=	${PREFIX}/share/doc/py-asv
ASV_EGDIR=	${PREFIX}/share/examples/py-asv

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@printf '#!/bin/sh\n${PYTHON_CMD} ${ASV_BASEDIR}/ASV.py "$$@"\n' \
		> ${WRKDIR}/asv.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/asv.sh ${PREFIX}/bin/asv
	@${INSTALL_DATA} ${WRKSRC}/ASV.* ${ASV_BASEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${ASV_DOCDIR}
.for docfile in INSTALL README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${ASV_DOCDIR}
.endfor
	@${MKDIR} ${ASV_EGDIR}
.for egfile in asv_example.* example_data.csv
	@${INSTALL_DATA} ${WRKSRC}/${egfile} ${ASV_EGDIR}
.endfor
.endif

.include <bsd.port.mk>
